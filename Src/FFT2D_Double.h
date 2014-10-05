#ifndef FFT2D_DOUBLE_H
#define FFT2D_DOUBLE_H

#include "Common.h"

#include <fftw3.h>

/**
 * @brief serialFFT2D_DOUBLE
 * @param data
 * @param N
 */
void serialFFT2D_DOUBLE(fftw_complex* data, const int N);

/**
 * @brief serialFFT2D_DOUBLE
 * @param input
 * @param output
 * @param N
 */
void serialFFT2D_DOUBLE(const fftw_complex* input, fftw_complex* output,
                        const int N);

/**
 * @brief parallelFFT2D_DOUBLE
 * @param data
 * @param N
 * @param numThreads
 */
void parallelFFT2D_DOUBLE(fftw_complex* data, const int N, const int numThreads);

/**
 * @brief parallelFFT2D_DOUBLE
 * @param input
 * @param output
 * @param N
 * @param nulThreads
 */
void parallelFFT2D_DOUBLE(const fftw_complex* input, fftw_complex* output,
                          const int N, const int nulThreads);


#endif // FFT2D_DOUBLE_H
