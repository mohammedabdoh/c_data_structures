#include <stdio.h>
#include <stdlib.h>

int factorial(int num) {
    if(num == 1) {
        return 1;
    }

    return num * factorial(num - 1);
}

int main() {
    int num;

    printf("Please enter the number: ");
    scanf("%d", &num);

    printf("%d! is: %d\n", num, factorial(num));
    return 0;
}
