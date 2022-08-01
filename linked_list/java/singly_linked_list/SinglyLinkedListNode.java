package linked_list.java.singly_linked_list;

public class SinglyLinkedListNode<T>
{
    public T data;
    public SinglyLinkedListNode<T> nextNode;
    
    public SinglyLinkedListNode(T value) {
        data = value;
    }
}