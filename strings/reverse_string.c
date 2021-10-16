#include <stdio.h>
#include <stdlib.h>

int str_length(char str[]) {
    
    int i = 0;
    int total = 0;
    
    while(str[i++] != '\0') {
        total++;
    }

    return total;
}

const char* reverseString(char str[]) {
    
    for(int i = 0, ii = str_length(str) - 1; i < str_length(str); i++, ii--) {
        
        if(i == ii) {
            break;
        }

        char tmp = str[i];
        str[i] = str[ii];
        str[ii] = tmp;
    }

    return str;
}

int isPalendromeString(char str[]) {
    
    return 1;
}

int main() { 
    printf("%s", reverseString("Mohammed"));
    return 0;
}
