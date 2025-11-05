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
    return (q->rear == MAX - 1);
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
        q->front = 0;
    }

    q->rear++;
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
    printf("%d dequeued.\n", data);
    q->front++;

    if (q->front > q->rear)
    {
        q->front = q->rear = -1; // Reset when empty
    }
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
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d ", q->arr[i]);
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

    printf("Current size: %d\n", q->rear - q->front + 1);
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

    for (int i = q->front; i <= q->rear; i++)
    {
        if (q->arr[i] == key)
        {
            printf("Element %d found at position %d.\n", key, i - q->front + 1);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Element not found.\n");
}

void clear(Queue *q)
{
    q->front = -1;
    q->rear = -1;
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
