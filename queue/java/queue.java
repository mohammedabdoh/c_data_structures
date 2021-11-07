class Queue<T> {
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

class QueueWithList {
    public static void main(String[] args) {
        
        Queue<Integer> queue = new Queue<Integer>();
        
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
    }
}
