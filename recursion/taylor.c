#include <stdio.h>
#include <stdlib.h>

double e(int x, int num) {
    static double factorial = 1, power = 1;
    double result;

    if(num == 0) 
        return 1;

    result = e(x, num - 1);
    power *= x;
    factorial *= num;

    return result + (power / factorial);
}

int main() {
    printf("%lf \n", e(1, 10));
    return 0;
}
