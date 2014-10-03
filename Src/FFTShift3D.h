#ifndef FFTSHIFT3D_H
#define FFTSHIFT3D_H


template <class T>
void serialFFTShift3D(T* data, const int N);

template <class T>
void parallelFFTShift3D(T* data, const int N);

template <class T>
void serialFFTShift3D(const T* input , T* output, const int N);

template <class T>
void parallelFFTShift3D(const T* input , T* output, const int N);
#endif // FFTSHIFT3D_H
