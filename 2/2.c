#include <stdio.h>
#include <math.h>
#include <time.h>

#pragma GCC optimize ("inline-functions")

inline double __attribute__((always_inline)) calc_D(double a, double b, double c) {
    return b*b - 4*a*c;
}

inline double __attribute__((always_inline)) calc_x1(double a, double b, double discriminant) {
    return (-b + sqrt(discriminant)) / (2*a);
}

inline double __attribute__((always_inline)) calc_x2(double a, double b, double discriminant) {
    return (-b - sqrt(discriminant)) / (2*a);
}

int main() {
    double a, b, c, D, x1, x2;
    clock_t start, end;
    double cpu_time_used = 0;
    int total_loops = 0;

    while (scanf("%lf %lf %lf", &a, &b, &c) == 3) {
        total_loops++;

        start = clock();
        D = calc_D(a, b, c);
        if (D >= 0) {
            x1 = calc_x1(a, b, D);
            x2 = calc_x2(a, b, D);
        }
        end = clock();
        cpu_time_used += ((double)(end - start)) / CLOCKS_PER_SEC;
    }
    printf("\nВремя работы программы: %.6f секунд\n", cpu_time_used);
    printf("Exiting...\n");
    return 0;
}
