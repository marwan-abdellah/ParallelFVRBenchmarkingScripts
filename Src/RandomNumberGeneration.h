#ifndef RANDOMNUMBERGENERATION_H
#define RANDOMNUMBERGENERATION_H

char charRNG(const char min, const char max);
char ucharRNG(const char min, const char max);
int intRNG(const int min, const int max);
float floatRNG(const float min, const float max);

template <class T>
T RNG(T dummy);

#endif // RANDOMNUMBERGENERATION_H
