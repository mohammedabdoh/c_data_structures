package linked_list.java.singly_linked_list;

public class SinglyLinkedList<T>
{
    SinglyLinkedListNode<T> head;
    int size;

    SinglyLinkedList() {
        head = null;
        size = 0;
    }

    void prepend(SinglyLinkedListNode<T> nodeToPrepend)
    {
        nodeToPrepend.nextNode = head;
        
        head = nodeToPrepend;
        
        size++;
    }

    void append(SinglyLinkedListNode<T> nodeToAppend)
    {
        if(isEmpty()) {
            prepend(nodeToAppend);
            return;
        }
        
        SinglyLinkedListNode<T> currentNode = head;
        
        while(currentNode.nextNode != null) {
            currentNode = currentNode.nextNode;
        }

        currentNode.nextNode = nodeToAppend;

        size++;
    }

    void insertAfterNode(SinglyLinkedListNode<T> nodeToInsertAfter, SinglyLinkedListNode<T> nodeToInsert)
    {
        if(isEmpty()) {
            prepend(nodeToInsert);
            return;
        }

        nodeToInsert.nextNode = nodeToInsertAfter.nextNode;
        nodeToInsertAfter.nextNode = nodeToInsert;
        size++;
    }

    void deleteNode(SinglyLinkedListNode<T> nodeToDelete)
    {
        if(isEmpty()) {
            return;
        }

        SinglyLinkedListNode<T> currentNode = head;

        if(currentNode == nodeToDelete) {
            head = head.nextNode;
            return;
        }

        while(currentNode.nextNode != nodeToDelete) {
            currentNode = currentNode.nextNode;
        }
        currentNode.nextNode = nodeToDelete.nextNode;
        size--;
    }

    SinglyLinkedListNode<T> findNode(T value)
    {
        if(isEmpty()) {
            return null;
        }

        SinglyLinkedListNode<T> currentNode = head;
        
        while(currentNode != null) {
            if(currentNode.data == value) {
                return currentNode;
            }
            currentNode = currentNode.nextNode;
        }

        return null;
    }

    boolean isEmpty()
    {
        return head == null;
    }

    void print()
    {
        SinglyLinkedListNode<T> currentNode = head;
        
        System.out.print("HEAD -> ");
        
        while(currentNode != null) {
            System.out.print(currentNode.data + " -> ");
            currentNode = currentNode.nextNode;
        }
        
        System.out.print("NULL\n");
    }

    int getSize() {
        return size;
    }
}
