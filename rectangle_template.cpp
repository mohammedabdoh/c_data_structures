#include <cstdio>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

template<class T>
class Rectangle
{
    private:
        T length;
        T height;

    public:
        Rectangle<T>(T l, T h)
        {
            length = l;
            height = h;
        }

        T area()
        {
            return length * height;
        }

        void changeLength(T newLength)
        {
            length = newLength;
        }
};


int main()
{    
    Rectangle<int> rect(8, 8);
    printf("%d\n", rect.area());
    return 0;
}
