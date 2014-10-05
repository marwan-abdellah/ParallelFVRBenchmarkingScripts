#ifndef FFTSHIFTPROFILER_H
#define FFTSHIFTPROFILER_H

#include "Common.h"

/**
 * @brief ProfileFFTShift
 * @param dimension
 * @param format
 * @param type
 * @param threading
 * @param n
 */
void ProfileFFTShift(const DIMENSION dimension, const DATA_FORMAT format,
                     const SHIFT_TYPE type, const THREADING threading,
                     const int n);

template <typename T>
/**
 * @brief ProfileFFTShift_2D
 * @param type
 * @param threading
 * @param n
 * @return
 */
T ProfileFFTShift_2D(const SHIFT_TYPE type, const THREADING threading,
                        const int n);

template <typename T>
/**
 * @brief ProfileFFTShift_3D
 * @param type
 * @param threading
 * @param n
 * @return
 */
T ProfileFFTShift_3D(const SHIFT_TYPE type, const THREADING threading,
                        const int n);


#endif // FFTSHIFTPROFILER_H
