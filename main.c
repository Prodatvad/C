#include <stdio.h>
#include <stdlib.h>

int SumFunction(char *arr, int b);
int SizeNumber(int z);

int main() {

int mb = 0;
printf("Enter size arr: ");
scanf("%d", &mb);
printf("\n");
printf("Enter your arr: ");
char *mas = NULL;
mas = (char*)malloc(sizeof(char) * mb);
if(mas == NULL) {                                               //Проверка памяти
    printf("\n");
    printf("Sorry, u don't have memory for the Array =(");
    printf("\n");
return 1;
}
scanf("%s", mas);

printf("\n");
printf("Enter your number: ");
int c = 0;
scanf("%d", &c);

printf("\nResult: %d\n", SumFunction(mas, c));
free(mas);                                                  //Освобождение памяти

return 0;
}

int SizeNumber(int z) {                                     //Функция по вычислению значности числа
int l = 0;
while(z != 0) {
l++;
z = z / 10;
}
return l;
}

int SumFunction(char *arr, int b) {
if(b < 0) {
    printf("\n");
    printf("Sorry my dear dude =(\nNumber < 0");
    printf("\n");
exit(1);
}

int bb = b;
int n = 0;
int sizenum = SizeNumber(b) - 1;

int mb2 = 0;
printf("\n");
printf("Enter size arrB: ");
scanf("%d", &mb2);
char *masb = NULL;
masb = (char*)malloc(sizeof(char) * mb2);
if(masb == NULL) {                                              //Проверка памяти 2
    printf("\n");
    printf("Sorry, u don't have memory for the ArrayB =(");
    printf("\n");
return 1;
}

int y = 0;
while(b != 0) {                                             //Цикл с переводом инта в чар и занесением в массив
    y = b % 10;
    masb[sizenum] = y + '0';
    sizenum--;
    b = b / 10;
}

sizenum = SizeNumber(bb);                                   
for(int i = sizenum; i < 10; i++) {                         //заполняем оставшуюся часть массива нулевым терминалом
    masb[i] = '\0';
}

sizenum--;                                                  //Понижаем на один, чтобы было равно последнему записанному элементу в массиве B
for(int i = 0; arr[i] != '\0'; i++) {
    if(arr[i] == masb[0] && arr[i + sizenum] != '\0') {
        for(int j = 0; masb[j] == arr[i + j]; j++) {
            if(j == sizenum) {
                n++;
                i = i + sizenum;
            }
        }
    }
}
free(masb);                                                 //Освобождение памяти 2
printf("\nN: %d\n", n);
return n * bb;
}