#include <stdlib.h>
#include <stdio.h>

struct node {
    int value;
    struct node *nextNode;
};

typedef struct node node_t;

void print_nodes(node_t *head) {
    node_t *temporary = head;
    while (temporary != NULL) {
        printf("------\n| %d  |\n", temporary->value);
        temporary = temporary->nextNode;
    }
    printf("------\n");
}

int isEmpty(node_t *head) {
    return head == NULL ? 1 : 0;
}

node_t *create_new_node(int value) {
    node_t *node = malloc(sizeof(node_t));
    node->value = value;
    node->nextNode = NULL;
    return node;
}

void insert_node_at_head(node_t **pointerToHead, node_t *node_to_insert) {
    node_to_insert->nextNode = *pointerToHead;
    *pointerToHead = node_to_insert;
}

void insert_node_at_tail(node_t *head, node_t *node_to_insert) {
    if(1 == isEmpty(head)) {
        return;
    }

    node_t *tmp = head;
    while(tmp->nextNode != NULL) {
        tmp = tmp->nextNode;
    }
    tmp->nextNode = node_to_insert;
}

node_t *find_node(node_t *head, int value) {
    if(1 == isEmpty(head)) {
        return NULL;
    }

    node_t *tmp = head;
    while(tmp->nextNode != NULL) {
        if(tmp->value == value) {
            return tmp;
        }
        tmp = tmp->nextNode;
    }
    return NULL;
}

void insert_node_after_node(node_t *node_to_insert_after, node_t *node_to_insert) {
    if(1 == isEmpty(node_to_insert_after)) {
        return;
    }

    node_to_insert->nextNode = node_to_insert_after->nextNode;
    node_to_insert_after->nextNode = node_to_insert;
}

void delete_node(node_t **head, node_t *node_to_delete) {
    if(1 == isEmpty(*head)) {
        return;
    }

    if(*head == node_to_delete) {
        if((*head)->nextNode != NULL) {
            node_t *newHead = (*head)->nextNode;
            *head = newHead;
        } else {
            *head = NULL;
        }
        
        return;
    }

    node_t *tmp = *head;
    while(tmp->nextNode != node_to_delete) {
        tmp = tmp->nextNode;
    }
    tmp->nextNode = node_to_delete->nextNode;
}