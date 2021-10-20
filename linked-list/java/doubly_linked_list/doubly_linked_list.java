class DoublyLinkedList<T>
{
    DoublyNode<T> head;
    int size;

    DoublyLinkedList() {
        head = null;
        size = 0;
    }

    void prepend(DoublyNode<T> nodeToPrepend)
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

    void append(DoublyNode<T> nodeToAppend)
    {
        if(isEmpty()) {
            prepend(nodeToAppend);
            return;
        }
        
        DoublyNode<T> currentNode = head;
        
        while(currentNode.nextNode != null) {
            currentNode = currentNode.nextNode;
        }

        currentNode.nextNode = nodeToAppend;
        nodeToAppend.prevNode = currentNode;
        nodeToAppend.nextNode = null;

        size++;
    }

    void insertAfterNode(DoublyNode<T> nodeToInsertAfter, DoublyNode<T> nodeToInsert)
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

    void deleteNode(DoublyNode<T> nodeToDelete)
    {
        if(isEmpty()) {
            return;
        }

        DoublyNode<T> currentNode = head;

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

    DoublyNode<T> findNode(T value)
    {
        if(isEmpty()) {
            return null;
        }

        DoublyNode<T> currentNode = head;
        
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
        DoublyNode<T> currentNode = head;
        
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

class DoublyLinkedListMain
{
    public static void main(String[] args) {

        DoublyLinkedList<Integer> linkedList = new DoublyLinkedList<Integer>();
        
        for (int i = 0; i < 5; i++) {
            linkedList.prepend(new DoublyNode<Integer>(i+1));
        }

        linkedList.prepend(new DoublyNode<Integer>(100));
        linkedList.append(new DoublyNode<Integer>(78));
        linkedList.insertAfterNode(linkedList.findNode(3), new DoublyNode<Integer>(102));
        linkedList.insertAfterNode(linkedList.findNode(1), new DoublyNode<Integer>(11));
        linkedList.insertAfterNode(linkedList.findNode(78), new DoublyNode<Integer>(101));
        linkedList.deleteNode(linkedList.findNode(1));
        linkedList.deleteNode(linkedList.findNode(11));
        linkedList.deleteNode(linkedList.findNode(101));

        linkedList.print();
    }
}