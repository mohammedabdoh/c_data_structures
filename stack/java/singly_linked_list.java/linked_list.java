class LinkedListForStack<T>
{
    NodeForStack<T> head;
    int size;

    LinkedListForStack() {
        head = null;
        size = 0;
    }

    void prepend(NodeForStack<T> nodeToPrepend)
    {
        nodeToPrepend.nextNode = head;
        
        head = nodeToPrepend;
        
        size++;
    }

    void append(NodeForStack<T> nodeToAppend)
    {
        if(isEmpty()) {
            prepend(nodeToAppend);
            return;
        }
        
        NodeForStack<T> currentNode = head;
        
        while(currentNode.nextNode != null) {
            currentNode = currentNode.nextNode;
        }

        currentNode.nextNode = nodeToAppend;

        size++;
    }

    void insertAfterNode(NodeForStack<T> nodeToInsertAfter, NodeForStack<T> nodeToInsert)
    {
        if(isEmpty()) {
            prepend(nodeToInsert);
            return;
        }

        nodeToInsert.nextNode = nodeToInsertAfter.nextNode;
        nodeToInsertAfter.nextNode = nodeToInsert;
        size++;
    }

    void deleteNode(NodeForStack<T> nodeToDelete)
    {
        if(isEmpty()) {
            return;
        }

        NodeForStack<T> currentNode = head;

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

    NodeForStack<T> findNode(T value)
    {
        if(isEmpty()) {
            return null;
        }

        NodeForStack<T> currentNode = head;
        
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

    NodeForStack<T> getHead() {
        return head;
    }

    void print()
    {
        NodeForStack<T> currentNode = head;
        
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
