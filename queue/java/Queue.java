package queue.java;

public class Queue<T> {
    private DoublyLinkedList<T> storage;

    Queue() {
        storage = new DoublyLinkedList<T>();
    }

    void enqueue(T val) {
        Node<T> nodeToEnqueue = new Node<T>(val);
        storage.append(nodeToEnqueue);
    }

    T dequeue() {
        Node<T> nodeToDequeue = storage.head;
        T valueToDequeue = nodeToDequeue.data;
        storage.deleteNode(nodeToDequeue);
        return valueToDequeue;
    }

    void print() {
        Node<T> currentHead = storage.head;

        while(currentHead != null) {
            System.out.print(currentHead.data + " ");
            currentHead = currentHead.nextNode;
        }

        System.out.print("\n");
    }
}
