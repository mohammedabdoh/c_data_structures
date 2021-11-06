#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

typedef struct {
    node_t *head;
    node_t *tail;
} queue_t;

void enqueue(int val, queue_t *queue) {
    node_t *node_to_insert = create_new_node(val);
    insert_node_at_tail(&queue->head, &queue->tail, node_to_insert);
}

void dequeue(queue_t *queue) {
    delete_node(&queue->head, &queue->tail, queue->head);
}

void print_queue(queue_t *queue) {
    node_t *current_head = queue->head;

    while(current_head != NULL) {
        printf("%d ", current_head->value);
        current_head = current_head->nextNode;
    }

    printf("\n");
}

queue_t initialize_queue() {
    queue_t queue;
    
    queue.head = NULL;
    queue.tail = NULL;
    
    return queue;
}

int main() {

    queue_t queue = initialize_queue();
    
    enqueue(11, &queue);
    enqueue(6, &queue);
    enqueue(5, &queue);
    enqueue(20, &queue);
    enqueue(11, &queue);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    enqueue(23, &queue);
    enqueue(7, &queue);
    enqueue(65, &queue);
    enqueue(9, &queue);
    dequeue(&queue);
    enqueue(45, &queue);
    dequeue(&queue);
    dequeue(&queue);
    enqueue(31, &queue);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    enqueue(20, &queue);
    enqueue(43, &queue);

    print_queue(&queue);

    return 0;
}