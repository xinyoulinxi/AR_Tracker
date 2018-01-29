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
	while (1) {
		Cam >> sceneImg;
		viewModel->DrawScene(sceneImg);
		viewModel->DrawObject();
	}

}
