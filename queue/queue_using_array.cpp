#include <iostream>
#include <vector>

using std::cout;
using std::vector;

template<class T>
class Queue
{
private:
    int front;
    int back;
    int size;
    int length;
    vector<T> storage;

public:
    Queue(int queueSize) {
        front = -1;
        back = -1;
        length = 0;
        size = queueSize;
        storage = vector<T>(size);
    }

    void enqueue(T val) {
        // If the queue is full we cannot add more elements
        if(isFull()) {
            return;
        }

        // if the queue is empty then front and back should be updated
        // to the same index in the array
        if(isEmpty()) {
            // make sure to reset again
            back = -1;
            front = -1;
            
            back++;
            front++;
        } else {
            // if the next back is out of the array range
            // we start at the beginning by restting it
            if(back + 1 == size) {
                back = -1;
            }
            back++;
        }

        storage[back] = val;
        length++;
    }

    T dequeue() {
        // If the queue is empty we cannot dequeue
        if(isEmpty()) {
            throw std::logic_error("Queue is empty");
        }

        T elementToDequeue = storage[front];
        storage[front] = T();

        // If this is the end of the queue
        if(front + 1 == size) {
            // we reset the front
            front = -1;
        }
        front++;
        length--;

        return elementToDequeue;
    }

    bool isFull() {
        return length == size;
    }

    bool isEmpty() {
        return length == 0;
    }

    int getFront() {
        return front;
    }

    int getBack() {
        return back;
    }

    int getSize() {
        return size;
    }

    int getLength() {
        return length;
    }

    void print() {
        for(int i = 0; i < size; i++) {
            cout << storage[i] << " ";
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

        printf("length: %d, front: %d, back: %d\n", queue.getLength(), queue.getFront(), queue.getBack());
        queue.print();
    } catch(const std::exception& e) {
        cout << e.what() << "\n";
    }

    return 0;
}