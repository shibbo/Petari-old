#include <cmath>

double fmod(double x, double y) {
    return __ieee754_fmod(x, y);
}