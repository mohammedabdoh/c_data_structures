#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swap_by_reference(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a, b;
    
    a = 10;
    b = 20;

    // Passing by value
    swap(a, b);
    printf("a: %d, b: %d\n", a, b);

    // Passing by address
    swap_by_reference(&a, &b);
    printf("a: %d, b: %d\n", a, b);

    return 0;
}


