package linked_list.java.doubly_linked_list;

public class DoublyLinkedListNode<T>
{
    public T data;
    public DoublyLinkedListNode<T> nextNode;
    public DoublyLinkedListNode<T> prevNode;
    
    public DoublyLinkedListNode(T value) {
        data = value;
        nextNode = null;
        prevNode = null;
    }
}