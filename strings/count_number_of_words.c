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

int *countVowelsAndWords(char str[]) {
    
    int wordCount = 0;
    int vowelsCount = 0;

    for (int i = 0, ii = str_length(str); i < ii; i++) {
        
        if(str[i] == ' ' && i - 1 >= 0 && str[i-1] != ' ') {
            wordCount++;
        }
        
        if(str[i] == 'a' ||
           str[i] == 'e' ||
           str[i] == 'i' ||
           str[i] == 'o' ||
           str[i] == 'u'
        ) {
            vowelsCount++;
        }
    }
    
    int *counts = (int *) malloc(sizeof(int) * 2);
    
    counts[0] = ++wordCount;
    counts[1] = vowelsCount;
    
    return counts;
}

int main() {

    char str[100];
    
    printf("Please enter a string: ");
    gets(str);
    
    int *counts = countVowelsAndWords(str);

    printf("Number of words is: %d\n", counts[0]);
    printf("Number of vowels is: %d\n", counts[1]);

    return 0;
}
