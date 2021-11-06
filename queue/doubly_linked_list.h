#include <stdlib.h>
#include <stdio.h>

struct node {
    int value;
    struct node *nextNode;
    struct node *prevNode;
};

typedef struct node node_t;

/**
 * @brief prints the linked list
 * 
 * @param head the head of the list
 * @param message a message to show for debugging
 */
void print_nodes(node_t *head, char message[]) {
    node_t *temporary = head;

    printf("%s\n", message);

    while (temporary != NULL) {
        printf("%d -> ", temporary->value);
        if(temporary->nextNode == NULL) {
            break;
        }
        temporary = temporary->nextNode;
    }
    printf("NULL\n");

    while (temporary != NULL) {
        printf("%d -> ", temporary->value);
        temporary = temporary->prevNode;
    }
    printf("NULL\n=======\n");
}

/**
 * @brief Check whether the list is empty or not
 * 
 * @param head the head of the list
 * @return int 
 */
int isEmpty(node_t *head) {
    // If the head is null them the list is empty
    return head == NULL ? 1 : 0;
}

/**
 * @brief Create a new node object
 * 
 * @param value 
 * @return node_t* 
 */
node_t *create_new_node(int value) {
    // We reserve a memory in the heap
    node_t *node = malloc(sizeof(node_t));
    
    node->value = value;
    node->nextNode = NULL;
    node->prevNode = NULL;
    
    return node;
}

/**
 * @brief Inserts a node at the head of the list
 * 
 * @param pointerToHead 
 * @param node_to_insert 
 */
void insert_node_at_head(node_t **pointerToHead, node_t **tail, node_t *node_to_insert) {
    // When inserting at head and the list is empty
    // we initialize it
    if(1 == isEmpty(*pointerToHead)) {
        *pointerToHead = node_to_insert;
        *tail = node_to_insert;
        return;
    }
    
    // Otherwise we initialize the current head node's prev node
    // to be the new node
    (*pointerToHead)->prevNode = node_to_insert;

    // Then we set the new node's next node to be the current head node
    node_to_insert->nextNode = *pointerToHead;

    // Then we set the head to the new node
    *pointerToHead = node_to_insert;
}

/**
 * @brief Inserts a node at the tail of the list
 * 
 * @param head 
 * @param node_to_insert 
 */
void insert_node_at_tail(node_t **head, node_t **tail, node_t *node_to_insert) {
    // If the list is empty we initialize a new list with a head
    if(1 == isEmpty(*tail)) {
        insert_node_at_head(head, tail, node_to_insert);
        return;
    }

    // Otherwise we iterate over to the end of the list 
    // and add the new node
    node_t *tmp = *tail;
    
    // We set the new node's prev node to the current tail
    node_to_insert->prevNode = tmp;

    // We ensure the new node's next node is NULL
    node_to_insert->nextNode = NULL;

    // we set the current tail's next node to the new node
    tmp->nextNode = node_to_insert;

    // We set the tail to the last node (tmp)
    *tail = node_to_insert;
}

/**
 * @brief Searches the list for a node with a given value
 * 
 * @param head 
 * @param value 
 * @return node_t* 
 */
node_t *find_node(node_t *head, int value) {
    // If the list is empty we return a NULL node
    if(1 == isEmpty(head)) {
        return NULL;
    }

    node_t *tmp = head;
    while(tmp != NULL) {
        if(tmp->value == value) {
            return tmp;
        }
        tmp = tmp->nextNode;
    }
    return NULL;
}

/**
 * @brief inserts a node after a node, at the head or at the tail
 * 
 * @param node_to_insert_after 
 * @param node_to_insert 
 */
void insert_node_after_node(node_t **node_to_insert_after, node_t *node_to_insert, node_t **tail) {
    // If the list is empty we initialize it with a head
    // or, if this is the node_to_insert_after is the head
    if(1 == isEmpty(*node_to_insert_after) || (*node_to_insert_after)->prevNode == NULL) {
        insert_node_at_head(node_to_insert_after, tail, node_to_insert);
        return;
    }

    // If this is the node_to_insert_after is the tail
    if((*node_to_insert_after)->nextNode == NULL) {
        (*node_to_insert_after)->nextNode = node_to_insert;
        node_to_insert->prevNode = *node_to_insert_after;
        node_to_insert->nextNode = NULL;
        *tail = node_to_insert;
        return;
    }
    
    // Otherwise, we set the new node's next node to the node_to_insert_after's
    // next node
    node_to_insert->nextNode = (*node_to_insert_after)->nextNode;

    // Then we set the prev node of the next node of the node_to_insert_after
    // to point to the node_to_insert
    (*node_to_insert_after)->nextNode->prevNode = node_to_insert;

    // The we set the new node's prev node to be the note_to_insert_after
    node_to_insert->prevNode = *node_to_insert_after;

    // Finall we set the node_to_insert_after's next node to the new node
    (*node_to_insert_after)->nextNode = node_to_insert;
}

/**
 * @brief Deletes a node at nth poistion, head or tail of the list
 * 
 * @param head 
 * @param node_to_delete 
 */
void delete_node(node_t **head, node_t **tail, node_t *node_to_delete) {
    // If the list is empty then we need to do nothing
    if(1 == isEmpty(*head)) {
        return;
    }

    // If node_to_delete is the head
    if(node_to_delete->prevNode == NULL) {
        // If there is more nodes
        if(node_to_delete->nextNode != NULL) {
            node_to_delete->nextNode->prevNode = NULL;
            *head = node_to_delete->nextNode;
        } else {
            *head = NULL;
            *tail = NULL;
        }
        
        if(isEmpty(*head)) {
            free(*tail);
        }
        return;
    }

    // If node_to_delete is the tail
    if(node_to_delete->nextNode == NULL) {
        node_to_delete->prevNode->nextNode = NULL;
        *tail = node_to_delete->prevNode;
        free(node_to_delete);
        if(isEmpty(*tail)) {
            free(*tail);
        }
        return;
    }

    // Otherwise, we remove the node
    node_t *tmp = *head;

    // We travserse the whole list until we find the node to delete
    while(tmp->nextNode != node_to_delete) {
        tmp = tmp->nextNode;
    }

    // We set the node_to_delete's next node prev node to tmp
    node_to_delete->nextNode->prevNode = tmp;

    // We set the next node of the node before the one we need to delete
    // to the node_to_delete's next node
    tmp->nextNode = node_to_delete->nextNode;

    // free up the object from memory
    free(node_to_delete);
}