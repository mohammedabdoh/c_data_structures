package queue.java;

import java.util.ArrayList;

public class QueueUsingArray<T> {
    private int front;
    private int back;
    private int size;
    private int length;
    private ArrayList<T> storage;

    QueueUsingArray(int queueSize) {
        front = -1;
        back = -1;
        size = queueSize;
        length = 0;
        storage = new ArrayList<T>();
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

        storage.add(back, val);
        length++;
    }

    T dequeue() {
        // If the queue is empty we cannot dequeue
        if(isEmpty()) {
            return null;
        }

        T elementToDequeue = storage.get(front);
        storage.add(front, null);

        // If this is the end of the queue
        if(front + 1 == size) {
            // we reset the front
            front = -1;
        }
        front++;
        length--;

        return elementToDequeue;
    }

    boolean isFull() {
        return length == size;
    }

    boolean isEmpty() {
        return length == 0;
    }

    void print() {
        for(int i = 0; i < size; i++) {
            System.out.print(storage.get(i) + " ");
        }

        System.out.print("\n");
    }
}