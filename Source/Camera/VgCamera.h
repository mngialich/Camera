#pragma once

#include "opencv2/opencv.hpp"
#include <iostream>

class VgCamera
{
	public:
		
		VgCamera();
		
		~VgCamera();
		
		cv::Mat TakeImage();

		cv::VideoCapture GetVideoHandle(void);				

	private:
		
		void OpenCamera(void);
		
		cv::VideoCapture Camera;
		
		cv::Mat mCurrentFrame;
};
