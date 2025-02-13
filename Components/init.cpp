#include <init.h>
#include <iostream>
#include <GL/gl.h>

unsigned int globalSettings::screen_width = 1280;
unsigned int globalSettings::screen_height = 720;
float globalSettings::deltaTime = 0.0f;
float globalSettings::lastFrame = 0.0f;
Camera globalSettings::mainCamera = Camera();
GLFWwindow* globalSettings::mainWindow = nullptr;
GLfloat globalSettings::max_anisotropy = 0.0;

globalSettings::DebugInfo globalSettings::debugInfo{ nullptr,0 };


void init() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);

    globalSettings::mainWindow = glfwCreateWindow(1280, 720, "compute_nbody", NULL, NULL);
    if (globalSettings::mainWindow == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(globalSettings::mainWindow);
    glfwSetFramebufferSizeCallback(globalSettings::mainWindow, framebuffer_size_callback);
    glfwSetScrollCallback(globalSettings::mainWindow, scroll_callback);
    glfwSetCursorPosCallback(globalSettings::mainWindow, mouse_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        throw std::runtime_error("Failed to initialize GLAD");
    }

    GLint flags;
    glGetIntegerv(GL_CONTEXT_FLAGS, &flags);
    if (flags & GL_CONTEXT_FLAG_DEBUG_BIT)
    {
        glEnable(GL_DEBUG_OUTPUT);
        glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
        glDebugMessageCallback(glDebugOutput, &globalSettings::debugInfo);
        glDebugMessageControl(GL_DEBUG_SOURCE_API,
            GL_DEBUG_TYPE_ERROR,
            GL_DEBUG_SEVERITY_HIGH,
            0, nullptr, GL_TRUE);
    }

    glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY, &globalSettings::max_anisotropy);
}

void fin() {
    glfwDestroyWindow(globalSettings::mainWindow);
    glfwTerminate();
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

void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
    //Waiting for further implementation
}

void APIENTRY glDebugOutput(GLenum source,
    GLenum type,
    unsigned int id,
    GLenum severity,
    GLsizei length,
    const char* message,
    const void* userParam)
{
    const globalSettings::DebugInfo* info = static_cast<const globalSettings::DebugInfo*>(userParam);
    // ignore non-significant error/warning codes
    if (id == 131169 || id == 131185 || id == 131218 || id == 131204) return;

    std::cout << "---------------" << std::endl;
    std::cout << "Debug message (" << id << "): " << message << std::endl;

    switch (source)
    {
    case GL_DEBUG_SOURCE_API:             std::cout << "Source: API"; break;
    case GL_DEBUG_SOURCE_WINDOW_SYSTEM:   std::cout << "Source: Window System"; break;
    case GL_DEBUG_SOURCE_SHADER_COMPILER: std::cout << "Source: Shader Compiler"; break;
    case GL_DEBUG_SOURCE_THIRD_PARTY:     std::cout << "Source: Third Party"; break;
    case GL_DEBUG_SOURCE_APPLICATION:     std::cout << "Source: Application"; break;
    case GL_DEBUG_SOURCE_OTHER:           std::cout << "Source: Other"; break;
    } std::cout << std::endl;

    switch (type)
    {
    case GL_DEBUG_TYPE_ERROR:               std::cout << "Type: Error"; break;
    case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: std::cout << "Type: Deprecated Behaviour"; break;
    case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:  std::cout << "Type: Undefined Behaviour"; break;
    case GL_DEBUG_TYPE_PORTABILITY:         std::cout << "Type: Portability"; break;
    case GL_DEBUG_TYPE_PERFORMANCE:         std::cout << "Type: Performance"; break;
    case GL_DEBUG_TYPE_MARKER:              std::cout << "Type: Marker"; break;
    case GL_DEBUG_TYPE_PUSH_GROUP:          std::cout << "Type: Push Group"; break;
    case GL_DEBUG_TYPE_POP_GROUP:           std::cout << "Type: Pop Group"; break;
    case GL_DEBUG_TYPE_OTHER:               std::cout << "Type: Other"; break;
    } std::cout << std::endl;

    switch (severity)
    {
    case GL_DEBUG_SEVERITY_HIGH:         std::cout << "Severity: high"; break;
    case GL_DEBUG_SEVERITY_MEDIUM:       std::cout << "Severity: medium"; break;
    case GL_DEBUG_SEVERITY_LOW:          std::cout << "Severity: low"; break;
    case GL_DEBUG_SEVERITY_NOTIFICATION: std::cout << "Severity: notification"; break;
    } std::cout << std::endl;
    std::cout << std::endl;

    std::cerr << " Message: " << message
        << " (File: " << info->file
        << ", Line: " << info->line << ")" << std::endl;
}


