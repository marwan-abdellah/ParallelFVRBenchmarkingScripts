#ifndef FFTSHIFTPROFILER_H
#define FFTSHIFTPROFILER_H

#include "Common.h"

void ProfileFFTShift(const DIMENSION dimension, const DATA_FORMAT format,
                     const SHIFT_TYPE type, const THREADING threading,
                     const int n);

template <typename T>
T ProfileFFTShift_2D(const SHIFT_TYPE type, const THREADING threading,
                        const int n);

template <typename T>
T ProfileFFTShift_3D(const SHIFT_TYPE type, const THREADING threading,
                        const int n);


#endif // FFTSHIFTPROFILER_H
