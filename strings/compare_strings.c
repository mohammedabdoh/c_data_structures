#include <stdio.h>

int main() {

    char name[] = "Mohammed";
    char name2[] = "Mohamed";
    
    int i, j;

    for(i = 0, j = 0; name[i] != '\0' && name2[j] != '\0'; i++, j++) {
        if(name[i] != name2[j]) 
            break;
    }

    if(name[i] == name2[j]) {
        printf("Strings are equal");
    } else if (name[i] < name2[j]) {
        printf("%s is less than %s", name, name2);
    } else {
        printf("%s is greater than %s", name, name2);
    }

    return 0;
}
