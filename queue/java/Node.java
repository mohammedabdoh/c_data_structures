package queue.java;

public class Node<T>
{
    T data;
    Node<T> nextNode;
    Node<T> prevNode;
    
    Node(T value) {
        data = value;
        nextNode = null;
        prevNode = null;
    }
}