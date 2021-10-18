#include <iostream>

class Node
{
public:
    int data;
    Node *nextNode;
        
    explicit Node(int value) {
        data = value;
        nextNode = nullptr;
    }
};

class LinkedList
{
public:
    Node *head;
        
    LinkedList()
    {
        head = nullptr;
    }
        
    void prepend(Node *nodeToInsert)
    {
        nodeToInsert->nextNode = this->head;
        this->head = nodeToInsert;
    }
        
    void append(Node *nodeToInsert) const
    {
        Node *currentNode = this->head;
        while(currentNode->nextNode != nullptr) {
            currentNode = currentNode->nextNode;
        }
        currentNode->nextNode = nodeToInsert;
    }
        
    static void insertAfterNode(Node *nodeToInsertAfter, Node *nodeToInsert)
    {
        nodeToInsert->nextNode = nodeToInsertAfter->nextNode;
        nodeToInsertAfter->nextNode = nodeToInsert;
    }
        
    void deleteNode(Node *nodeToDelete) const
    {
        Node *currentNode = this->head;
        while(currentNode->nextNode != nodeToDelete) {
            currentNode = currentNode->nextNode;
        }
        currentNode->nextNode = nodeToDelete->nextNode;
    }
        
    Node *findNode(int value) const
    {
        Node *currentNode = this->head;
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
        Node *currentNode = this->head;
        printf("head -> ");
        while(currentNode != nullptr) {
            printf("%d -> ", currentNode->data);
            currentNode = currentNode->nextNode;
        }
        printf("NULL\n");
    }
};

int main() {
    LinkedList linkedList;
    
    for ( int i = 0; i < 5; i++ ) {
        linkedList.prepend(new Node(i+1));
    }
    
    linkedList.append(new Node(100));
    LinkedList::insertAfterNode(linkedList.findNode(3), new Node(102));
    linkedList.deleteNode(linkedList.findNode(1));
    
    linkedList.print();
    
    return 0;
}