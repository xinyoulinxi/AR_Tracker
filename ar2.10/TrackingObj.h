#pragma once
#include<features2d\features2d.hpp>
#include<opencv2\flann\flann.hpp>
#include<core\core.hpp>
#include<highgui\highgui.hpp>
#include<opencv.hpp>
#include<vector>

class TrackingObj
{
private:
	cv::Mat m_homography;  //变换矩阵
	cv::Mat m_trackImg;    //需要抓取的图像
	cv::Mat m_trackImgGray;//需要抓取的图像灰度图

	float m_maxDistance;
	float m_minDistance;
	cv::SurfFeatureDetector m_detector;  //
	cv::SurfDescriptorExtractor m_extractor;
	std::vector<cv::DMatch> m_allMatches;
	std::vector<cv::KeyPoint> m_objKeypoints;
	std::vector<cv::KeyPoint> m_sceneKeypoints;

	cv::Mat m_descriptorObj;//特征图像的描述子矩阵
	cv::Mat m_descriptorScene;//场景图像的描述子矩阵

	cv::BruteForceMatcher<cv::L2<float>> m_matcher;


	std::vector<cv::DMatch> m_matchesVoted;//选出的优质匹配


	std::vector<cv::Point2f> m_pointsObj, m_pointsScene;//对应点的位置

	std::vector<cv::Point2f> m_objectPosition;//四角
	std::vector<cv::Point2f> m_ObgImgconers;

	std::vector<cv::KeyPoint> m_imagePointsObj, m_imagePointsScene;//选出的对应优质特征点


	
public:
	void Tracking(cv::Mat &frame);
	cv::Mat GetHomography() {return m_homography;}
	
	cv::Point2f GetObjectPosition() {
		cv::Point2f center;
		center.x = (m_objectPosition[0].x + m_objectPosition[2].x)/2.0;
		center.y = (m_objectPosition[3].y + m_objectPosition[0].y) / 2.0;
		return center;
	}
	TrackingObj();
	~TrackingObj();
};

