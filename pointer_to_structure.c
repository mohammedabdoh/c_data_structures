#include <stdlib.h>
#include <stdio.h>

int main()
{
    struct student {
        char name[20];
        int age;
    };

    struct student mohammed = {"Mohammed Abdoh", 39};

    struct student *p = (struct student *) malloc(sizeof(struct student));

    p->age = 40;

    printf("%s\n", mohammed.name);
    printf("%d\n", mohammed.age);

    return 0;
}
