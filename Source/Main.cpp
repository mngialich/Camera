//#include <gst/gst.h>
#include "Camera/VgCamera.h"
#include "Camera/VgVideo.h"
#include "opencv2/opencv.hpp"

VgCamera Camera;

VgVideo Video;

int main()
{
	cv::Mat *Image;
	
	cv::VideoCapture CameraHandle;

	CameraHandle = Camera.GetVideoHandle();
 
	Image = Camera.TakeImage();
	
	Video.VideoInitialize(
		Image->rows,
		Image->cols);
	
	std::cout << "Rows: " << Image->rows << std::endl;

	std::cout << "colums: " << Image->cols << std::endl;
	
	Video.SetOutputFileName("TestVideoNew.avi");
		
	Video.SetFormat("h.264");
		
	Video.SetFrameRate(10);
			
	Video.OpenVideoFile(CameraHandle);
			
	for(int i = 1; i < 10000; i++)
	{
		std::cout << "Saving Image" << std::endl;
			
		Image = Camera.TakeImage();
	
		Video.SetFrame(Image);
	}

	Video.CloseVideo();

	std::cout << "Completed writting video " << std::endl;
	
	return 0;
}
