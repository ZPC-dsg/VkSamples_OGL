#include <init.h>
#include <iostream>

unsigned int globalSettings::screen_width = 800;
unsigned int globalSettings::screen_height = 600;
float globalSettings::deltaTime = 0.0f;
float globalSettings::lastFrame = 0.0f;
Camera globalSettings::mainCamera = Camera();

Initializer::Initializer() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(800, 600, "compute_nbody", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetScrollCallback(window, scroll_callback);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        throw std::runtime_error("Failed to initialize GLAD");
    }
}

Initializer::~Initializer() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

GLFWwindow* Initializer::init() {
    static Initializer initializer = Initializer();
    return initializer.get();
}

GLFWwindow* Initializer::get() {
    return window;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
    globalSettings::screen_width = static_cast<unsigned int>(width);
    globalSettings::screen_height = static_cast<unsigned int>(height);
    globalSettings::mainCamera.update_aspect_ratio(width, height);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    globalSettings::mainCamera.ProcessMouseScroll(static_cast<float>(yoffset));
}

