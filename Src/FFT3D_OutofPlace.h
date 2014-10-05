#ifndef FFT3D_OUT_OF_PLACE_H
#define FFT3D_OUT_OF_PLACE_H
#include "Common.h"


/**
 * @brief FFT3D_OUT_OF_PLACE
 * @param n
 * @param threading
 * @param precision
 * @param numThreads
 */
void FFT3D_OUT_OF_PLACE(const int n, const THREADING threading,
                    const PRECISION precision, const int numThreads);


#endif // FFT3D_OUT_OF_PLACE_H
