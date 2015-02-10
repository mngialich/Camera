//#include <gst/gst.h>
#include "Camera/VgCamera.h"
#include "Camera/VgVideo.h"
#include "opencv2/opencv.hpp"

VgCamera Camera;

VgVideo Video;


int main()
{
	cv::Mat Image;
	
	Image = Camera.TakeImage();


	Video.VideoInitialize(
		Image.rows,
		Image.cols);
		
		Video.SetOutputFileName("TestVideo");
		
		Video.SetFormat("h.264");
		
		Video.SetFrameRate(15);
		
		//Video.OpenVideoFile();
		
		for(int i = 1; i < 2; i++)
		{
			std::cout << "Saving Image" << std::endl;
			Image = Camera.TakeImage();
	
			Video.OpenVideoFile(Image);
		}
	
	return 0;
}
