#pragma once

/*
#include <memory>
#include <storageimage.h>
#include <buffer.h>
#include <shader.h>
#include <computeshader.h>
#include <utils.h>

#define PARTICLES_PER_ATTRACTOR 4 * 1024

class Compute_nBody :public Utils {
public:
	Compute_nBody();
	~Compute_nBody();

	virtual void render() override;
	virtual void prepare() override;
	virtual void prepare_ui(const std::string& name) override;

private:
	uint32_t num_particles;
	uint32_t work_group_size = 128;
	uint32_t shared_data_size = 1024;

	std::unique_ptr<Buffer> storage;

	bool firstFrame = true;

	struct
	{
		std::unique_ptr<TextureBase> particle;
		std::unique_ptr<TextureBase> gradient;
	} textures;

	struct GUBO
	{
		glm::mat4 projection;
		glm::mat4 view;
		glm::vec2 screenDim;
	} GraphicsUBO;

	struct CUBO
	{                              
		float   delta_time;      
		int32_t particle_count;
	} ComputeUBO;

	struct Particle
	{
		glm::vec4 pos;        // xyz = position, w = mass
		glm::vec4 vel;        // xyz = velocity, w = gradient texture position
	};

	struct
	{
		std::unique_ptr<Buffer> compute;
		std::unique_ptr<ComputeShader> calculate;
		std::unique_ptr<ComputeShader> integrate;
	} ComputeResources;

	struct
	{
		std::unique_ptr<Buffer> graphics;
		std::unique_ptr<Shader> shader;
		GLuint VAO;
	} GraphicsResources;

	void load_assets();
	void prepare_graphics();
	void prepare_compute();
	void prepare_storage_buffer();

	void updateGraphicsUBO();
	void updateComputeUBO(float delta);
	void setup_compute_constants();
	void setup_graphics_textures();
	void setup_render_states();

	void draw();
	void compute();
};

*/