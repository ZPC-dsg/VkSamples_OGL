#include <compute_nbody.h>

#include <glm/glm.hpp>

#include <vector>
#include <random>

Compute_nBody::Compute_nBody() {
	globalSettings::mainCamera.type = CameraType::LookAt;

	globalSettings::mainCamera.set_perspective(60.0f, globalSettings::screen_width, globalSettings::screen_height, 512.0f, 0.1f);
	globalSettings::mainCamera.set_rotation(glm::vec3(-26.0f, 75.0f, 0.0f));
	globalSettings::mainCamera.set_position(glm::vec3(0.0f, 0.0f, -14.0f));
	globalSettings::mainCamera.translation_speed = 2.5f;
}

Compute_nBody::~Compute_nBody() {
	terminate();

	glBindVertexArray(0);
	glDeleteVertexArrays(1, &GraphicsResources.VAO);
}

void Compute_nBody::render() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (!firstFrame) {
		compute();
	}
	else {
		firstFrame = false;
	}

	draw();

	updateComputeUBO(globalSettings::deltaTime);
	if (globalSettings::mainCamera.updated) {
		updateGraphicsUBO();
	}
}

void Compute_nBody::prepare() {
	setup_render_states();
	load_assets();
	prepare_storage_buffer();
	prepare_graphics();
	prepare_compute();
}

void Compute_nBody::load_assets() {
	GL_CALL(textures.gradient = TextureFactory::build(TEXTURE_IMAGE, 0, 0, "particle_gradient_rgb.jpg"));
	GL_CALL(textures.particle = TextureFactory::build(TEXTURE_IMAGE, 0, 0, "particle_rgb.jpg"));
}

void Compute_nBody::prepare_graphics() {
	GL_CALL(GraphicsResources.graphics = std::unique_ptr<Buffer>(new Buffer(GL_UNIFORM_BUFFER, GL_STATIC_DRAW, sizeof(GUBO), NULL)));
	GL_CALL(GraphicsResources.graphics->bind(2));
	GL_CALL(updateGraphicsUBO());
	glGenVertexArrays(1, &GraphicsResources.VAO);
	glBindVertexArray(GraphicsResources.VAO);
	GL_CALL(storage->rebind(GL_ARRAY_BUFFER));
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Particle), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Particle), (void*)offsetof(Particle, vel));
	glEnableVertexAttribArray(1);
	storage->unbind();
	glBindVertexArray(0);
	GL_CALL(GraphicsResources.shader = std::unique_ptr<Shader>(new Shader("compute_nbody", "particle.vert", "particle.frag")));
	GL_CALL(setup_graphics_textures());
}

void Compute_nBody::prepare_compute() {
	GL_CALL(ComputeResources.compute = std::unique_ptr<Buffer>(new Buffer(GL_UNIFORM_BUFFER, GL_STATIC_DRAW, sizeof(CUBO), NULL)));
	GL_CALL(ComputeResources.compute->bind(1));
	GL_CALL(updateComputeUBO(1.0f));
	GL_CALL(ComputeResources.calculate = std::unique_ptr<ComputeShader>(new ComputeShader("compute_nbody", "particle_calculate.comp")));
	GL_CALL(ComputeResources.integrate = std::unique_ptr<ComputeShader>(new ComputeShader("compute_nbody", "particle_integrate.comp")));
	GL_CALL(setup_compute_constants());
}

void Compute_nBody::prepare_storage_buffer() {
	std::vector<glm::vec3> attractors = {
		glm::vec3(5.0f, 0.0f, 0.0f),
		glm::vec3(-5.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 0.0f, 5.0f),
		glm::vec3(0.0f, 0.0f, -5.0f),
		glm::vec3(0.0f, 4.0f, 0.0f),
		glm::vec3(0.0f, -8.0f, 0.0f),
	};

	num_particles = static_cast<uint32_t>(attractors.size()) * PARTICLES_PER_ATTRACTOR;

	// Initial particle positions
	std::vector<Particle> particle_buffer(num_particles);

	std::default_random_engine      rnd_engine(static_cast<unsigned>(time(nullptr)));
	std::normal_distribution<float> rnd_distribution(0.0f, 1.0f);

	for (uint32_t i = 0; i < static_cast<uint32_t>(attractors.size()); i++)
	{
		for (uint32_t j = 0; j < PARTICLES_PER_ATTRACTOR; j++)
		{
			Particle& particle = particle_buffer[i * PARTICLES_PER_ATTRACTOR + j];

			// First particle in group as heavy center of gravity
			if (j == 0)
			{
				particle.pos = glm::vec4(attractors[i] * 1.5f, 90000.0f);
				particle.vel = glm::vec4(glm::vec4(0.0f));
			}
			else
			{
				// Position
				glm::vec3 position(attractors[i] + glm::vec3(rnd_distribution(rnd_engine), rnd_distribution(rnd_engine), rnd_distribution(rnd_engine)) * 0.75f);
				float     len = glm::length(glm::normalize(position - attractors[i]));
				position.y *= 2.0f - (len * len);

				// Velocity
				glm::vec3 angular = glm::vec3(0.5f, 1.5f, 0.5f) * (((i % 2) == 0) ? 1.0f : -1.0f);
				glm::vec3 velocity = glm::cross((position - attractors[i]), angular) + glm::vec3(rnd_distribution(rnd_engine), rnd_distribution(rnd_engine), rnd_distribution(rnd_engine) * 0.025f);

				float mass = (rnd_distribution(rnd_engine) * 0.5f + 0.5f) * 75.0f;
				particle.pos = glm::vec4(position, mass);
				particle.vel = glm::vec4(velocity, 0.0f);
			}

			// Color gradient offset
			particle.vel.w = static_cast<float>(i) * 1.0f / static_cast<uint32_t>(attractors.size());
		}
	}

	ComputeUBO.particle_count = num_particles;

	storage = std::unique_ptr<Buffer>(new Buffer(GL_SHADER_STORAGE_BUFFER, GL_DYNAMIC_DRAW, particle_buffer.size() * sizeof(Particle), particle_buffer.data()));
	GL_CALL(storage->bind(0));
}

void Compute_nBody::updateGraphicsUBO() {
	GraphicsUBO.projection = globalSettings::mainCamera.matrices.perspective;
	GraphicsUBO.view = globalSettings::mainCamera.matrices.view;
	GraphicsUBO.screenDim = glm::vec2(static_cast<float>(globalSettings::screen_width), static_cast<float>(globalSettings::screen_height));
	
	GraphicsResources.graphics->update(sizeof(GUBO), &GraphicsUBO);

	globalSettings::mainCamera.updated = false;
}

void Compute_nBody::updateComputeUBO(float delta) {
	ComputeUBO.delta_time = delta;
	ComputeResources.compute->update(sizeof(CUBO), &ComputeUBO);
}

void Compute_nBody::setup_compute_constants() {
	ComputeResources.calculate->use();
	ComputeResources.calculate->setFloat("GRAVITY", 0.002f);
	ComputeResources.calculate->setFloat("POWER", 0.75f);
	ComputeResources.calculate->setFloat("SOFTEN", 0.05f);
	ComputeResources.calculate->unuse();
}

void Compute_nBody::setup_graphics_textures() {
	GraphicsResources.shader->use();
	textures.particle->bind(0);
	textures.gradient->bind(1);
	GraphicsResources.shader->setInt("samplerColorMap", 0);
	GraphicsResources.shader->setInt("samplerGradientRamp", 1);
	GraphicsResources.shader->unuse();
}

void Compute_nBody::setup_render_states() {
	glDisable(GL_DEPTH_TEST);
	glEnable(GL_PROGRAM_POINT_SIZE);
}

void Compute_nBody::draw() {
	GL_CALL(storage->rebind(GL_ARRAY_BUFFER));

	GL_CALL(GraphicsResources.shader->use());
	glBindVertexArray(GraphicsResources.VAO);
	GL_CALL(glDrawArrays(GL_POINTS, 0, num_particles));
}

void Compute_nBody::compute() {
	GL_CALL(storage->rebind(GL_SHADER_STORAGE_BUFFER));

	ComputeResources.calculate->use();
	glDispatchCompute(num_particles / work_group_size, 1, 1);
	glMemoryBarrier(GL_SHADER_STORAGE_BARRIER_BIT);

	ComputeResources.integrate->use();
	glDispatchCompute(num_particles / work_group_size, 1, 1);
	glMemoryBarrier(GL_SHADER_STORAGE_BARRIER_BIT);
}

