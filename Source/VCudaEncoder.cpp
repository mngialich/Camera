#include "VCudaEncoder.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
VCudaEncoder::VCudaEncoder()
{	
	cuInit(0);
	
	// Check that cuda is supported
	
	int DeviceCount = 0;
	
	cuDeviceGetCount(&DeviceCount);
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
VCudaEncoder::~VCudaEncoder()
{
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void VCudaEncoder::CheckH264Codec(void)
{
	if((4))
	{
		std::cout << "H.264 Encoding is avalible" 
			<< std::endl;
	}
	else
	{
		std::cout << "ERROR: H.264 is not avalible" 
			<< std::endl;
	}
}
