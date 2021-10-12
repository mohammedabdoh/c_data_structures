#include <stdio.h>
#include <stdlib.h>

int calculateComabination(int n, int r) {
    if (r == 0 || n == r) {
        return 1;
    }
    return calculateComabination(n - 1, r - 1) + calculateComabination(n - 1, r);
}

int main() {
    int n, r;
    

    printf("Please enter n and r to calculate combination: ");
    
    scanf("%d", &n);
    scanf("%d", &r);

    printf("Combination of n: %d and r: %d is: %d\n", n, r, calculateComabination(n, r));

    return 0;
}
