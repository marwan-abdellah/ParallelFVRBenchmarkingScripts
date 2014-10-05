#ifndef FFT2D_SINGLE_H
#define FFT2D_SINGLE_H

#include "Common.h"

#include <fftw3.h>

/**
 * @brief serialFFT2D_SINGLE
 * @param data
 * @param N
 */
void serialFFT2D_SINGLE(fftwf_complex* data, const int N);

/**
 * @brief serialFFT2D_SINGLE
 * @param input
 * @param outout
 * @param N
 */
void serialFFT2D_SINGLE(const fftwf_complex* input, fftwf_complex* outout,
                        const int N);

/**
 * @brief parallelFFT2D_SINGLE
 * @param data
 * @param N
 * @param numThreads
 */
void parallelFFT2D_SINGLE(fftwf_complex* data, const int N, const int numThreads);

/**
 * @brief parallelFFT2D_SINGLE
 * @param input
 * @param output
 * @param N
 * @param numThreads
 */
void parallelFFT2D_SINGLE(const fftwf_complex* input, fftwf_complex* output,
                          const int N, const int numThreads);


#endif // FFT2D_SINGLE_H
