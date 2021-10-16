#include <stdio.h>
#include "string.h"


int str_length(char str[]) {
    
    int i = 0;
    int total = 0;
    
    while(str[i++] != '\0') {
        total++;
    }

    return total;
}

void reverseString(char str[]) {
    
    for(int i = 0, ii = str_length(str) - 1; i < str_length(str); i++, ii--) {
        
        if(i >= ii) {
            break;
        }

        char tmp = str[i];
        str[i] = str[ii];
        str[ii] = tmp;
    }
}

int stringIsEqual(char str1[], char str2[]) {
    int i, j;

    for(i = 0, j = 0; str1[i] != '\0' && str2[j] != '\0'; i++, j++) {
        if(str1[i] != str2[j])
          break;
    }

    if(str1[i] == str2[j]) {
        return 1;
    }

    return 0;
}

int main() {
    char str[20];
    char reversedStr[20];

    printf("Please enter a string: ");
    gets(str);

    strcpy(reversedStr, str);

    reverseString(reversedStr);

    if(stringIsEqual(str, reversedStr)) {
      printf("String is palindrome\n");
    } else {
      printf("String is not palindrome\n");
    }

    return 0;
}
