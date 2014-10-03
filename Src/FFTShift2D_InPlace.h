#ifndef FFTSHIFT2D_INPLACE_H
#define FFTSHIFT2D_INPLACE_H

template <typename T>
T FFTShift2D_IN_PLACE_SERIAL(const int n);

template <typename T>
T FFTShift2D_IN_PLACE_PARALLEL(const int n);

#endif // FFTSHIFT2D_INPLACE_H
