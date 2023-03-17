#include <stdio.h>
#include <stdlib.h>

//Matrix

int main() {

int i, j, l, k;
int mas1[3][3];
int mas2[3][3];
int mas3[3][3];
int a;

printf("\nInput1: ");
for(i = 0; i < 3; i++){ // Функция заполнения mas1
    for(j = 0; j < 3; j++) {
        scanf("%d", &a);
        mas1[i][j] = a;
    }
}

printf("\nInput2: ");
for(i = 0; i < 3; i++){ // Функция заполнения mas2
    for(j = 0; j < 3; j++) {
        scanf("%d", &a);
        mas2[i][j] = a;
    }
}

for(i = 0; i < 3; i++){ // Функция вычисления mas3
    for(j = 0; j < 3; j++) {
        mas3[i][j] = mas1[i][j] - mas2[i][j];
    }
}
printf("\nResult: ");

for(i = 0; i < 3; i++){ // Функция выведения mas3
    for(j = 0; j < 3; j++) {
        printf("%d ", mas3[i][j]);
    }
}
printf("\n");

return 0;
} 