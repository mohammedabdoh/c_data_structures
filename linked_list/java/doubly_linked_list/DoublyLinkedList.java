package linked_list.java.doubly_linked_list;

public class DoublyLinkedList<T>
{
    public DoublyLinkedListNode<T> head;
    public int size;

    public DoublyLinkedList() {
        head = null;
        size = 0;
    }

    public void prepend(DoublyLinkedListNode<T> nodeToPrepend)
    {
        if(isEmpty()) {
            head = nodeToPrepend;
            size++;
            return;
        }

        nodeToPrepend.prevNode = null;
        nodeToPrepend.nextNode = head;
        head.prevNode = nodeToPrepend;
        
        head = nodeToPrepend;
        
        size++;
    }

    public void append(DoublyLinkedListNode<T> nodeToAppend)
    {
        if(isEmpty()) {
            prepend(nodeToAppend);
            return;
        }
        
        DoublyLinkedListNode<T> currentNode = head;
        
        while(currentNode.nextNode != null) {
            currentNode = currentNode.nextNode;
        }

        currentNode.nextNode = nodeToAppend;
        nodeToAppend.prevNode = currentNode;
        nodeToAppend.nextNode = null;

        size++;
    }

    public void insertAfterNode(DoublyLinkedListNode<T> nodeToInsertAfter, DoublyLinkedListNode<T> nodeToInsert)
    {
        if(isEmpty()) {
            prepend(nodeToInsert);
            return;
        }

        if(nodeToInsertAfter.prevNode == null) {
            prepend(nodeToInsert);
            return;
        }

        if(nodeToInsertAfter.nextNode == null) {
            append(nodeToInsert);
            return;
        }

        nodeToInsert.prevNode = nodeToInsertAfter;
        nodeToInsert.nextNode = nodeToInsertAfter.nextNode;
        nodeToInsertAfter.nextNode.prevNode = nodeToInsert;
        nodeToInsertAfter.nextNode = nodeToInsert;

        size++;
    }

    public void deleteNode(DoublyLinkedListNode<T> nodeToDelete)
    {
        if(isEmpty()) {
            return;
        }

        DoublyLinkedListNode<T> currentNode = head;

        if(currentNode == nodeToDelete) {
            head = head.nextNode;
            head.prevNode = null;
            size--;
            return;
        }

        if(nodeToDelete.nextNode == null) {
            nodeToDelete.prevNode.nextNode = null;
            size--;
            return;
        }

        while(currentNode.nextNode != nodeToDelete) {
            currentNode = currentNode.nextNode;
        }
        
        currentNode.nextNode = nodeToDelete.nextNode;
        nodeToDelete.nextNode.prevNode = currentNode;

        size--;
    }

    public DoublyLinkedListNode<T> findNode(T value)
    {
        if(isEmpty()) {
            return null;
        }

        DoublyLinkedListNode<T> currentNode = head;
        
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
        DoublyLinkedListNode<T> currentNode = head;
        
        System.out.printf("Size is: %d\n", size);

        while(currentNode != null) {
            System.out.print(currentNode.data + " -> ");
            if(currentNode.nextNode == null) {
                break;
            }
            currentNode = currentNode.nextNode;
        }
        
        System.out.println("NULL");

        while (currentNode != null) {
            System.out.print(currentNode.data + " -> ");
            currentNode = currentNode.prevNode;
        }

        System.out.println("NULL\n=======");
    }

    public int getSize() {
        return size;
    }
}