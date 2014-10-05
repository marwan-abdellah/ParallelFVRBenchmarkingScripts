#ifndef FFT3D_SINGLE_H
#define FFT3D_SINGLE_H

#include "Common.h"

#include <fftw3.h>

void serialFFT3D_SINGLE(fftwf_complex* data, const int N);
void serialFFT3D_SINGLE(const fftwf_complex* input, fftwf_complex* outout,
                        const int N);

void parallelFFT3D_SINGLE(fftwf_complex* data, const int N, const int nulThreads);
void parallelFFT3D_SINGLE(const fftwf_complex* input, fftwf_complex* output,
                          const int N, const int nulThreads);


#endif // FFT3D_SINGLE_H
