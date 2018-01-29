#include<iostream>  
#include<opencv.hpp>
#include<glad/glad.h>
#include<glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include"Shader.h"
#include"Window.h"
//#include"VertexData.h"
#include"Camera.h"
#include"TrackingObj.h"
using namespace std;
using namespace cv;
////�����������ɫ�ľ��ζ�������(������
//float sceneVertices[] = {
//	// positions          // texture coords
//	1.0f,  1.0f, -0.0f,    1.0f, 0.0f,// top right
//	1.0f, -1.0f,-0.0f,   1.0f, 1.0f, // bottom right
//	-1.0f, -1.0f, -0.0f,    0.0f, 1.0f ,// bottom left
//	-1.0f,  1.0f, -0.0f,   0.0f, 0.0f, // top left 
//};
////����
//float width = 0.2f;
//float
//x_cube = 0.0f
//, y_cube = 0.0f
//, z_cube = 0.0f;
//float boxVertices[] = {
//	-width, -width, -width,  0.0f, 0.0f,
//	width, -width, -width,  1.0f, 0.0f,
//	width,  width, -width,  1.0f, 1.0f,
//	width,  width, -width,  1.0f, 1.0f,
//	-width,  width, -width,  0.0f, 1.0f,
//	-width, -width, -width,  0.0f, 0.0f,
//
//	-width, -width,  width,  0.0f, 0.0f,
//	width, -width,  width,  1.0f, 0.0f,
//	width,  width,  width,  1.0f, 1.0f,
//	width,  width,  width,  1.0f, 1.0f,
//	-width,  width,  width,  0.0f, 1.0f,
//	-width, -width,  width,  0.0f, 0.0f,
//
//	-width,  width,  width,  1.0f, 0.0f,
//	-width,  width, -width,  1.0f, 1.0f,
//	-width, -width, -width,  0.0f, 1.0f,
//	-width, -width, -width,  0.0f, 1.0f,
//	-width, -width,  width,  0.0f, 0.0f,
//	-width,  width,  width,  1.0f, 0.0f,
//
//	width,  width,  width,  1.0f, 0.0f,
//	width,  width, -width,  1.0f, 1.0f,
//	width, -width, -width,  0.0f, 1.0f,
//	width, -width, -width,  0.0f, 1.0f,
//	width, -width,  width,  0.0f, 0.0f,
//	width,  width,  width,  1.0f, 0.0f,
//
//	-width, -width, -width,  0.0f, 1.0f,
//	width, -width, -width,  1.0f, 1.0f,
//	width, -width,  width,  1.0f, 0.0f,
//	width, -width,  width,  1.0f, 0.0f,
//	-width, -width,  width,  0.0f, 0.0f,
//	-width, -width, -width,  0.0f, 1.0f,
//
//	-width,  width, -width,  0.0f, 1.0f,
//	width,  width, -width,  1.0f, 1.0f,
//	width,  width,  width,  1.0f, 0.0f,
//	width,  width,  width,  1.0f, 0.0f,
//	-width,  width,  width,  0.0f, 0.0f,
//	-width,  width, -width,  0.0f, 1.0f
//};
////��������˳��
//unsigned int indices[] = {
//	0, 1, 3, // first triangle
//	1, 2, 3  // second triangle
//};
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow *window);
//Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
////��ʼ���ڴ�С
//const int windowWidth = 512;
//const int windowHeight = 512;
//static float alpha = 0.0f;
#include"AR_Controller.h"
int main()
{
	AR_Controller ar;
	ar.StartAR();
//	TrackingObj tracker;
//	//���ڴ�������ʼ��С
//
//	Window myWindow("OpenGL_Learn", windowWidth, windowHeight);
//	GLFWwindow* window = myWindow.GetWindow();
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);//ע�ᴰ�ڴ�С�仯ʱ������Ӧ�Ļص�����
//																	  //������opengl��Ⱦ����
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		return -1;
//	}
//	glEnable(GL_DEPTH_TEST);
//
//	//������ɫ��
//	Shader sceneShader;
//	sceneShader.Init("vertexShaderSorce.txt", "fragmentShaderSource.txt");
//	//cube��ɫ��
//	Shader cubeShader;
//	cubeShader.Init("boxVertexShader.txt", "boxFragmentShader.txt");
//	
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
////���㻺�����(Vertex Buffer Objects, VBO)��������ڴ棬������GPU�ڴ棨ͨ������Ϊ�Դ棩�д���������㡣
//    //��ʼ��������VAO,VBO��EBO
//	unsigned int scene_VBO, scene_VAO, scene_EBO;
//
//	glGenVertexArrays(1, &scene_VAO);
//	glGenBuffers(1, &scene_VBO);
//	glGenBuffers(1, &scene_EBO);
//
//	glBindVertexArray(scene_VAO);
//	glBindBuffer(GL_ARRAY_BUFFER, scene_VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(sceneVertices), sceneVertices, GL_STATIC_DRAW);
//
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, scene_EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//	// position attribute
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//	// texture coord attribute
//	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//	//����
//	unsigned int cubeVAO, cubeVBO;
//	glGenVertexArrays(1, &cubeVAO);
//	glGenBuffers(1, &cubeVBO);
//	glBindVertexArray(cubeVAO);
//	glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(boxVertices), &boxVertices, GL_STATIC_DRAW);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(1);
//	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//
////�������
//	//��������
//	unsigned int textureScene, textureCube1, textureCube2;
//	glGenTextures(1, &textureCube1);
//	glBindTexture(GL_TEXTURE_2D, textureCube1);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	Mat cubeImg = imread("image/container.jpg");
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, cubeImg.cols, cubeImg.rows, 0, GL_BGR, GL_UNSIGNED_BYTE, cubeImg.data);
//	glGenerateMipmap(GL_TEXTURE_2D);
//
//
//	glGenTextures(1, &textureCube2);
//	glBindTexture(GL_TEXTURE_2D, textureCube2);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	cubeImg = imread("image/awesomeface.png");
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, cubeImg.cols, cubeImg.rows, 0, GL_BGR, GL_UNSIGNED_BYTE, cubeImg.data);
//	glGenerateMipmap(GL_TEXTURE_2D);
//	cubeShader.use();
//	cubeShader.setInt("texture1", 0);
//	cubeShader.setInt("texture2", 1);
//	VideoCapture Cam(0);
//	Mat sceneImg;
//	Cam >> sceneImg;
//	cout << sceneImg.rows << " " << sceneImg.cols << endl;
//	while (!glfwWindowShouldClose(window))//��Ⱦѭ����ʼ
//	{
//
//		// �������
//		processInput(window);
//
//		// ��Ⱦָ��		
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f); //����glClearColor������glClear�����Ļ֮�����ɫ
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);       //�����Ļ
//
//		Cam >> sceneImg;
//		tracker.Tracking(sceneImg);
//		cv::Mat homg = tracker.GetHomography();
//
////cube��ɫ���׶�
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, textureCube1);
//		glActiveTexture(GL_TEXTURE1);
//		glBindTexture(GL_TEXTURE_2D, textureCube2);
//
//		cubeShader.use();
//		glm::mat4 model;
//		glm::mat4 view;
//		glm::mat4 projection;
//		//λ�ú�״̬�任
//		model = glm::scale(model, glm::vec3(0.5, 0.5, 0.5));
//		model = glm::translate(model, glm::vec3(x_cube, y_cube, z_cube));
//		model = glm::rotate(model, glm::radians(-90.0f), glm::vec3(1.0f, 1.0f, 0.0f));
//
//
//		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -2.0f));
//		projection = glm::perspective(glm::radians(45.0f), (float)windowWidth / (float)windowHeight, 0.1f, 100.0f);
//		// retrieve the matrix uniform locations
//		unsigned int modelLoc = glGetUniformLocation(cubeShader.ID, "model");
//		unsigned int viewLoc = glGetUniformLocation(cubeShader.ID, "view");
//		// pass them to the shaders (3 different ways)
//		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);
//		// note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
//		cubeShader.setMat4("projection", projection);
//
//		// render box
//		glBindVertexArray(cubeVAO);
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//		glBindVertexArray(0);
//
//		glDepthFunc(GL_LEQUAL);
////������ɫ���׶�
//		glGenTextures(1, &textureScene);
//		glBindTexture(GL_TEXTURE_2D, textureScene);
//		// set the texture wrapping parameters
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//		// set texture filtering parameters
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, sceneImg.cols, sceneImg.rows, 0, GL_BGR, GL_UNSIGNED_BYTE, sceneImg.data);
//		glGenerateMipmap(GL_TEXTURE_2D);
//		
//		sceneShader.setInt("texture1", 0);
//		sceneShader.use();
//		glm::mat4 Scenemodel;
//		glm::mat4 Sceneview;
//		glm::mat4 Sceneprojection;
//		//Scenemodel = glm::rotate(Scenemodel, glm::radians(0.0f), glm::vec3(1.0f, 0.0f, 0.0f));
//		Sceneview = glm::translate(Sceneview, glm::vec3(0.0f, 0.0f, -2.0f));
//		// retrieve the matrix uniform locations
//		modelLoc = glGetUniformLocation(sceneShader.ID, "model");
//		viewLoc = glGetUniformLocation(sceneShader.ID, "view");
//		// pass them to the shaders (3 different ways)
//		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(Scenemodel));
//		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &Sceneview[0][0]);
//		// note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
//		sceneShader.setMat4("projection", projection);
//   //scene����
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, textureScene);
//		glBindVertexArray(scene_VAO);
//		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//	//����
//
//		//glfwWindowShouldClose����������ÿ��ѭ���Ŀ�ʼǰ���һ��GLFW�Ƿ�Ҫ���˳�
//		//����ǵĻ��ú�������trueȻ����Ⱦѭ��������ˣ�֮��Ϊ���ǾͿ��Թر�Ӧ�ó����ˡ�
//		glfwSwapBuffers(window);
//
//		//glfwPollEvents���������û�д���ʲô�¼�������������롢����ƶ��ȣ���
//		//���´���״̬�������ö�Ӧ�Ļص�����������ͨ���ص������ֶ����ã���
//		glfwPollEvents();
//		//glfwSwapBuffers�����ύ����ɫ���壨����һ��������GLFW����ÿһ��������ɫֵ�Ĵ󻺳壩
//		//������һ�����б��������ƣ����ҽ�����Ϊ�����ʾ����Ļ�ϡ�
//
//
//	}
//	//���VAO��VBO
//	glDeleteVertexArrays(1, &scene_VAO);
//	glDeleteBuffers(1, &scene_VBO);
//	glDeleteBuffers(1, &scene_EBO);
//	glfwTerminate();//ɾ��������Դ
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