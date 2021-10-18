/*
 * Copyright@2021 <Mohammed Abdoh>
 */

#include <cstdio>

void swap(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}



int main() {
    int a, b;

    a = 10;
    b = 20;

    // Passing by value
    swap(a, b);
    printf("a: %d, b: %d\n", a, b);

    return 0;
}

