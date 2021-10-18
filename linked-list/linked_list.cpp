#include <iostream>

using std::cout;

template<class T>
class Node
{
public:
    T data;
    Node *nextNode;
        
    explicit Node(T value) {
        data = value;
        nextNode = nullptr;
    }
};

template<class T>
class LinkedList
{
public:
    Node<T> *head;
        
    LinkedList()
    {
        head = nullptr;
    }
        
    void prepend(Node<T> *nodeToInsert)
    {
        nodeToInsert->nextNode = this->head;
        this->head = nodeToInsert;
    }
        
    void append(Node<T> *nodeToInsert) const
    {
        Node<T> *currentNode = this->head;
        while(currentNode->nextNode != nullptr) {
            currentNode = currentNode->nextNode;
        }
        currentNode->nextNode = nodeToInsert;
    }
        
    static void insertAfterNode(Node<T> *nodeToInsertAfter, Node<T> *nodeToInsert)
    {
        nodeToInsert->nextNode = nodeToInsertAfter->nextNode;
        nodeToInsertAfter->nextNode = nodeToInsert;
    }
        
    void deleteNode(Node<T> *nodeToDelete) const
    {
        Node<T> *currentNode = this->head;
        while(currentNode->nextNode != nodeToDelete) {
            currentNode = currentNode->nextNode;
        }
        currentNode->nextNode = nodeToDelete->nextNode;
    }
        
    Node<T> *findNode(T value) const
    {
        Node<T> *currentNode = this->head;
        while(currentNode->nextNode != nullptr) {
            if(currentNode->data == value) {
                return currentNode;
            }
            currentNode = currentNode->nextNode;
        }
        return nullptr;
    }
        
    void print() const
    {
        Node<T> *currentNode = this->head;
        cout << "head -> ";
        while(currentNode != nullptr) {
            cout << currentNode->data << " -> ";
            currentNode = currentNode->nextNode;
        }
        cout << "NULL\n";
    }
};

int main() {

    // Linked list of ints
    LinkedList<int> linkedList;
    
    for ( int i = 0; i < 5; i++ ) {
        linkedList.prepend(new Node<int>(i+1));
    }
    
    linkedList.append(new Node<int>(100));
    LinkedList<int>::insertAfterNode(linkedList.findNode(3), new Node<int>(102));
    linkedList.deleteNode(linkedList.findNode(1));
    
    linkedList.print();


    // Linked list of chars
    LinkedList<char> charLinkedList;

    charLinkedList.prepend(new Node<char>('a'));
    charLinkedList.prepend(new Node<char>('b'));
    charLinkedList.prepend(new Node<char>('c'));
    charLinkedList.prepend(new Node<char>('d'));

    charLinkedList.append(new Node<char>('e'));
    LinkedList<char>::insertAfterNode(charLinkedList.findNode('b'), new Node<char>('f'));
    charLinkedList.deleteNode(charLinkedList.findNode('a'));

    charLinkedList.print();
    
    return 0;
}