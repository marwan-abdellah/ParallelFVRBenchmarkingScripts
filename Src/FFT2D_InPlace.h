#ifndef FFT2D_IN_PLACE_H
#define FFT2D_IN_PLACE_H

#include <fftw3.h>
#include "Common.h"

/**
 * @brief FFT2D_IN_PLACE
 * @param n
 * @param threading
 * @param precision
 * @param numThreads
 */
void FFT2D_IN_PLACE(const int n, const THREADING threading,
                    const PRECISION precision, const int numThreads);


#endif // FFT2D_IN_PLACE_H
