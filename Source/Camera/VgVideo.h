#pragma once

#include <opencv2/core/core.hpp> 
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>

class VgVideo
{
	public:
		
		VgVideo();
			
		~VgVideo();
		
		void CheckCompressionTypes(void);
		
		void VideoInitialize(
			int ImageWidth,
			int ImageHeight);
			
		void SetOutputFileName(const std::string);
			
		void SetFormat(const std::string);
			
		void SetFrameRate(int);
			
		void OpenVideoFile(void);
			
		void SetFrame(cv::Mat);
		
	private:
		
		cv::Size mImageSize;
		
		int mCameraWidth;
		
		int mCameraHeigth;
		
		std::string mOutputName;
		
		int mFourCC;
		
		int mFrameRate;
	
		cv::VideoWriter mOutputVideo;
			
		bool mParametersSet;
};
