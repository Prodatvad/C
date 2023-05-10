#include <stdio.h>

int main(void){
    int arr[5] = {};

    scanf("%d %d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4]);

    int min = arr[4];
    for(int i = 4; i > -1; i--) {
        if(arr[i] < min) {
            min = arr[i];
        }
    }

    int max = arr[4];
    for(int i = 4; i > -1; i--) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    printf("min: %d\nmax: %d", min, max);

    return 0;
}
