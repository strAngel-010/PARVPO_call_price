#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double random_double(double min, double max) {
    return min + (rand() / (double)RAND_MAX) * (max - min);
}

int main() {
    int n;
    printf("Введите количество наборов коэффициентов: ");
    scanf("%d", &n);

    // Открываем файл для записи
    FILE *file = fopen("coefficients.txt", "w");
    if (file == NULL) {
        printf("Ошибка открытия файла!\n");
        return 1;
    }

    srand(time(NULL)); // Инициализация генератора случайных чисел

    for (int i = 0; i < n; i++) {
        double a = random_double(1.0, 10.0); // 'a' не должно быть 0
        double b = random_double(-10.0, 10.0);
        double c = random_double(-10.0, 10.0);
        fprintf(file, "%.2lf %.2lf %.2lf\n", a, b, c);
    }

    fclose(file);
    printf("Сгенерировано %d наборов коэффициентов в файле coefficients.txt\n", n);
    return 0;
}
