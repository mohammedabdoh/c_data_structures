#include <iostream>
#include "linked_list.hh"

using std::cout;

template<class T>
class Stack
{
private:
    int size;
    LinkedList<T> storage;

public:
    Stack(int sizeValue)
    {
        size = sizeValue;
        storage = LinkedList<T>();
    }

    void push(T value) {
        Node<T> *nodeToAdd = new Node<T>(value);
        storage.prepend(nodeToAdd);
    }

    T pop() {
        if(isEmpty()) {
            throw std::logic_error("No peek found. Stack is empty");
        }

        Node<T> *lastElement = storage.getHead();
        T lastElementValue = lastElement->data;
        
        storage.deleteNode(lastElement);

        return lastElementValue;
    }

    T peek() {
        if(isEmpty()) {
            throw std::logic_error("No peek found. Stack is empty");
        }
        
        return storage.getHead()->data;
    }

    bool isEmpty() {
        return storage.isEmpty();
    }
        
    void print()
    {
        Node<T> *currentHead = storage.getHead();
        while (currentHead != nullptr)
        {
            printf("------\n| %d  |\n", currentHead->data);
            currentHead = currentHead->nextNode;
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