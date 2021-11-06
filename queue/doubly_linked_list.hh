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
    Node<T> *tail;
    int size;

public:
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
        
    void prepend(Node<T> *nodeToInsert)
    {
        // If the list is empty
        if(this->head == nullptr) {
            this->head = nodeToInsert;
            this->tail = nodeToInsert;
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

        Node<T> *currentNode = this->tail;
        nodeToInsert->prevNode = currentNode;
        nodeToInsert->nextNode = nullptr;
        currentNode->nextNode = nodeToInsert;
        this->tail = nodeToInsert;
        
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
            if(head->nextNode != nullptr) {
                head = head->nextNode;
                head->prevNode = nullptr;
            } else {
                head = nullptr;
                tail = nullptr;
            }
            
            if(isEmpty()) {
                delete this->tail;
            }
            size--;
            return;
        }

        if(nodeToDelete->nextNode == nullptr) {
            nodeToDelete->prevNode->nextNode = nullptr;
            delete nodeToDelete;
            if(isEmpty()) {
                delete this->head;
            }
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

    Node<T> *getHead() {
        return head;
    }
};
