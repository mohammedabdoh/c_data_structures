class LinkedList<T>
{
    Node<T> head;
    int size;

    LinkedList() {
        head = null;
        size = 0;
    }

    void prepend(Node<T> nodeToPrepend)
    {
        nodeToPrepend.nextNode = head;
        
        head = nodeToPrepend;
        
        size++;
    }

    void append(Node<T> nodeToAppend)
    {
        if(isEmpty()) {
            prepend(nodeToAppend);
            return;
        }
        
        Node<T> currentNode = head;
        
        while(currentNode.nextNode != null) {
            currentNode = currentNode.nextNode;
        }

        currentNode.nextNode = nodeToAppend;

        size++;
    }

    void insertAfterNode(Node<T> nodeToInsertAfter, Node<T> nodeToInsert)
    {
        if(isEmpty()) {
            prepend(nodeToInsert);
            return;
        }

        nodeToInsert.nextNode = nodeToInsertAfter.nextNode;
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
            head = head.nextNode;
            return;
        }

        while(currentNode.nextNode != nodeToDelete) {
            currentNode = currentNode.nextNode;
        }
        currentNode.nextNode = nodeToDelete.nextNode;
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

class Main
{
    public static void main(String[] args) {

        LinkedList<Integer> linkedList = new LinkedList<Integer>();
        
        for (int i = 0; i < 5; i++) {
            linkedList.prepend(new Node<Integer>(i+1));
        }

        linkedList.prepend(new Node<Integer>(100));
        linkedList.append(new Node<Integer>(78));
        linkedList.insertAfterNode(linkedList.findNode(3), new Node<Integer>(102));
        linkedList.insertAfterNode(linkedList.findNode(1), new Node<Integer>(11));
        linkedList.insertAfterNode(linkedList.findNode(78), new Node<Integer>(101));
        linkedList.deleteNode(linkedList.findNode(1));
        linkedList.deleteNode(linkedList.findNode(11));
        linkedList.deleteNode(linkedList.findNode(101));

        System.out.println("Size is: " + linkedList.getSize() + "\n");
        linkedList.print();
    }
}