#pragma once

#include <iostream>
#include "cuda.h"
#include "cuda_runtime.h"

class VCudaEncoder
{
	public:
		
		VCudaEncoder();
		
		~VCudaEncoder();
		
		void CheckH264Codec(void);

	private:
};
