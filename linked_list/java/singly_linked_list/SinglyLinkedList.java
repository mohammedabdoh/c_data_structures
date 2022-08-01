package linked_list.java.singly_linked_list;

public class SinglyLinkedList<T>
{
    public SinglyLinkedListNode<T> head;
    public int size;

    public SinglyLinkedList() {
        head = null;
        size = 0;
    }

    public void prepend(SinglyLinkedListNode<T> nodeToPrepend)
    {
        nodeToPrepend.nextNode = head;
        
        head = nodeToPrepend;
        
        size++;
    }

    public void append(SinglyLinkedListNode<T> nodeToAppend)
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

    public void insertAfterNode(SinglyLinkedListNode<T> nodeToInsertAfter, SinglyLinkedListNode<T> nodeToInsert)
    {
        if(isEmpty()) {
            prepend(nodeToInsert);
            return;
        }

        nodeToInsert.nextNode = nodeToInsertAfter.nextNode;
        nodeToInsertAfter.nextNode = nodeToInsert;
        size++;
    }

    public void deleteNode(SinglyLinkedListNode<T> nodeToDelete)
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

    public SinglyLinkedListNode<T> findNode(T value)
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

    public boolean isEmpty()
    {
        return head == null;
    }

    public void print()
    {
        SinglyLinkedListNode<T> currentNode = head;
        
        System.out.print("HEAD -> ");
        
        while(currentNode != null) {
            System.out.print(currentNode.data + " -> ");
            currentNode = currentNode.nextNode;
        }
        
        System.out.print("NULL\n");
    }

    public int getSize() {
        return size;
    }
}
