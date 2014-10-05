#include "FFTProfiler.h"
#include "FFT3D_InPlace.h"
#include "FFT3D_OutofPlace.h"

#include <iostream>

void ProfileFFT(const DIMENSION dimension, const FFT_ARRAY_TYPE type,
                const PRECISION precision, const THREADING threading,
                const int n, const int numThreads) {

    if (dimension == DIM_2D) {
        // ProfileFFT_2D (type, threading, precision, n, numThreads);
    }
    else if (dimension == DIM_3D) {
        ProfileFFT_3D (type, precision, threading, n, numThreads);
    }
    else
        std::cout << "Wrong profile selection" << std::endl;
}

void ProfileFFT_3D(const FFT_ARRAY_TYPE type,
                   const PRECISION precision, const THREADING threading, const int n,
                   const int numThreads) {

    if (type == IN_PLACE)
        FFT3D_IN_PLACE (n, threading, precision, numThreads);
    else if (type == OUT_OF_PLACE)
        FFT3D_OUT_OF_PLACE (n, threading, precision, numThreads);
    else
        std::cout << "Wrong operation type selection" << std::endl;
}
