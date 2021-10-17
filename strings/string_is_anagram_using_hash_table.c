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

    char str1[20];
    char str2[20];

    int isAnagram = 1;

    printf("Enter string 1: ");
    gets(str1);

    printf("Enter string 2: ");
    gets(str2);

    if(str_length(str1) != str_length(str2)) {
        printf("%s and %s are not anagram strings", str1, str2);
        return 0;
    }

    int i;
    int hash[26] = {0};

    for(i = 0; str1[i] != '\0'; i++) {
        hash[str1[i] - 97] += 1;
    }

    for(i = 0; str2[i] != '\0'; i++) {
        hash[str2[i] - 97] -= 1;
        if(hash[str2[i] - 97] < 0) {
            isAnagram = 0;
            break;
        }
    }

    if(isAnagram) {
        printf("%s and %s are anagram strings", str1, str2);
    } else {
        printf("%s and %s are not anagram strings", str1, str2);
    }

    return 0;
}
