#pragma once
#include"ViewModel.h"
#include"TrackingObj.h"
class AR_Controller
{
public:
	AR_Controller();
	~AR_Controller();

	void Reshader();
public:
	TrackingObj tracker;
	ViewModel* viewModel;
	void StartAR();
	
};

