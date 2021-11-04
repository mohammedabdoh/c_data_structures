#include "linked_list.h"

void push(node_t **pointerToHead, int value) {
    node_t *new_element = create_new_node(value);
    insert_node_at_head(pointerToHead, new_element);
}

node_t *pop(node_t **head) {
    if(isEmpty(*head)) {
        return NULL;
    }
    node_t *node_to_return = *head;

    delete_node(head, *head);
    
    return node_to_return;
}

int main() {
    node_t *head = NULL;
    
    printf("Initialize\n");
    print_nodes(head);

    printf("\npush(%d)\n", 1);
    push(&head, 1);
    print_nodes(head);

    printf("\npush(%d)\n", 2);
    push(&head, 2);
    print_nodes(head);

    printf("\npush(%d)\n", 3);
    push(&head, 3);
    print_nodes(head);

    printf("\npush(%d)\n", 4);
    push(&head, 4);
    print_nodes(head);

    node_t *last_elemet = pop(&head);
    printf("\npop() -> %d\n", last_elemet->value);
    print_nodes(head);

    last_elemet = pop(&head);
    printf("\npop() -> %d\n", last_elemet->value);
    print_nodes(head);

    printf("\npush(%d)\n", 5);
    push(&head, 5);
    print_nodes(head);

    last_elemet = pop(&head);
    printf("\npop() -> %d\n", last_elemet->value);
    print_nodes(head);

    last_elemet = pop(&head);
    printf("\npop() -> %d\n", last_elemet->value);
    print_nodes(head);

    last_elemet = pop(&head);
    printf("\npop() -> %d\n", last_elemet->value);
    print_nodes(head);

    return 0;
}