#include <stdio.h>

int main() {

    char name[] = "mohammed";
    
    int i;
    int hash[26] = {0};

    for(i = 0; name[i] != '\0'; i++) {
        hash[name[i] - 97] += 1;
    }

    for (int j = 0; j < 26; ++j) {
        if(hash[j] > 1) {
            printf("Found that letter %c has %d duplicates", j + 97, hash[j]);
        }
    }

    return 0;
}
