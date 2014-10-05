#ifndef FFT3D_DOUBLE_H
#define FFT3D_DOUBLE_H

#include "Common.h"

#include <fftw3.h>

/**
 * @brief serialFFT3D_DOUBLE
 * @param data
 * @param N
 */
void serialFFT3D_DOUBLE(fftw_complex* data, const int N);

/**
 * @brief serialFFT3D_DOUBLE
 * @param input
 * @param output
 * @param N
 */
void serialFFT3D_DOUBLE(const fftw_complex* input, fftw_complex* output,
                        const int N);

/**
 * @brief parallelFFT3D_DOUBLE
 * @param data
 * @param N
 * @param numThreads
 */
void parallelFFT3D_DOUBLE(fftw_complex* data, const int N, const int numThreads);


/**
/** * @brief parallelFFT3D_DOUBLE
/** * @param input
/** * @param output
/** * @param N
/** * @param nulThreads
/** */
void parallelFFT3D_DOUBLE(const fftw_complex* input, fftw_complex* output,
                          const int N, const int nulThreads);


#endif // FFT3D_DOUBLE_H
