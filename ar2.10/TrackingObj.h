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
	cv::Mat m_homography;  //�任����
	cv::Mat m_trackImg;    //��Ҫץȡ��ͼ��
	cv::Mat m_trackImgGray;//��Ҫץȡ��ͼ��Ҷ�ͼ

	float m_maxDistance;
	float m_minDistance;
	cv::SurfFeatureDetector m_detector;  //
	cv::SurfDescriptorExtractor m_extractor;
	std::vector<cv::DMatch> m_allMatches;
	std::vector<cv::KeyPoint> m_objKeypoints;
	std::vector<cv::KeyPoint> m_sceneKeypoints;

	cv::Mat m_descriptorObj;//����ͼ��������Ӿ���
	cv::Mat m_descriptorScene;//����ͼ��������Ӿ���

	cv::BruteForceMatcher<cv::L2<float>> m_matcher;


	std::vector<cv::DMatch> m_matchesVoted;//ѡ��������ƥ��


	std::vector<cv::Point2f> m_pointsObj, m_pointsScene;//��Ӧ���λ��

	std::vector<cv::Point2f> m_objectPosition;//�Ľ�
	std::vector<cv::Point2f> m_ObgImgconers;

	std::vector<cv::KeyPoint> m_imagePointsObj, m_imagePointsScene;//ѡ���Ķ�Ӧ����������


	
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

