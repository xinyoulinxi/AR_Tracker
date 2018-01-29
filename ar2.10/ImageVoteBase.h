#pragma once
#include<opencv.hpp>

class ImageVoteBase
{

	cv::Mat m_trackImage;
	
public:

	ImageVoteBase(cv::Mat &trackImg );
	ImageVoteBase();
	virtual ~ImageVoteBase();
	
};

