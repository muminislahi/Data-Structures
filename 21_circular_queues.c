#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct 
{
    int arr[MAX];
    int front;
    int rear;
} Queue;

void init(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue *q)
{
    return (q->front == -1);
}

int isFull(Queue *q)
{
    return ((q->rear + 1) % MAX == q->front);
}

void enqueue(Queue *q)
{
    if (isFull(q))
    {
        printf("Queue is full.\n");
        return;
    }

    int data;
    printf("Enter data to enqueue: ");
    scanf("%d", &data);

    if (isEmpty(q))
    {
        q->front = q->rear = 0;
    }
    else
    {
        q->rear = (q->rear + 1) % MAX;
    }

    q->arr[q->rear] = data;
    printf("%d enqueued.\n", data);
}

void dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return;
    }

    int data = q->arr[q->front];
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % MAX;
    }

    printf("%d dequeued.\n", data);
}

void peek(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Front element: %d\n", q->arr[q->front]);
}

void display(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    int i = q->front;
    while (1)
    {
        printf("%d ", q->arr[i]);
        if (i == q->rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

void size(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Size: 0\n");
        return;
    }

    int count = (q->rear - q->front + MAX) % MAX + 1;
    printf("Current size: %d\n", count);
}

void search(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return;
    }

    int key, found = 0;
    printf("Enter element to search: ");
    scanf("%d", &key);

    int i = q->front;
    while (1)
    {
        if (q->arr[i] == key)
        {
            printf("Element %d found in queue.\n", key);
            found = 1;
            break;
        }
        if (i == q->rear)
            break;
        i = (i + 1) % MAX;
    }

    if (!found)
        printf("Element not found.\n");
}

void clear(Queue *q)
{
    q->front = q->rear = -1;
    printf("Queue cleared.\n");
}

int main()
{
    Queue q;
    init(&q);
    int choice;

    do
    {
        printf("\n1] Enqueue\n2] Dequeue\n3] Peek\n4] Display\n5] Size\n6] Search\n7] Clear\n0] Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: 
                enqueue(&q); 
                break;

            case 2: 
                dequeue(&q); 
                break;

            case 3: 
                peek(&q); 
                break;

            case 4: 
                display(&q); 
                break;

            case 5: 
                size(&q); 
                break;

            case 6: 
                search(&q); 
                break;

            case 7: 
                clear(&q); 
                break;

            case 0: 
                printf("Exiting...\n"); 
                break;

            default: 
                printf("Invalid choice.\n"); 
                break;
        }
    } 
    while (choice != 0);

    return 0;
}
