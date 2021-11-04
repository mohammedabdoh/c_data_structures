#include <iostream>
#include <vector>

using std::cout;
using std::vector;

template<class T>
class Stack
{
private:
    int size;
    int top;
    vector<T> storage;

public:
    Stack(int sizeValue)
    {
        size = sizeValue;
        top = -1;
        storage = vector<T>(size);
    }

    void push(T value) {
        if(top == size - 1) {
            return;
        }
        storage[++top] = value;
    }

    T pop() {
        if(top == -1) {
            return 0;
        }

        T lastElement = storage[top];
        
        storage[top] = 0;
        top--;

        return lastElement;
    }

    T peek() {
        if(isEmpty()) {
            throw std::logic_error("No peek found. Stack is empty");
        }
        
        return storage[top];
    }

    bool isEmpty() {
        return top == -1;
    }
        
    void print() const
    {
        int i = top;
        while (i >= 0)
        {
            if(storage[i] == 0) {
                i--;
                continue;
            }
            printf("------\n| %d  |\n", storage[i]);
            i--;
        }
        printf("------\n");
    }
};

int main() {
    Stack<int> mystack(10);

    mystack.push(1);
    mystack.push(2);
    mystack.pop();
    mystack.push(3);
    mystack.push(4);
    mystack.push(5);
    mystack.pop();
    mystack.push(11);
    mystack.pop();
    mystack.push(12);
    mystack.push(20);

    mystack.print();

    Stack<char> mystack2(10);

    mystack2.push('a');
    mystack2.push('b');
    mystack2.pop();
    mystack2.push('c');
    mystack2.push('d');
    mystack2.push('e');
    mystack2.pop();
    mystack2.push('f');
    mystack2.pop();
    mystack2.push('g');
    mystack2.push('h');

    mystack2.print();

    try {
        Stack<int> mystack3(0);
        int peek = mystack3.peek();
        cout << peek << "\n";
    } catch(const std::exception& e) {
        cout << e.what() << "\n";
    }

    return 0;
}