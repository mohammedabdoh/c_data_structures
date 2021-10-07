#include <stdio.h>
#include <stdlib.h>

int power(int num, int pwr) {
    if(pwr == 0)
        return 1;
    
    return num * power(num, pwr - 1);
}

int main() {
    int num, pwr;

    printf("Please enter the number: ");
    scanf("%d", &num);

    printf("Please enter the power: ");
    scanf("%d", &pwr);

    printf("%d^%d is: %d\n", num, pwr, power(num, pwr));
    return 0;
}
