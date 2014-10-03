#include "FFTShift2D_OutofPlace.h"
#include "FFTShift2D.h"
#include "RandomNumberGeneration.h"

#include <iostream>
/**
 * @brief FFTShift3D_OUT_OF_PLACE_SERIAL
 * @param n
 */
template <typename T>
T FFTShift2D_OUT_OF_PLACE_SERIAL(const int n) {

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
    serialFFTShift2D<T>(a, b, n);

    // Free array
    std::cout << "Freeing memory" << std::endl;
    delete [] a;
    delete [] b;

    return 0;
}

/**
 * @brief FFTShift3D_OUT_OF_PLACE_PARALLEL
 * @param n
 */
template <typename T>
T FFTShift2D_OUT_OF_PLACE_PARALLEL(const int n) {

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
    parallelFFTShift2D<T>(a, b, n);

    // Free array
    std::cout << "Freeing memory" << std::endl;
    delete [] a;
    delete [] b;

    return 0;
}


template
char FFTShift2D_OUT_OF_PLACE_SERIAL(const int n);
template
unsigned char FFTShift2D_OUT_OF_PLACE_SERIAL(const int n);
template
short FFTShift2D_OUT_OF_PLACE_SERIAL(const int n);
template
unsigned short FFTShift2D_OUT_OF_PLACE_SERIAL(const int n);
template
int FFTShift2D_OUT_OF_PLACE_SERIAL(const int n);
template
float FFTShift2D_OUT_OF_PLACE_SERIAL(const int n);
template
double FFTShift2D_OUT_OF_PLACE_SERIAL(const int n);


template
char FFTShift2D_OUT_OF_PLACE_PARALLEL(const int n);
template
unsigned char FFTShift2D_OUT_OF_PLACE_PARALLEL(const int n);
template
short FFTShift2D_OUT_OF_PLACE_PARALLEL(const int n);
template
unsigned short FFTShift2D_OUT_OF_PLACE_PARALLEL(const int n);
template
int FFTShift2D_OUT_OF_PLACE_PARALLEL(const int n);
template
float FFTShift2D_OUT_OF_PLACE_PARALLEL(const int n);
template
double FFTShift2D_OUT_OF_PLACE_PARALLEL(const int n);


