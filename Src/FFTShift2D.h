#ifndef FFTSHIFT2D_H
#define FFTSHIFT2D_H

template <class T>
void serialFFTShift2D(T* data, const int N);

template <class T>
void parallelFFTShift2D(T* data, const int N);

template <class T>
void serialFFTShift2D(const T* input, T* output, const int N);

template <class T>
void parallelFFTShift2D(const T* input, T* output, const int N);

#endif // FFTSHIFT2D_H
