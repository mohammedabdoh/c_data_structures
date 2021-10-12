#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p, *q;

    // create an array
    p = (int *) malloc(sizeof(int) * 5);

    //initialize it
    p[0] = 1; p[1] = 2; p[2] = 3; p[3] = 4; p[4] = 5;

    // create another bigger array
    q = (int *) malloc(sizeof(int) * 10);

    // initialize it
    for (int i = 0; i < 5; i++) {
        q[i] = p[i];
    }

    // free up p
    free(p);

    // Assign a new address to p
    p = q;

    // nullify q
    q = NULL;

    printf("%d\n", p[0]);


    return 0;
}
