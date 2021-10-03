#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    struct student {
        char name[20];
        int age;
    };

    struct student *students = (struct student *) malloc(2 * sizeof(struct student));
    students[0] = (struct student){"Mohammed Abdoh", 39};

    printf("%s",students[0].name);

    struct student newStudents[2];
    newStudents[0] = (struct student) {"Ahmed Yehia", 10};

    printf("\n%d", newStudents[0].age);
    return 0;
}
