class DoublyNode<T>
{
    T data;
    DoublyNode<T> nextNode;
    DoublyNode<T> prevNode;
    
    DoublyNode(T value) {
        data = value;
        nextNode = null;
        prevNode = null;
    }
}