#include <stdio.h>

void BigSm(char*);
void Print(char*);

int main(void) {
    char sym;
    printf("Big symbol: ");
    scanf("%c", &sym);
    BigSm(&sym);
    Print(&sym);

    return 0;
}
void BigSm(char* x) {
    char A = 'A';
    char a = 'a';
    int size = A - a;
    *x -= size; }

void Print(char* y) {
    printf("Small symbol: %c", *y);
}
