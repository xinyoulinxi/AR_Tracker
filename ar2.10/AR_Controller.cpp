#include "AR_Controller.h"

#include<opencv.hpp>
using namespace cv;
AR_Controller::AR_Controller()
{
	viewModel = ViewModel::GetInstance();
	
}


AR_Controller::~AR_Controller()
{

}
void AR_Controller::Reshader() {

}
void AR_Controller::StartAR()
{
	VideoCapture Cam(0);
	Mat sceneImg;
	viewModel->Init();
	while (!glfwWindowShouldClose(viewModel->m_window)) {
		Cam >> sceneImg;
		tracker.Tracking(sceneImg);
		viewModel->DrawObject();
		viewModel->DrawScene(sceneImg);
	}

}
