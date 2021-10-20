#include <iostream>

using std::cout;

template<class T>
class Node
{
public:
    T data;
    Node *nextNode;
    Node *prevNode;
        
    explicit Node(T value) {
        data = value;
        nextNode = nullptr;
        prevNode = nullptr;
    }
};

template<class T>
class DoublyLinkedList
{
private:
    Node<T> *head;
    int size;

public:
    DoublyLinkedList()
    {
        head = nullptr;
        size = 0;
    }
        
    void prepend(Node<T> *nodeToInsert)
    {
        // If the list is empty
        if(this->head == nullptr) {
            this->head = nodeToInsert;
            size++;
            return;
        }
        
        this->head->prevNode = nodeToInsert;
        nodeToInsert->nextNode = this->head;
        nodeToInsert->prevNode = nullptr;
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
        
        nodeToInsert->prevNode = currentNode;
        nodeToInsert->nextNode = nullptr;
        currentNode->nextNode = nodeToInsert;
        
        size++;
    }
        
    void insertAfterNode(Node<T> *nodeToInsertAfter, Node<T> *nodeToInsert)
    {
        if(isEmpty()) {
            prepend(nodeToInsert);
            return;
        }

        if(nodeToInsertAfter->prevNode == nullptr) {
            prepend(nodeToInsert);
            return;
        }

        if(nodeToInsertAfter->nextNode == nullptr) {
            append(nodeToInsert);
            return;
        }

        nodeToInsertAfter->nextNode->prevNode = nodeToInsert;
        nodeToInsert->nextNode = nodeToInsertAfter->nextNode;
        nodeToInsert->prevNode = nodeToInsertAfter;
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
            head->prevNode = nullptr;
            delete nodeToDelete;
            size--;
            return;
        }

        if(nodeToDelete->nextNode == nullptr) {
            nodeToDelete->prevNode->nextNode = nullptr;
            delete nodeToDelete;
            size--;
            return;
        }

        while(currentNode->nextNode != nodeToDelete) {
            currentNode = currentNode->nextNode;
        }
        
        currentNode->nextNode = nodeToDelete->nextNode;
        nodeToDelete->nextNode->prevNode = currentNode;
        
        delete nodeToDelete;
        
        size--;
    }
        
    Node<T> *findNode(T value)
    {
        if(isEmpty()) {
            return nullptr;
        }

        Node<T> *currentNode = this->head;
        while(currentNode != nullptr) {
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
        
    void print()
    {
        Node<T> *currentNode = this->head;

        cout << "Size is: " << size << "\n";

        while (currentNode != nullptr) {
            cout << currentNode->data << " -> ";
            if(currentNode->nextNode == nullptr) {
                break;
            }
            currentNode = currentNode->nextNode;
        }
        cout << "NULL\n";

        while (currentNode != NULL) {
            cout << currentNode->data << " -> ";
            currentNode = currentNode->prevNode;
        }
        cout << "NULL\n=======\n";
    }

    int getSize()
    {
        return size;
    }
};

int main() {

    // Linked list of ints
    DoublyLinkedList<int> linkedList;
    
    for ( int i = 0; i < 5; i++ ) {
        linkedList.append(new Node<int>(i+1));
    }
    
    cout << "Initializing the list\n";
    linkedList.print();

    cout << "Appending a new element\n";
    linkedList.append(new Node<int>(100));
    linkedList.print();

    cout << "Prepending a new element\n";
    linkedList.prepend(new Node<int>(120));
    linkedList.print();
    
    cout << "Inserting a new element after node with value 3\n";
    linkedList.insertAfterNode(linkedList.findNode(3), new Node<int>(87));
    linkedList.print();

    cout << "Inserting a new element at tail\n";
    linkedList.insertAfterNode(linkedList.findNode(100), new Node<int>(45));
    linkedList.print();

    cout << "Inserting a new element at head\n";
    linkedList.insertAfterNode(linkedList.findNode(120), new Node<int>(55));
    linkedList.print();
    
    cout << "Delete node with value 1\n";
    linkedList.deleteNode(linkedList.findNode(1));
    linkedList.print();

    cout << "Delete the tail\n";
    linkedList.deleteNode(linkedList.findNode(45));
    linkedList.print();

    cout << "Delete the head\n";
    linkedList.deleteNode(linkedList.findNode(55));
    linkedList.print();


    // Linked list of chars
    DoublyLinkedList<char> charLinkedList;

    charLinkedList.prepend(new Node<char>('a'));
    charLinkedList.prepend(new Node<char>('b'));
    charLinkedList.prepend(new Node<char>('c'));
    charLinkedList.prepend(new Node<char>('d'));
    charLinkedList.print();

    charLinkedList.append(new Node<char>('e'));
    charLinkedList.print();

    charLinkedList.insertAfterNode(charLinkedList.findNode('b'), new Node<char>('f'));
    charLinkedList.print();

    charLinkedList.deleteNode(charLinkedList.findNode('a'));
    charLinkedList.print();

    // Empty linked list
    DoublyLinkedList<int> emptyLinkedList;

    if(emptyLinkedList.isEmpty()) {
        cout << "List is empty\n";
    }

    return 0;
}