#include <stdio.h>
#include <stdlib.h>

double e(int x, int num) {
    static double result = 1;

    if(num == 0) 
        return result;

    result = 1 + (x * result / num);
    

    return e(x, num - 1);
}

double e_iterative(int x, int num) {
    double result = 1;

    for (; num > 0; num--) {
        result = 1 + (x * result / num);
    }

    return result;
}

int main() {
    printf("%lf \n", e(1, 10));
    printf("%lf \n", e_iterative(1, 10));
    return 0;
}
