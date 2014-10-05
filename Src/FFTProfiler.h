#ifndef FFTPROFILEROFILER_H
#define FFTPROFILEROFILER_H

#include "Common.h"

void ProfileFFT(const DIMENSION dimension, const FFT_ARRAY_TYPE type,
                const PRECISION precision, const THREADING threading,
                const int n, const int numThreads);

void ProfileFFT_3D(const FFT_ARRAY_TYPE type, const PRECISION precision,
                   const THREADING threading, const int n,
                   const int numThreads);


#endif // FFTPROFILEROFILER_H
