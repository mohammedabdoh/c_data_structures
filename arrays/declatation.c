#include <stdio.h>

int main() {

    // declaring an array of size 5

    int A[5];

    A[0] = 2;
    A[1] = 4;
    A[2] = 6;
    A[3] = 8;
    A[4] = 10;

    // declaring an array of size 5 with initialization
    int B[5] = {1,2,3,4,5};

    // declaring an array of size 5 with few initialization
    int C[5] = {10,11};

    // If the initialization begins then all the indexes that were not assigned values will get a value of 0 by default
    int D[5] = {0};

    // declating an array without defining the size but initializing values
    int E[] = {34,93,20};

    return 0;
}
