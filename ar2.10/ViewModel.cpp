#include "ViewModel.h"
using namespace std;
using namespace cv;
#include"NormalFunctions.h"
ViewModel* ViewModel::Instance = nullptr;
float
ViewModel::x_cube = 0.0,
ViewModel::y_cube=0.0,
ViewModel::z_cube=0.0;
//带有纹理和颜色的矩形顶点数据(场景）
float sceneVertices[] = {
	// positions          // texture coords
	1.0f,  1.0f, -0.0f,    1.0f, 0.0f,// top right
	1.0f, -1.0f,-0.0f,   1.0f, 1.0f, // bottom right
	-1.0f, -1.0f, -0.0f,    0.0f, 1.0f ,// bottom left
	-1.0f,  1.0f, -0.0f,   0.0f, 0.0f, // top left 
};
float width = 0.5f;
float boxVertices[] = {
	-width, -width, -width,  0.0f, 0.0f,
	width, -width, -width,  1.0f, 0.0f,
	width,  width, -width,  1.0f, 1.0f,
	width,  width, -width,  1.0f, 1.0f,
	-width,  width, -width,  0.0f, 1.0f,
	-width, -width, -width,  0.0f, 0.0f,

	-width, -width,  width,  0.0f, 0.0f,
	width, -width,  width,  1.0f, 0.0f,
	width,  width,  width,  1.0f, 1.0f,
	width,  width,  width,  1.0f, 1.0f,
	-width,  width,  width,  0.0f, 1.0f,
	-width, -width,  width,  0.0f, 0.0f,

	-width,  width,  width,  1.0f, 0.0f,
	-width,  width, -width,  1.0f, 1.0f,
	-width, -width, -width,  0.0f, 1.0f,
	-width, -width, -width,  0.0f, 1.0f,
	-width, -width,  width,  0.0f, 0.0f,
	-width,  width,  width,  1.0f, 0.0f,

	width,  width,  width,  1.0f, 0.0f,
	width,  width, -width,  1.0f, 1.0f,
	width, -width, -width,  0.0f, 1.0f,
	width, -width, -width,  0.0f, 1.0f,
	width, -width,  width,  0.0f, 0.0f,
	width,  width,  width,  1.0f, 0.0f,

	-width, -width, -width,  0.0f, 1.0f,
	width, -width, -width,  1.0f, 1.0f,
	width, -width,  width,  1.0f, 0.0f,
	width, -width,  width,  1.0f, 0.0f,
	-width, -width,  width,  0.0f, 0.0f,
	-width, -width, -width,  0.0f, 1.0f,

	-width,  width, -width,  0.0f, 1.0f,
	width,  width, -width,  1.0f, 1.0f,
	width,  width,  width,  1.0f, 0.0f,
	width,  width,  width,  1.0f, 0.0f,
	-width,  width,  width,  0.0f, 0.0f,
	-width,  width, -width,  0.0f, 1.0f
};
//顶点连接顺序
unsigned int indices[] = {
	0, 1, 3, // first triangle
	1, 2, 3  // second triangle
};
void ViewModel::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	//窗口大小改变，重新更改渲染模式
	glViewport(0, 0, width, height);

}
void ViewModel::processInput(GLFWwindow *window)
{
	//按键检测
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	else if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
		y_cube += 0.05;
	}
	else if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
		y_cube -= 0.05;
	}
	else if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
		x_cube -= 0.05;
	}
	else if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
		x_cube += 0.05;
	}
	//cout << x_cube << " " << y_cube << endl;
}

const int widthWindow = 512;
const int heightWindow = 512;
ViewModel::ViewModel()
{
	Window window("AR Window", widthWindow, heightWindow);
	m_window = window.GetWindow();

	camera = new Camera(glm::vec3(0.0f, 0.0f, 3.0f));

}


ViewModel::~ViewModel()
{
	//解绑VAO和VBO
	glDeleteVertexArrays(1, &scene_VAO);
	glDeleteBuffers(1, &scene_VBO);
	glDeleteBuffers(1, &scene_EBO);
	glfwTerminate();//删除所有资源
}

void ViewModel::Init()
{

	glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);//注册窗口大小变化时的自适应的回调函数
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return;
	}
	glEnable(GL_DEPTH_TEST);//开启深度测试
	m_sceneShader.Init("vertexShaderSorce.txt", "fragmentShaderSource.txt");
	m_objShader.Init("boxVertexShader.txt", "boxFragmentShader.txt");

	InitVertexs();
	InitTextures();
}

void ViewModel::InitTextures()
{
//纹理加载
	//盒子纹理
	
	glGenTextures(1, &textureCube1);
	glBindTexture(GL_TEXTURE_2D, textureCube1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	Mat cubeImg = imread("image/container.jpg");
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, cubeImg.cols, cubeImg.rows, 0, GL_BGR, GL_UNSIGNED_BYTE, cubeImg.data);
	glGenerateMipmap(GL_TEXTURE_2D);

	glGenTextures(1, &textureCube2);
	glBindTexture(GL_TEXTURE_2D, textureCube2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	cubeImg = imread("image/awesomeface.png");
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, cubeImg.cols, cubeImg.rows, 0, GL_BGR, GL_UNSIGNED_BYTE, cubeImg.data);
	glGenerateMipmap(GL_TEXTURE_2D);
	m_objShader.use();
	m_objShader.setInt("texture1", 0);
	m_objShader.setInt("texture2", 1);

}

void ViewModel::InitVertexs()
{
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);

	glGenVertexArrays(1, &scene_VAO);
	glGenBuffers(1, &scene_VBO);
	glGenBuffers(1, &scene_EBO);

	glBindVertexArray(scene_VAO);
	glBindBuffer(GL_ARRAY_BUFFER, scene_VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(sceneVertices), sceneVertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, scene_EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// texture coord attribute
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	//盒子
	
	glGenVertexArrays(1, &cubeVAO);
	glGenBuffers(1, &cubeVBO);
	glBindVertexArray(cubeVAO);
	glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(boxVertices), &boxVertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));

}

void ViewModel::DrawObject()
{
	// 检测输入
	processInput(m_window);

	// 渲染指令		
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f); //调用glClearColor来设置glClear清空屏幕之后的颜色
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);       //清空屏幕
//cube着色器阶段
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureCube1);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, textureCube2);

	m_objShader.use();
	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 projection;
	//位置和状态变换

	model = glm::scale(model, glm::vec3(0.5, 0.5, 0.5));
	//model = glm::translate(model, glm::vec3(x_cube, y_cube, z_cube));
	model = glm::rotate(model, glm::radians(-90.0f), glm::vec3(1.0f, 1.0f, 0.0f));


	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -2.0f));
	projection = glm::perspective(glm::radians(45.0f), (float)widthWindow / (float)heightWindow, 0.1f, 100.0f);

	unsigned int modelLoc = glGetUniformLocation(m_objShader.ID, "model");
	unsigned int viewLoc = glGetUniformLocation(m_objShader.ID, "view");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);
	m_objShader.setMat4("projection", projection);

	// render box
	glBindVertexArray(cubeVAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glBindVertexArray(0);

	glDepthFunc(GL_LEQUAL);
}

void ViewModel::DrawScene(cv::Mat & frame)
{

	unsigned int modelLoc;
	unsigned int viewLoc;

	glGenTextures(1, &textureScene);
	glBindTexture(GL_TEXTURE_2D, textureScene);
	// set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, frame.cols, frame.rows, 0, GL_BGR, GL_UNSIGNED_BYTE, frame.data);
	glGenerateMipmap(GL_TEXTURE_2D);

	m_sceneShader.setInt("texture1", 0);
	m_sceneShader.use();
	glm::mat4 Scenemodel;
	glm::mat4 Sceneview;
	glm::mat4 projection;
	//Scenemodel = glm::rotate(Scenemodel, glm::radians(0.0f), glm::vec3(0.0f, 0.0f, 0.0f));
	projection = glm::perspective(glm::radians(45.0f), (float)widthWindow / (float)heightWindow, 0.1f, 100.0f);
	Sceneview = glm::translate(Sceneview, glm::vec3(0.0f, 0.0f, -2.0f));
	// retrieve the matrix uniform locations
	modelLoc = glGetUniformLocation(m_sceneShader.ID, "model");
	viewLoc = glGetUniformLocation(m_sceneShader.ID, "view");
	// pass them to the shaders (3 different ways)
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(Scenemodel));
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &Sceneview[0][0]);
	// note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
	m_sceneShader.setMat4("projection", projection);
	//scene纹理
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureScene);
	glBindVertexArray(scene_VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glfwSwapBuffers(m_window);

	//glfwPollEvents函数检查有没有触发什么事件（比如键盘输入、鼠标移动等）、
	//更新窗口状态，并调用对应的回调函数（可以通过回调方法手动设置）。
	glfwPollEvents();

}
