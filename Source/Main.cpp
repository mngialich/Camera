//#include <gst/gst.h>
#include "Camera/VgCamera.h"
#include "Camera/VgVideo.h"
#include "opencv2/opencv.hpp"
#include <boost/thread/thread.hpp>
#include <boost/timer.hpp>

VgCamera Camera;

VgVideo Video;

int main()
{
	cv::Mat *Image;
	
	cv::Mat *WriteImage;
	
	cv::VideoCapture CameraHandle;

	CameraHandle = Camera.GetVideoHandle();
 
	Image = Camera.TakeInitialImage();
	
	WriteImage = Camera.TakeInitialImage();
	
	Video.VideoInitialize(
		Image->rows,
		Image->cols);
	
	std::cout << "Rows: " << Image->rows << std::endl;

	std::cout << "colums: " << Image->cols << std::endl;
	
	Video.SetOutputFileName("TestVideoNew.avi");
		
	Video.SetFormat("h.264");
		
	Video.SetFrameRate(20);
			
	Video.OpenVideoFile(CameraHandle);
				
	for(int i = 1; i < 1000; i++)
	{
		boost::timer Start;
		
		std::cout << "Saving Image" << std::endl;
		
		boost::thread CameraThread(
			boost::bind(&VgCamera::TakeImage, &Camera, Image));
		
		double TotalTime = Start.elapsed();
		
		std::cout << "Frame Rate: " << 1 / TotalTime << std::endl;
		
		*WriteImage = *Image;
		
		boost::timer StartVideo;
		
		boost::thread VideoThread(
			boost::bind(&VgVideo::SetFrame, &Video, WriteImage));
			
		CameraThread.join();
		VideoThread.join();
		
		double TotalTime = StartVideo.elapsed();
		
		std::cout << "Frame Rate: " << 1 / TotalTime << std::endl;
	}

	Video.CloseVideo();

	std::cout << "Completed writting video " << std::endl;
	
	return 0;
}
