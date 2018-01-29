#include "Window.h"

Window::Window(char* n,size_t w, size_t h) :width(w), height(h),name(n) {
	//��ͬ�ĳ�ʼ�����ڷ�ʽ
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	//�������ڣ������ش���ָ��
	GLFWwindow* window = glfwCreateWindow(width, height, name, NULL, NULL);
	if ((m_window = window) == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		m_window = NULL;
	}
	glfwMakeContextCurrent(window);//���õ�ǰOpenGL������
}
