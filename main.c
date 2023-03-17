#include <stdio.h>
#include <stdlib.h>

//Matrix 3

void inputmas();

int main() {

inputmas();

return 0;
}

void inputmas() {

int size1, size2;

printf("Size 1: ");
scanf("%d", &size1);

printf("Size 2: ");
scanf("%d", &size2);

int mas1[size1][size2];
int mas2[size1][size2];

printf("Input mas: ");
    for(int i = 0; i < size1; i++) { //Функция ввода
        for(int j = 0; j < size2; j++) {
        int a;
        scanf("%d", &a);
        mas1[i][j] = a;
        }
    }

printf("Output mas: \n");
for(int i = 0; i < size1; i++) { //Функция транспонирования с выводом
    for(int j = 0; j < size2; j++) {
        mas2[i][j] = mas1[j][i];
        printf("%d ", mas2[i][j]);
    }
    printf("\n");
}

return 0;
}