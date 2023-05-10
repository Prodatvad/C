#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int i, j;
    int mas1[3][3];
    int mas2[3][3];
    int a, b;

    printf("Input1: ");
    for(i = 0; i < 3; i++) {                // Функция занесения делимых чисел в массив 1
        for(j = 0; j < 3; j++) {
            scanf("%d", &a);
            mas1[i][j] = a;
        }
    }

    printf("Input2: ");
    scanf("%d", &b);                        //Ввод делителя
    for(i = 0; i < 3; i++) {                //Функция вычисления частных и занесение их в массив 2
        for(j = 0; j < 3; j++) {
            mas2[i][j] = mas1[i][j] / b;
        }
    }

    printf("Result: ");
    for(i = 0; i < 3; i++) {                //Функция выведения частных из массива 2
        for(j = 0; j < 3; j++) {
            printf("%d ", mas2[i][j]);
        }
    }

    return 0;
}
