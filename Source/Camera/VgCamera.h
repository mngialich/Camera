#pragma once

#include "opencv2/opencv.hpp"
#include <iostream>
#include <boost/thread/thread.hpp>


class VgCamera
{
	boost::mutex mutex; 
	
	public:
		
		VgCamera();
		
		~VgCamera();
		
		cv::Mat* TakeInitialImage();
		
		void TakeImage(cv::Mat *);

		cv::VideoCapture GetVideoHandle(void);

	private:
		
		void OpenCamera(void);
		
		cv::VideoCapture Camera;
		
		cv::Mat mCurrentFrame;
};
