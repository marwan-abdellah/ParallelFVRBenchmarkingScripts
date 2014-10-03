#ifndef FFTSHIFT3D_INPLACE_H
#define FFTSHIFT3D_INPLACE_H

template <typename T>
T FFTShift3D_IN_PLACE_SERIAL(const int n);

template <typename T>
T FFTShift3D_IN_PLACE_PARALLEL(const int n);

#endif // FFTSHIFT3D_INPLACE_H
