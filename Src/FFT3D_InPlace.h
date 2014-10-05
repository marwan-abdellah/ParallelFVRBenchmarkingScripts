#ifndef FFT3D_IN_PLACE_H
#define FFT3D_IN_PLACE_H

#include <fftw3.h>
#include "Common.h"

void FFT3D_IN_PLACE(const int n, const THREADING threading,
                    const PRECISION precision, const int numThreads);


#endif // FFT3D_IN_PLACE_H
