#include<stdio.h>

int X;
int Y;
void printmap();

int main() {    
    printmap();

    char movement;
    char w = 'w';
    char s = 's';
    char a = 'a';
    char d = 'd';

    while(1) {
        scanf("%c", &movement);
        switch(movement) {
            case 'w':
            Y--;
            break;

            case 's':
            Y++;
            break;

            case 'a':
            X--;
            break;

            case 'd':
            X++;
            break;
        }    
        printmap();
        printf("\n");
    }
    
    return 0;
}
int X = 3;
int Y = 3;

void printmap() {
    for(int y = 0; y<=6; y++) { 
        for(int x = 0; x<=6; x++) {
            char point = '.';
            if(x == X && y == Y) {
                char player = 'X';
                point = player;
                printf("%c ", point); 
            }
            else {
                printf("%c ", point);
            }
        }
printf("\n");
    }
}
