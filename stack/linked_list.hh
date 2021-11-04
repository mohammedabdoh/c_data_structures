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

    Node<T> *getHead()
    {
        return head;
    }
};
