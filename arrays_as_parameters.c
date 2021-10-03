#include <stdio.h>
#include <stdlib.h>

void rotateByOne(int a[], int length)
{
    for (int i = 0; i < length; i++) {
        a[i] *= 2;
    }

    for (int i = 0; i < length; i++) {
        printf("%d\n", a[i]);
    }
}

int main()
{
    int a[3] = {1,2,3};
    rotateByOne(a, 3);
    return 0;
}
