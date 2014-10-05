#include "FFTProfiler.h"
#include "FFT2D_InPlace.h"
#include "FFT2D_OutofPlace.h"
#include "FFT3D_InPlace.h"
#include "FFT3D_OutofPlace.h"

#include <iostream>

/**
 * @brief ProfileFFT
 * @param dimension
 * @param type
 * @param precision
 * @param threading
 * @param n
 * @param numThreads
 */
void ProfileFFT(const DIMENSION dimension, const FFT_ARRAY_TYPE type,
                const PRECISION precision, const THREADING threading,
                const int n, const int numThreads) {

    if (dimension == DIM_2D) {
        ProfileFFT_2D (type, precision, threading, n, numThreads);
    }
    else if (dimension == DIM_3D) {
        ProfileFFT_3D (type, precision, threading, n, numThreads);
    }
    else
        std::cout << "Wrong profile selection" << std::endl;
}


/**
 * @brief ProfileFFT_2D
 * @param type
 * @param precision
 * @param threading
 * @param n
 * @param numThreads
 */
void ProfileFFT_2D(const FFT_ARRAY_TYPE type,
                   const PRECISION precision, const THREADING threading,
                   const int n, const int numThreads) {
    if (type == IN_PLACE)
        FFT2D_IN_PLACE (n, threading, precision, numThreads);
    else if (type == OUT_OF_PLACE)
        FFT2D_OUT_OF_PLACE (n, threading, precision, numThreads);
    else
        std::cout << "Wrong operation type selection" << std::endl;

}


/**
 * @brief ProfileFFT_3D
 * @param type
 * @param precision
 * @param threading
 * @param n
 * @param numThreads
 */
void ProfileFFT_3D(const FFT_ARRAY_TYPE type,
                   const PRECISION precision, const THREADING threading,
                   const int n, const int numThreads) {

    if (type == IN_PLACE)
        FFT3D_IN_PLACE (n, threading, precision, numThreads);
    else if (type == OUT_OF_PLACE)
        FFT3D_OUT_OF_PLACE (n, threading, precision, numThreads);
    else
        std::cout << "Wrong operation type selection" << std::endl;
}
