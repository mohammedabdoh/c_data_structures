#include <iostream>
#include "doubly_linked_list.hh"

using std::cout;

template<class T>
class Queue
{
private:
    DoublyLinkedList<T> storage;

public:
    Queue(int queueSize) {
        storage = DoublyLinkedList<T>();
    }

    void enqueue(T val) {
        Node<T> *nodeToEnqueue = new Node<T>(val);
        storage.append(nodeToEnqueue);
    }

    T dequeue() {
        Node<T> *nodeToDequeue = storage.getHead();
        T valueToReturn = nodeToDequeue->data;
        storage.deleteNode(nodeToDequeue);
        return valueToReturn;
    }

    void print() {
        Node<T> *currentHead = storage.getHead();

        while(currentHead != NULL) {
            cout << currentHead->data << " ";
            currentHead = currentHead->nextNode;
        }

        cout << "\n";
    }
};

int main() {

    Queue<int> queue(6);

    try {
        
        queue.enqueue(11);
        queue.enqueue(6);
        queue.enqueue(5);
        queue.enqueue(20);
        queue.enqueue(11);
        queue.dequeue();
        queue.dequeue();
        queue.dequeue();
        queue.enqueue(23);
        queue.enqueue(7);
        queue.enqueue(65);
        queue.enqueue(9);
        queue.dequeue();
        queue.enqueue(45);
        queue.dequeue();
        queue.dequeue();
        queue.enqueue(31);
        queue.dequeue();
        queue.dequeue();
        queue.dequeue();
        queue.dequeue();
        queue.dequeue();
        queue.enqueue(20);
        queue.enqueue(43);

        queue.print();
    } catch(const std::exception& e) {
        cout << e.what() << "\n";
    }

    return 0;
}