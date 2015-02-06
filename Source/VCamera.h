#pragma once

#include "opencv2/opencv.hpp"
#include "cuda_runtime.h"
#include <iostream>

class VCamera
{
	public:
		
		VCamera();
	
		~VCamera();
		
		void RecordVideo(void);
	
	private:
		
		void OpenCamera(void);
		
		cv::VideoCapture Camera;		
		
		cv::Mat mCurrentFrame;
};
