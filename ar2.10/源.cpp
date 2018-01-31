#include<iostream>  
#include<opencv.hpp>
#include<glad/glad.h>
#include<glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include"Shader.h"
#include"Window.h"
#include"Camera.h"
#include"TrackingObj.h"
using namespace std;
using namespace cv;
#include"AR_Controller.h"
int main()
{
	AR_Controller ar;
	ar.StartAR();
	return 0;
}

////�ص������Ʋ�ͬ��С���ڵ���Ⱦ
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	//���ڴ�С�ı䣬���¸�����Ⱦģʽ
//	glViewport(0, 0, width, height);
//}
////�������м���Ƿ���io�豸���������
//void processInput(GLFWwindow *window)
//{
//	//�������
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, true);
//	else if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
//		y_cube += 0.05;
//	}
//	else if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
//		y_cube -= 0.05;
//	}
//	else if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
//		x_cube -= 0.05;
//	}
//	else if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
//		x_cube += 0.05;
//	}
//	cout << x_cube << " " << y_cube << endl;
//}