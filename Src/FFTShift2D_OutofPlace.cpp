#include "FFTShift2D_OutofPlace.h"
#include "FFTShift2D.h"
#include "RandomNumberGeneration.h"

#include <iostream>

template <typename T>
/**
 * @brief FFTShift2D_OUT_OF_PLACE
 * @param n
 * @param threading
 * @return
 */
T FFTShift2D_OUT_OF_PLACE(const int n, const THREADING threading) {

    // Allocate the arrays
    std::cout << "Allocation" << std::endl;

    const int imageSize = n * n;
    T* a = new T[imageSize];
    T* b = new T[imageSize];

    std::cout << "Initialization" << std::endl;
    for (int i = 0; i < imageSize; i++) {
        a[i] = RNG (T(0));
        b[i] = 0;
    }

    // Do the FFT Shift
    std::cout << "Executing operation" << std::endl;
    switch (threading) {
    case SERIAL:
        serialFFTShift2D<T>(a, b, n);
        break;
    case PARALLEL:
        parallelFFTShift2D<T>(a, b, n);
        break;
    default:
        break;
    }

    // Free array
    std::cout << "Freeing memory" << std::endl;
    delete [] a;
    delete [] b;

    return 0;
}


// Template instanciation
///////////////////////////////////////////////////////////////////////////////
template
char FFTShift2D_OUT_OF_PLACE(const int n, const THREADING threading) ;
template
unsigned char FFTShift2D_OUT_OF_PLACE(const int n, const THREADING threading) ;
template
short FFTShift2D_OUT_OF_PLACE(const int n, const THREADING threading) ;
template
unsigned short FFTShift2D_OUT_OF_PLACE(const int n, const THREADING threading) ;
template
int FFTShift2D_OUT_OF_PLACE(const int n, const THREADING threading) ;
template
float FFTShift2D_OUT_OF_PLACE(const int n, const THREADING threading) ;
template
double FFTShift2D_OUT_OF_PLACE(const int n, const THREADING threading) ;
///////////////////////////////////////////////////////////////////////////////



