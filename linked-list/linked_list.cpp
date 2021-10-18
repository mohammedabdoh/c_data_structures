#include <iostream>

class Node
{
public:
    int data;
    Node *nextNode;
        
    Node(int value) {
        data = value;
        nextNode = NULL;
    }
};

class LinkedList
{
public:
    Node *head;
        
    LinkedList()
    {
        head = NULL;
    }
        
    void prepend(Node *nodeToInsert)
    {
        nodeToInsert->nextNode = this->head;
        this->head = nodeToInsert;
    }
        
    void append(Node *nodeToInsert)
    {
        Node *currentNode = this->head;
        while(currentNode->nextNode != NULL) {
            currentNode = currentNode->nextNode;
        }
        currentNode->nextNode = nodeToInsert;
    }
        
    void insertAfterNode(Node *nodeToInsertAfter, Node *nodeToInsert)
    {
        nodeToInsert->nextNode = nodeToInsertAfter->nextNode;
        nodeToInsertAfter->nextNode = nodeToInsert;
    }
        
    void deleteNode(Node *nodeToDelete)
    {
        Node *currentNode = this->head;
        while(currentNode->nextNode != nodeToDelete) {
            currentNode = currentNode->nextNode;
        }
        currentNode->nextNode = nodeToDelete->nextNode;
    }
        
    Node *findNode(int value)
    {
        Node *currentNode = this->head;
        while(currentNode->nextNode != NULL) {
            if(currentNode->data == value) {
                return currentNode;
            }
            currentNode = currentNode->nextNode;
        }
        return NULL;
    }
        
    void print()
    {
        Node *currentNode = this->head;
        printf("head -> ");
        while(currentNode != NULL) {
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
    linkedList.insertAfterNode(linkedList.findNode(3), new Node(102));
    linkedList.deleteNode(linkedList.findNode(1));
    
    linkedList.print();
    
    return 0;
}