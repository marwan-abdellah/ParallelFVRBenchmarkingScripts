#ifndef FFTSHIFT2D_OUTOFPLACE_H
#define FFTSHIFT2D_OUTOFPLACE_H

template <typename T>
T FFTShift2D_OUT_OF_PLACE_SERIAL(const int n);

template <typename T>
T FFTShift2D_OUT_OF_PLACE_PARALLEL(const int n);

#endif // FFTSHIFT2D_OUTOFPLACE_H
