#include <math.h>

#pragma GCC optimize ("inline-functions")

double calc_D(double a, double b, double c) {
    return b * b - 4 * a * c;
}

double calc_x1(double a, double b, double discriminant) {
    return (-b + sqrt(discriminant)) / (2*a);
}

double calc_x2(double a, double b, double discriminant) {
    return (-b - sqrt(discriminant)) / (2*a);
}
