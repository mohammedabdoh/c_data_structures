#include <stdlib.h>
#include <stdio.h>

struct node {
    int value;
    struct node *nextNode;
};

typedef struct node node_t;

void print_nodes(node_t *head) {
    node_t *temporary = head;
    printf("HEAD -> ");
    while (temporary != NULL) {
        printf("%d -> ", temporary->value);
        temporary = temporary->nextNode;
    }
    printf("NULL\n");
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

void delete_node(node_t *head, node_t *node_to_delete) {
    if(1 == isEmpty(head)) {
        return;
    }

    node_t *tmp = head;
    while(tmp->nextNode != node_to_delete) {
        tmp = tmp->nextNode;
    }
    tmp->nextNode = node_to_delete->nextNode;
}

int main() {

    node_t *head = NULL;

    for (int i = 0; i < 10; ++i) {
        insert_node_at_head(&head, create_new_node(i+1));
    }
    print_nodes(head);

    insert_node_after_node(find_node(head, 6), create_new_node(15));
    print_nodes(head);

    insert_node_at_tail(head, create_new_node(100));
    print_nodes(head);

    delete_node(head, find_node(head, 2));
    print_nodes(head);

    if(NULL != find_node(head, 6)) {
        printf("Node was found.");
    } else {
        printf("Node not found.");
    }

    return 0;
}