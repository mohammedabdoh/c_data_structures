package queue.java;

public class DoublyLinkedList<T>
{
    Node<T> head;
    Node<T> tail;
    int size;

    DoublyLinkedList() {
        head = null;
        tail = null;
        size = 0;
    }

    void prepend(Node<T> nodeToPrepend)
    {
        if(isEmpty()) {
            head = nodeToPrepend;
            tail = nodeToPrepend;
            size++;
            return;
        }

        nodeToPrepend.prevNode = null;
        nodeToPrepend.nextNode = head;
        head.prevNode = nodeToPrepend;
        
        head = nodeToPrepend;
        
        size++;
    }

    void append(Node<T> nodeToAppend)
    {
        if(isEmpty()) {
            prepend(nodeToAppend);
            return;
        }
        
        Node<T> currentNode = tail;
        currentNode.nextNode = nodeToAppend;
        nodeToAppend.prevNode = currentNode;
        nodeToAppend.nextNode = null;
        tail = nodeToAppend;

        size++;
    }

    void insertAfterNode(Node<T> nodeToInsertAfter, Node<T> nodeToInsert)
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

    void deleteNode(Node<T> nodeToDelete)
    {
        if(isEmpty()) {
            return;
        }

        Node<T> currentNode = head;

        if(currentNode == nodeToDelete) {
            
            if(currentNode.nextNode != null) {
                head = head.nextNode;
                head.prevNode = null;
            } else {
                head = null;
                tail = null;
            }
            
            if(isEmpty()) {
                tail = null;
            }
            size--;
            return;
        }

        if(nodeToDelete.nextNode == null) {
            nodeToDelete.prevNode.nextNode = null;
            if(isEmpty()) {
                head = null;
            }
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

    Node<T> findNode(T value)
    {
        if(isEmpty()) {
            return null;
        }

        Node<T> currentNode = head;
        
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
        Node<T> currentNode = head;
        
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

    int getSize() {
        return size;
    }
}
