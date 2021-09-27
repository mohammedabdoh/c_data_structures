#include <stdlib.h>
#include <stdio.h>

int main() 
{
    int num = 100;

    // Initialize a pointer 
    int *p;

    // Assign a value
    p = &num;

    // Deferencing
    printf("%d\n", *p);

    // Printing the memory address of the pointer
    printf("%p\n", p);
    printf("%p\n", &num);

    // Lets define an array and use a pointer to it
    int *nums;
    nums = (int *) malloc(6 * sizeof(int));
    nums[0] = 10;
    printf("%d\n", nums[0]);

    free(p);

    return 0;

}