#include <stdio.h>
#include <stdlib.h>

int main() {

    // declaring and initializing a 2D array (in stack)

    int quarterlyResults [4][3] = {{1,2,3}, {4,5,6}, {7,8,9}, {10,11,12}};
    
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 3; j++) {
            printf("Row %d Column %d: %d\n", i, j, quarterlyResults[i][j]);
        }
    }

    // declaring a 2D array (the main array of pointers remains in stack but the actual arrays are in heap)

    int *A[4];
    
    A[0] = (int *) malloc(sizeof(int) * 3);
    A[1] = (int *) malloc(sizeof(int) * 3); 
    A[2] = (int *) malloc(sizeof(int) * 3);
    A[3] = (int *) malloc(sizeof(int) * 3);

    // declaring a 2D array all in heap
    int **B;

    B = (int **) malloc(sizeof(int *) * 4);
    
    B[0] = (int *) malloc(sizeof(int) * 3);
    B[1] = (int *) malloc(sizeof(int) * 3);
    B[2] = (int *) malloc(sizeof(int) * 3);
    B[3] = (int *) malloc(sizeof(int) * 3);

    return 0;
}
