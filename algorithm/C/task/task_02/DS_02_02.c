#include <stdio.h>
#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = 0;
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

int isFull(Queue *q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}

void enqueue(Queue *q, int x) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    q->data[q->rear] = x;
    q->rear = (q->rear + 1) % MAX_SIZE;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int x = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    return x;
}

void printTopN(int n) {
    Queue q;
    initQueue(&q);
    int a = 1, b = 1;
    enqueue(&q, a);
    enqueue(&q, b);
    for (int i = 3; i <= n; i++) {
        int c = a + b;
        a = b;
        b = c;
        if (!isFull(&q)) {
            enqueue(&q, c);
        } else {
            dequeue(&q);
            enqueue(&q, c);
        }
    }
    printf("Top %d items of Fibonacci sequence : ", n);
    while (!isEmpty(&q)) {
        printf("%d ", dequeue(&q));
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    printTopN(n);
    return 0;
}