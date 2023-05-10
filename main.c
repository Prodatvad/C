#include <stdio.h>
#include <stdlib.h>

int SumFunction(char *arr, int b);
int SizeNumber(int z);

int main(void) {
    int mb = 0;
    printf("Enter size arr: ");
    scanf("%d", &mb);
    if(mb == 0) {                                               //Проверка памяти
        printf("\n");
        printf("Sorry, u don't have memory for the Array =(");
        printf("\n");
        return 1;
    }
    printf("\n");
    printf("Enter your arr: ");
    char *mas = (char*)malloc(sizeof(char) * mb);
    scanf("%s", mas);

    printf("\n");
    printf("Enter your number: ");
    int c = 0;
    scanf("%d", &c);
    
    printf("\nResult: %d\n", SumFunction(mas, c));
    free(mas);                                                  //Освобождение памяти
    return 0;
}

int SizeNumber(int z) {                                         //Функция по вычислению значности числа
    int l = 0;

    if(z == 0) {
        return l = z + 1;
    }

    while(z != 0) {
        l++;
        z = z / 10;
    }
    return l;
}

int SumFunction(char *arr, int b) {
    if(b <= 0) {
        printf("\n");
        printf("Sorry my dear dude =(\nNumber <= 0");
        printf("\n");
        return 1;
    }
    if(arr == NULL) {
        printf("\n");
        printf("Sorry my dear dude =(\nArray == NULL");
        printf("\n");
        return 1;
    }

    char *masb = (char*)malloc(sizeof(*masb) * SizeNumber(b));
    int bb = b; 
    int lastElement = SizeNumber(bb) - 1;                     
    int LE = lastElement;
    int y = 0;
    while(bb != 0) {                                             //Цикл с переводом инта в чар и занесением в массив
        y = bb % 10;
        masb[LE] = y + '0';
        LE--;
        bb = bb / 10;
    }
        
    int n = 0;                                                     
    for(int i = 0; arr[i] != '\0'; i++) {
        if(arr[i] == masb[0] && arr[i + lastElement] != '\0') {
            for(int j = 0; masb[j] == arr[i + j]; j++) {
                if(j == lastElement) {
                    n++;
                    i = i + lastElement;
                }
            }
        }
    }
    free(masb);                                                 //Освобождение памяти 2
    printf("\nN: %d\n", n);
    return n * b;
}
