package linked_list.java.singly_linked_list;

public class SinglyLinkedListNode<T>
{
    T data;
    SinglyLinkedListNode<T> nextNode;
    
    SinglyLinkedListNode(T value) {
        data = value;
    }
}