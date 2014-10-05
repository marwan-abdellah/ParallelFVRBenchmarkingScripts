#ifndef FFTSHIFT2D_H
#define FFTSHIFT2D_H

template <class T>
/**
 * @brief serialFFTShift2D
 * @param data
 * @param N
 */
void serialFFTShift2D(T* data, const int N);

template <class T>
/**
 * @brief parallelFFTShift2D
 * @param data
 * @param N
 */
void parallelFFTShift2D(T* data, const int N);

template <class T>
/**
 * @brief serialFFTShift2D
 * @param input
 * @param output
 * @param N
 */
void serialFFTShift2D(const T* input, T* output, const int N);

template <class T>
/**
 * @brief parallelFFTShift2D
 * @param input
 * @param output
 * @param N
 */
void parallelFFTShift2D(const T* input, T* output, const int N);

#endif // FFTSHIFT2D_H
