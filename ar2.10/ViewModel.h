#pragma once
#include<opencv.hpp>
#include<glad/glad.h>
#include<glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include"Shader.h"
#include"Window.h"
#include"Camera.h"

//单例设计的模型加载类

class ViewModel
{
private:
	static ViewModel* Instance;
	//没有对外的构造函数
	ViewModel();
	ViewModel(ViewModel*) {}
	~ViewModel();

	void Init();
	void InitTextures();
	void InitVertexs();
public:
	static ViewModel* GetInstance() {
		if (!Instance) {
			Instance = new ViewModel();
		}
		return Instance;
	}

	static void DeleteInstance() {
		if (Instance) {
			delete Instance;
		}
		Instance = nullptr;
	}
private://成员变量
//模型相关
	GLFWwindow* m_window;
	Shader m_sceneShader; //场景着色器
	Shader m_objShader;   //模型着色器
//图像属性
	cv::Mat	resized_frame;   //调整大小之后的帧图像
	unsigned int scene_VBO, scene_VAO, scene_EBO;
	unsigned int cubeVAO, cubeVBO;

//图像的属性
	//调整的帧图像大小
	int two_power_width;	
	int two_power_height;	

	//窗口大小
	int window_width;
	int window_height;

	//视频图像大小
	int capture_width;
	int capture_height;


public:
	//加载模型
	void DrawObject();

	//加载帧图像作为背景
	void DrawScene(cv::Mat& frame);


	
	
};

