#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int front;
    int back;
    int size;
    int length;
    int *storage;
} queue_t;

int *create_queue_storage(int size) {
    int *queueStorage = (int *) malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        queueStorage[i] = 0;
    }
    return queueStorage;
}

queue_t initialize_queue(int size) {
    queue_t queue;
    
    queue.back = -1;
    queue.front = -1;
    queue.size = size;
    queue.length = 0;
    queue.storage = create_queue_storage(size);

    return queue;
}

int isEmpty(queue_t *queue) {
    return queue->length == 0 ? 1 : 0;
}

int isFull(queue_t *queue) {
    return queue->length == queue->size ? 1 : 0;
}

void enqueue(int val, queue_t *queue) {
    // If the queue is full we cannot add more elements
    if(isFull(queue)) {
        return;
    }

    // if the queue is empty then front and back should be updated
    // to the same index in the array
    if(isEmpty(queue) == 1) {
        // make sure to reset again
        queue->back = -1;
        queue->front = -1;
        
        queue->back++;
        queue->front++;
    } else {
        // if the next back is out of the array range
        // we start at the beginning by restting it
        if(queue->back + 1 == queue->size) {
            queue->back = -1;
        }
        queue->back++;
    }

    queue->storage[queue->back] = val;
    queue->length++;
}

void dequeue(queue_t *queue) {
    // If the queue is empty we cannot dequeue
    if(isEmpty(queue)) {
        return;
    }

    queue->storage[queue->front] = 0;

    // If this is the end of the queue
    if(queue->front + 1 == queue->size) {
        // we reset the front
        queue->front = -1;
    }
    queue->front++;
    queue->length--;
}

void print_queue(queue_t *queue) {
    for(int i = 0; i < queue->size; i++) {
        printf("%d ", queue->storage[i]);
    }
    printf("\n");
}


int main() {
    queue_t queue = initialize_queue(6);
    
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

    printf("length: %d, front: %d, back: %d\n", queue.length, queue.front, queue.back);
    print_queue(&queue);

    return 0;
}