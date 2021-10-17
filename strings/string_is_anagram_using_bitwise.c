#include <stdio.h>

int str_length(char str[]) {

    int i = 0;
    int total = 0;

    while(str[i++] != '\0') {
        total++;
    }

    return total;
}

int main() {
    // Note that this is only useful for unique strings (the ones with no duplicates)
    char str1[20];
    char str2[20];

    int bits = 0;
    int bits2 = 0;

    printf("Enter string 1: ");
    gets(str1);

    printf("Enter string 2: ");
    gets(str2);

    if(str_length(str1) != str_length(str2)) {
        printf("%s and %s are not anagram strings", str1, str2);
        return 0;
    }

    int i;

    for(i = 0; str1[i] != '\0'; i++) {
        bits = 1;
        bits |= str1[i] - 97;
    }

    for(i = 0; str2[i] != '\0'; i++) {
        bits2 = 1;
        bits2 |= str2[i] - 97;
    }

    if(bits == bits2) {
        printf("%s and %s are anagram strings", str1, str2);
    } else {
        printf("%s and %s are not anagram strings", str1, str2);
    }

    return 0;
}
