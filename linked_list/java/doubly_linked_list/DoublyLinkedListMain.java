package linked_list.java.doubly_linked_list;

public class DoublyLinkedListMain
{
    public static void run() {

        DoublyLinkedList<Integer> linkedList = new DoublyLinkedList<Integer>();
        
        for (int i = 0; i < 5; i++) {
            linkedList.prepend(new DoublyLinkedListNode<Integer>(i+1));
        }

        linkedList.prepend(new DoublyLinkedListNode<Integer>(100));
        linkedList.append(new DoublyLinkedListNode<Integer>(78));
        linkedList.insertAfterNode(linkedList.findNode(3), new DoublyLinkedListNode<Integer>(102));
        linkedList.insertAfterNode(linkedList.findNode(1), new DoublyLinkedListNode<Integer>(11));
        linkedList.insertAfterNode(linkedList.findNode(78), new DoublyLinkedListNode<Integer>(101));
        linkedList.deleteNode(linkedList.findNode(1));
        linkedList.deleteNode(linkedList.findNode(11));
        linkedList.deleteNode(linkedList.findNode(101));

        linkedList.print();
    }
}