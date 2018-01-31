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

////回调，控制不同大小窗口的渲染
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	//窗口大小改变，重新更改渲染模式
//	glViewport(0, 0, width, height);
//}
////在运行中检测是否有io设备的输入操作
//void processInput(GLFWwindow *window)
//{
//	//按键检测
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