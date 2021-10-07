#include <stdio.h>
#include <stdlib.h>

int sum(int n) {
    if(n == 0)
        return 0;
    return n + sum(n-1);
}

int main() {
    printf("%d\n", sum(10));
    return 0;
}
