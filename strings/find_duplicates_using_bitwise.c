#include <stdio.h>

int main() {

    char name[20];
    int bitStore = 0;
    int x = 0;

    printf("Enter a string: ");
    gets(name);

    for(int i = 0; name[i] != '\0'; i++) {
        x = 1;
        x = x << (name[i] - 97);

        if((bitStore&x) > 0) {
            printf("%c is duplicate\n", name[i]);
        } else {
            bitStore = bitStore|x;
        }
    }

    return 0;
}
