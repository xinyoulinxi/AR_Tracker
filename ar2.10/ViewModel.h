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

//������Ƶ�ģ�ͼ�����

class ViewModel
{
private:
	static ViewModel* Instance;
	//û�ж���Ĺ��캯��
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
private://��Ա����
//ģ�����
	GLFWwindow* m_window;
	Shader m_sceneShader; //������ɫ��
	Shader m_objShader;   //ģ����ɫ��
//ͼ������
	cv::Mat	resized_frame;   //������С֮���֡ͼ��
	unsigned int scene_VBO, scene_VAO, scene_EBO;
	unsigned int cubeVAO, cubeVBO;

//ͼ�������
	//������֡ͼ���С
	int two_power_width;	
	int two_power_height;	

	//���ڴ�С
	int window_width;
	int window_height;

	//��Ƶͼ���С
	int capture_width;
	int capture_height;


public:
	//����ģ��
	void DrawObject();

	//����֡ͼ����Ϊ����
	void DrawScene(cv::Mat& frame);


	
	
};

