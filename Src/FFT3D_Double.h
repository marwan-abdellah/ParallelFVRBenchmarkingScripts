#ifndef FFT3D_DOUBLE_H
#define FFT3D_DOUBLE_H

#include "Common.h"

#include <fftw3.h>

void serialFFT3D_DOUBLE(fftw_complex* data, const int N);
void serialFFT3D_DOUBLE(const fftw_complex* input, fftw_complex* output,
                        const int N);

void parallelFFT3D_DOUBLE(fftw_complex* data, const int N, const int numThreads);
void parallelFFT3D_DOUBLE(const fftw_complex* input, fftw_complex* output,
                          const int N, const int nulThreads);


#endif // FFT3D_DOUBLE_H
