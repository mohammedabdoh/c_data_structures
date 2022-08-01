package linked_list.java.singly_linked_list;

public class SinglyLinkedListMain
{
    public static void main(String[] args) {

        SinglyLinkedList<Integer> linkedList = new SinglyLinkedList<Integer>();
        
        for (int i = 0; i < 5; i++) {
            linkedList.prepend(new SinglyLinkedListNode<Integer>(i+1));
        }

        linkedList.prepend(new SinglyLinkedListNode<Integer>(100));
        linkedList.append(new SinglyLinkedListNode<Integer>(78));
        linkedList.insertAfterNode(linkedList.findNode(3), new SinglyLinkedListNode<Integer>(102));
        linkedList.insertAfterNode(linkedList.findNode(1), new SinglyLinkedListNode<Integer>(11));
        linkedList.insertAfterNode(linkedList.findNode(78), new SinglyLinkedListNode<Integer>(101));
        linkedList.deleteNode(linkedList.findNode(1));
        linkedList.deleteNode(linkedList.findNode(11));
        linkedList.deleteNode(linkedList.findNode(101));

        System.out.println("Size is: " + linkedList.getSize() + "\n");
        linkedList.print();
    }
}