#include "Window.h"

Window::Window(char* n,size_t w, size_t h) :width(w), height(h),name(n) {
	//不同的初始化窗口方式
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	//创建窗口，并返回窗口指针
	GLFWwindow* window = glfwCreateWindow(width, height, name, NULL, NULL);
	if ((m_window = window) == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		m_window = NULL;
	}
	glfwMakeContextCurrent(window);//设置当前OpenGL上下文
}
