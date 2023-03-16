//Bilet_4

#include <stdio.h>
#include <stdlib.h>

int sum(char *arr, int b);

int main() {
char mas[10] = "97as97ap!";
int c = 97;

SumFunction(mas, c);

return 0;
}

int SumFunction(char *arr, int b) {
    int sum;
    char changeB;
    changeB = b;
    int n = 0;                                              // Кол-во повторябщихся чисел в массиве

    if(b >= 0) {                                            // Сравнение, если число положительное

        if (b < 10) {                                                           //1) Сравнение, если число однозначное
            for(int i = 0; arr[i] != '\0'; i++) {
                int change1 = arr[i] - '0';
                if(b == change1 || arr[i] == changeB) {
                    n++;
                    sum = b * n;
                }
                else;
            }
            return printf("%d\n", sum);
        }

        else if (b >= 10 && b < 100) {                                          //2) Сравнение, если число двузначное
            int num1 = b / 10; 
            int num2 = b % 10; 
            for(int i = 0; arr[i + 1] != '\0'; i++) {
                int change1 = arr[i] - '0';
                int change2 = arr[i + 1] - '0';
                if(num1 == change1 && num2 == change2 || arr[i] == changeB) {   // Сравниваем первое число и второе
                    n++;
                    sum = b * n;
                }
            else;
            }
            return printf("%d\n", sum);
        }

        else if (b >= 100 && b < 1000) { //3) Сравнение, если число трехзначное
            int num1 = b / 100;
            int num2 = (b / 10) % 10;
            int num3 = b % 10;
            for(int i = 0; arr[i + 2] != '\0'; i++) {
                int change1 = arr[i] - '0';
                int change2 = arr[i + 1] - '0';
                int change3 = arr[i + 2] - '0';
                if(num1 == change1 && num2 == change2 && num3 == change3 || arr[i] == changeB) { // Сравниваем первое, второе и третье число массива
                    n++;
                    sum = b * n;
                }
            else;
            }
            return printf("%d\n", sum);
        }
    }
    else
    return printf("Sorry, but number have a \"-\"\n");
}