package queue.java;

public class QueueWithList {
    public static void run() {
        
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
