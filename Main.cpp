#include "Source/VCamera.h"
#include "cuda.h"

int main()
{
	// Initialize Cuda
	
	cuInit(0);
	
	VCamera UsbCamera;
	
	UsbCamera.RecordVideo();
	
	return 0;
}