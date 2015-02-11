#include "VgVideo.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
VgVideo::VgVideo():
	mCameraWidth(0),
	mCameraHeigth(0),
	mFourCC(0),
	mFrameRate(0),
	mParametersSet(false)
{
	mOutputName.clear();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
VgVideo::~VgVideo()
{	
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void VgVideo::CheckCompressionTypes(void)
{
	cv::VideoWriter outputVideo("filename", -1, 10, cv::Size(10,10));
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void VgVideo::VideoInitialize(
	int ImageWidth,
	int ImageHeight)
{
	mCameraWidth = ImageWidth;
	
	mCameraHeigth = ImageHeight;
	
	mImageSize = cv::Size(mCameraHeigth,
		mCameraWidth);
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void VgVideo::SetOutputFileName(const std::string OutputFileName)
{
	mOutputName.assign(OutputFileName);
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void VgVideo::SetFormat(std::string FormatName)
{
	if(FormatName == "h.264")
	{
		mFourCC = CV_FOURCC('H','2','6','4');
	}
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void VgVideo::SetFrameRate(int FrameRate)
{
	mFrameRate = FrameRate;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void VgVideo::OpenVideoFile(cv::VideoCapture VideoHandle)
{
	if(mOutputName.size() == 0)
	{
		std::cout << "Please deinfe a file name" << std::endl;
	}
	else if( mFourCC == 0)
	{
		std::cout << "Please define a video format" << std::endl;
	}
	else if(mFrameRate == 0)
	{
		std::cout << "Please define a frame rate" << std::endl;
	}
	else if (mCameraWidth == 0 || mCameraHeigth == 0)
	{
		std::cout << "Please define an image size" << std::endl;
	} 
	else
	{
		mOutputVideo.open(
			mOutputName,
			mFourCC,
			mFrameRate,
			mImageSize);
			
		mParametersSet = true;
	}
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void VgVideo::SetFrame(cv::Mat *Frame)
{
	if(mParametersSet == true)
	{
		mutex.lock();
		
		mOutputVideo.write(*Frame);
		
		mutex.unlock();
	}
	else
	{
		std::cout << "Parameters are not set" << std::endl;
	}
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void VgVideo::CloseVideo(void)
{
	mOutputVideo.release();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void VgVideo::DisplayVideo(void)
{
	cv::VideoCapture video("TestVideoNew.avi");

	cv::Mat Frame;

	std::cout << "Displaying Video" << std::endl;

	while(video.read(Frame))
	{
		imshow("Frame Grabber",
			Frame);

	}
}
