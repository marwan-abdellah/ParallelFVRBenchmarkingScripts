#ifndef FFTSHIFT3D_H
#define FFTSHIFT3D_H


template <class T>
/**
 * @brief serialFFTShift3D
 * @param data
 * @param N
 */
void serialFFTShift3D(T* data, const int N);

template <class T>
/**
 * @brief parallelFFTShift3D
 * @param data
 * @param N
 */
void parallelFFTShift3D(T* data, const int N);

template <class T>
/**
 * @brief serialFFTShift3D
 * @param input
 * @param output
 * @param N
 */
void serialFFTShift3D(const T* input , T* output, const int N);

template <class T>
/**
 * @brief parallelFFTShift3D
 * @param input
 * @param output
 * @param N
 */
void parallelFFTShift3D(const T* input , T* output, const int N);
#endif // FFTSHIFT3D_H
