#include <cstdio>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Rectangle
{
    private:
        int length;
        int height;

    public:
        Rectangle(int l, int h)
        {
            length = l;
            height = h;
        }

        int area()
        {
            return length * height;
        }

        void changeLength(int newLength)
        {
            length = newLength;
        }
};


int main()
{    
    Rectangle rect(8, 8);
    printf("%d\n", rect.area());
    return 0;
}
