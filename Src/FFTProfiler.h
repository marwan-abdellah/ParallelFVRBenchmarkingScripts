#ifndef FFTPROFILEROFILER_H
#define FFTPROFILEROFILER_H

#include "Common.h"

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
                const int n, const int numThreads);

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
                   const int n, const int numThreads);

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
                   const int n, const int numThreads);


#endif // FFTPROFILEROFILER_H
