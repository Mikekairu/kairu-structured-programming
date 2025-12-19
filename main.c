#include <stdio.h>


void incrementByValue(int num);
void incrementByReference(int *ptr);

int main() {
    int num = 10;

    printf("Original value: %d\n\n", num);


    printf("Pass by Value Example:\n");
    printf("Before incrementByValue: %d\n", num);
    incrementByValue(num);
    printf("After incrementByValue: %d\n\n", num);


    printf("Pass by Reference Example:\n");
    printf("Before incrementByReference: %d\n", num);
    incrementByReference(&num);
    printf("After incrementByReference: %d\n", num);

    return 0;
}

void incrementByValue(int num) {
    num = num + 1;
    printf("Inside incrementByValue: %d\n", num);
}

void incrementByReference(int *ptr) {
    *ptr = *ptr + 1;
    printf("Inside incrementByReference: %d\n", *ptr);
}
