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
private:
    Node<T> *head;
    int size;

public:
    LinkedList()
    {
        head = nullptr;
        size = 0;
    }
        
    void prepend(Node<T> *nodeToInsert)
    {
        nodeToInsert->nextNode = this->head;
        this->head = nodeToInsert;
        size++;
    }
        
    void append(Node<T> *nodeToInsert)
    {
        if(isEmpty()) {
            prepend(nodeToInsert);
            return;
        }

        Node<T> *currentNode = this->head;
        while(currentNode->nextNode != nullptr) {
            currentNode = currentNode->nextNode;
        }
        currentNode->nextNode = nodeToInsert;
        size++;
    }
        
    void insertAfterNode(Node<T> *nodeToInsertAfter, Node<T> *nodeToInsert)
    {
        if(isEmpty()) {
            prepend(nodeToInsert);
            return;
        }

        nodeToInsert->nextNode = nodeToInsertAfter->nextNode;
        nodeToInsertAfter->nextNode = nodeToInsert;
        size++;
    }
        
    void deleteNode(Node<T> *nodeToDelete)
    {
        if(isEmpty()) {
            return;
        }

        Node<T> *currentNode = head;

        if(currentNode == nodeToDelete) {
            head = head->nextNode;
            return;
        }

        while(currentNode->nextNode != nodeToDelete) {
            currentNode = currentNode->nextNode;
        }
        currentNode->nextNode = nodeToDelete->nextNode;
        size--;
    }
        
    Node<T> *findNode(T value)
    {
        if(isEmpty()) {
            return nullptr;
        }

        Node<T> *currentNode = this->head;
        while(currentNode->nextNode != nullptr) {
            if(currentNode->data == value) {
                return currentNode;
            }
            currentNode = currentNode->nextNode;
        }
        return nullptr;
    }

    bool isEmpty() {
        return this->head == nullptr;
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

    int getSize()
    {
        return size;
    }
};

int main() {

    // Linked list of ints
    LinkedList<int> linkedList;
    
    for ( int i = 0; i < 5; i++ ) {
        linkedList.prepend(new Node<int>(i+1));
    }
    
    linkedList.append(new Node<int>(100));
    linkedList.insertAfterNode(linkedList.findNode(3), new Node<int>(102));
    linkedList.deleteNode(linkedList.findNode(1));

    cout << "Size is: " << linkedList.getSize() << "\n";
    linkedList.print();


    // Linked list of chars
    LinkedList<char> charLinkedList;

    charLinkedList.prepend(new Node<char>('a'));
    charLinkedList.prepend(new Node<char>('b'));
    charLinkedList.prepend(new Node<char>('c'));
    charLinkedList.prepend(new Node<char>('d'));

    charLinkedList.append(new Node<char>('e'));
    charLinkedList.insertAfterNode(charLinkedList.findNode('b'), new Node<char>('f'));
    charLinkedList.deleteNode(charLinkedList.findNode('a'));

    cout << "Size is: " << charLinkedList.getSize() << "\n";
    charLinkedList.print();

    // Empty linked list
    LinkedList<int> emptyLinkedList;

    if(emptyLinkedList.isEmpty()) {
        cout << "List is empty\n";
    }

    return 0;
}