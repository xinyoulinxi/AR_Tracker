#include "TrackingObj.h"



using namespace cv;
using namespace std;
void TrackingObj::Tracking(cv::Mat & frame)
{
	//frame������������

	Mat frameGray;
	cvtColor(frame, frameGray, CV_BGR2GRAY);

	m_detector.detect(frameGray, m_sceneKeypoints);
	m_extractor.compute(frameGray, m_sceneKeypoints, m_descriptorScene);
	m_matcher.match(m_descriptorObj, m_descriptorScene, m_allMatches);

	//�õ�ƥ��������Сŷ������
	for (int i = 0; i < m_allMatches.size(); i++) {
		if (m_allMatches[i].distance > m_maxDistance) {
			m_maxDistance = m_allMatches[i].distance;
		}
		if (m_allMatches[i].distance < m_minDistance) {
			m_minDistance = m_allMatches[i].distance;
		}
	}

	int count = 0;
	//ɸѡ������
	for (int i = 0; i < m_allMatches.size(); i++)
	{
		if (m_allMatches[i].distance < m_minDistance*2.5f) {
			DMatch dmatch;
			dmatch.queryIdx = count;
			dmatch.trainIdx = count;
			dmatch.distance = m_allMatches[i].distance;
			m_matchesVoted.push_back(dmatch);
			m_imagePointsObj.push_back(m_objKeypoints[m_allMatches[i].queryIdx]);
			m_imagePointsScene.push_back(m_sceneKeypoints[m_allMatches[i].trainIdx]);
			m_pointsObj.push_back(m_objKeypoints[m_allMatches[i].queryIdx].pt);
			m_pointsScene.push_back(m_sceneKeypoints[m_allMatches[i].trainIdx].pt);
			count++;
		}
	}
	//std::vector<unsigned char> track_status;
	if (m_pointsScene.size() >= 4) {//�Ƿ�߱�����͸�Ӿ���任�Ļ���
		 //͸�ӱ任
		m_homography = findHomography(m_pointsObj, m_pointsScene,CV_RANSAC);
	/*	auto it = track_status.begin();
		int count = 0;
		while (it != track_status.end()) {
			if (*it++ > 0) {
				count++;
			}
		}
		if (count > 6) {*/

			std::vector<Point2f> scene_corners(4);//����λ��
			perspectiveTransform(m_ObgImgconers, scene_corners, m_homography);
			m_objectPosition = scene_corners;
		//for (int i = 0; i < m_homography.rows; i++) {
		//	uchar* data = m_homography.ptr<uchar>(i);
		//	for (int j = 0; j < m_homography.cols*m_homography.channels(); j++) {
		//		cout << (int)data[j] << " ";
		//	}
		//	cout << endl;
		//}
			for (auto it = m_pointsScene.begin(); it != m_pointsScene.end(); ++it) {
				circle(frame, *it, 3, Scalar(255, 255, 255));
			}
		line(frame, scene_corners[0], scene_corners[1], Scalar(0, 255, 0), 4);
		line(frame, scene_corners[1], scene_corners[2], Scalar(0, 255, 0), 4);
		line(frame, scene_corners[2], scene_corners[3], Scalar(0, 255, 0), 4);
		line(frame, scene_corners[3], scene_corners[0], Scalar(0, 255, 0), 4);
	}
	else {
		float d[] = { 1,0,0,0,1,0,0,0,1 };
		m_homography = Mat(3, 3, CV_32FC1, d).clone();
	}


	m_sceneKeypoints.clear();
	m_pointsScene.clear();
	m_pointsObj.clear();
	m_imagePointsScene.clear();
	m_imagePointsObj.clear();
	m_matchesVoted.clear();
	m_allMatches.clear();


}

TrackingObj::TrackingObj()
{
	m_maxDistance = 0;
	m_minDistance = 999;
	m_trackImg = imread("image/bookObj.jpg");
	cvtColor(m_trackImg, m_trackImgGray, CV_BGR2GRAY);
	m_detector.detect(m_trackImgGray, m_objKeypoints);
	m_extractor.compute(m_trackImgGray, m_objKeypoints, m_descriptorObj);
	m_objKeypoints.shrink_to_fit();
	//ԭͼ�Ľǵ�
	m_ObgImgconers.reserve(4);

	m_ObgImgconers.push_back(cvPoint(0, 0));
	m_ObgImgconers.push_back(cvPoint(m_trackImgGray.cols, 0));
	m_ObgImgconers.push_back(cvPoint(m_trackImgGray.cols, m_trackImgGray.rows));
	m_ObgImgconers.push_back(cvPoint(0, m_trackImgGray.rows));


	m_objectPosition.reserve(4);
	
}


TrackingObj::~TrackingObj()
{
}
