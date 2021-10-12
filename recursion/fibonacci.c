#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n,int * memoizationArray) {

    if(n <= 1) {
        memoizationArray[n] = n;
        return n;
    }

    if(memoizationArray[n-2] == -1) {
        memoizationArray[n-2] = fibonacci(n-2, memoizationArray);
    }

    if(memoizationArray[n-1] == -1) {
        memoizationArray[n-1] = fibonacci(n-1, memoizationArray);
    }

    return memoizationArray[n-2] + memoizationArray[n-1];
}

int * createMemoizationArrray(int n) {
    int *memoizationArray = (int *) malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++) {
        memoizationArray[i] = -1;
    }

    return memoizationArray;
}

int main() {
    int n;
    
    printf("I need the Fibonacci of nth term: ");
    
    scanf("%d", &n);
    
    printf("Fibonacci of %dth term is: %d\n", n, fibonacci(n, createMemoizationArrray(n)));

    return 0;
}
