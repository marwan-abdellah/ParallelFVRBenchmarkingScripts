#ifndef FFTSHIFT3D_OUTOFPLACE_H
#define FFTSHIFT3D_OUTOFPLACE_H

template <typename T>
T FFTShift3D_OUT_OF_PLACE_SERIAL(const int n);

template <typename T>
T FFTShift3D_OUT_OF_PLACE_PARALLEL(const int n);

#endif // FFTSHIFT3D_OUTOFPLACE_H
