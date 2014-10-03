#include "FFTShift3D_OutofPlace.h"
#include "FFTShift3D.h"
#include "RandomNumberGeneration.h"

#include <iostream>
/**
 * @brief FFTShift3D_OUT_OF_PLACE
 * @param n
 */
template <typename T>
T FFTShift3D_OUT_OF_PLACE(const int n, const THREADING threading) {

    // Allocate the arrays
    std::cout << "Allocation" << std::endl;

    const int volumeSize = n * n * n;
    T* a = new T[volumeSize];
    T* b = new T[volumeSize];

    std::cout << "Initialization" << std::endl;
    for (int i = 0; i < volumeSize; i++) {
        a[i] = RNG (T(0));
        b[i] = 0;
    }

    // Do the FFT Shift
    std::cout << "Executing operation" << std::endl;
    switch (threading) {
    case SERIAL:
        serialFFTShift3D<T>(a, b, n);
        break;
    case PARALLEL:
        parallelFFTShift3D<T>(a, b, n);
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


template
char FFTShift3D_OUT_OF_PLACE(const int n, const THREADING threading) ;
template
unsigned char FFTShift3D_OUT_OF_PLACE(const int n, const THREADING threading) ;
template
short FFTShift3D_OUT_OF_PLACE(const int n, const THREADING threading) ;
template
unsigned short FFTShift3D_OUT_OF_PLACE(const int n, const THREADING threading) ;
template
int FFTShift3D_OUT_OF_PLACE(const int n, const THREADING threading) ;
template
float FFTShift3D_OUT_OF_PLACE(const int n, const THREADING threading) ;
template
double FFTShift3D_OUT_OF_PLACE(const int n, const THREADING threading) ;



