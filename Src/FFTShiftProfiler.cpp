#include "FFTShiftProfiler.h"
#include "FFTShift2D_InPlace.h"
#include "FFTShift2D_OutofPlace.h"
#include "FFTShift3D_InPlace.h"
#include "FFTShift3D_OutofPlace.h"
#include <iostream>

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
                     const int n) {
    if (dimension == DIM_2D) {
        switch (format) {
        case CHAR:
            ProfileFFTShift_2D <char> (type, threading, n);
            break;
        case UCHAR:
            ProfileFFTShift_2D <uchar> (type, threading, n);
            break;
        case SHORT:
            ProfileFFTShift_2D <short> (type, threading, n);
            break;
        case INT:
            ProfileFFTShift_2D <int> (type, threading, n);
            break;
        case FLOAT:
            ProfileFFTShift_2D <float> (type, threading, n);
            break;
        case DOUBLE:
            ProfileFFTShift_2D <double> (type, threading, n);
            break;
        default:
            std::cout << "Wrong data type was selected" << std::endl;
            break;
        }
    }
    else if (dimension == DIM_3D) {
        switch (format) {
        case CHAR:
            ProfileFFTShift_3D <char> (type, threading, n);
            break;
        case UCHAR:
            ProfileFFTShift_3D <uchar> (type, threading, n);
            break;
        case SHORT:
            ProfileFFTShift_3D <short> (type, threading, n);
            break;
        case INT:
            ProfileFFTShift_3D <int> (type, threading, n);
            break;
        case FLOAT:
            ProfileFFTShift_3D <float> (type, threading, n);
            break;
        case DOUBLE:
            ProfileFFTShift_3D <double> (type, threading, n);
            break;
        default:
            std::cout << "Wrong data type was selected" << std::endl;
            break;
        }
    }
    else
        std::cout << "Wrong profile selection" << std::endl;
}

template <typename T>
/**
 * @brief ProfileFFTShift_2D
 * @param type
 * @param threading
 * @param n
 * @return
 */
T ProfileFFTShift_2D(const SHIFT_TYPE type, const THREADING threading,
                        const int n) {
    T ret = NULL;
    if (type == IN_PLACE)
        ret = FFTShift2D_IN_PLACE <T> (n, threading);
    else if (type == OUT_OF_PLACE)
        ret = FFTShift2D_OUT_OF_PLACE <T> (n, threading);
    else
        std::cout << "Wrong operation type selection" << std::endl;

    return ret;
}

template <typename T>
/**
 * @brief ProfileFFTShift_3D
 * @param type
 * @param threading
 * @param n
 * @return
 */
T ProfileFFTShift_3D(const SHIFT_TYPE type, const THREADING threading,
                        const int n) {
    T ret = NULL;
    if (type == IN_PLACE)
        ret = FFTShift3D_IN_PLACE <T> (n, threading);
    else if (type == OUT_OF_PLACE)
        ret = FFTShift3D_OUT_OF_PLACE <T> (n, threading);
    else
        std::cout << "Wrong operation type selection" << std::endl;

    return ret;
}

// Template instanciation
///////////////////////////////////////////////////////////////////////////////
template char ProfileFFTShift_2D
(const SHIFT_TYPE type, const THREADING threading, const int n);
template uchar ProfileFFTShift_2D
(const SHIFT_TYPE type, const THREADING threading, const int n);
template short ProfileFFTShift_2D
(const SHIFT_TYPE type, const THREADING threading, const int n);
template int ProfileFFTShift_2D
(const SHIFT_TYPE type, const THREADING threading, const int n);
template float ProfileFFTShift_2D
(const SHIFT_TYPE type, const THREADING threading, const int n);
template double ProfileFFTShift_2D
(const SHIFT_TYPE type, const THREADING threading, const int n);
///////////////////////////////////////////////////////////////////////////////

