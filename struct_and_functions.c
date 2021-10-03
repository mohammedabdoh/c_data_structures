#include <stdio.h>
#include <stdlib.h>

struct rectangle {
    int length;
    int height;
};

void initializeStruct(struct rectangle *rect, int length, int height)
{
   rect->length = length;
   rect->height = height;
}

int area(struct rectangle rect)
{
    return rect.length * rect.height;
}

void changeLength(struct rectangle *rect, int newLength)
{
    rect->length = newLength;
}

int main()
{
    struct rectangle rect;
    
    initializeStruct(&rect, 8, 8);
    
    printf("%d\n", area(rect));
    
    changeLength(&rect, 9);
    
    printf("%d\n", area(rect));
    
    return 0;
}
