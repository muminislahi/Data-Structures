#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

typedef struct
{
    Node *front;
    Node *rear;
} Queue;

void init(Queue *q)
{
    q->front = q->rear = NULL;
}

int isEmpty(Queue *q)
{
    return (q->front == NULL);
}

void enqueue(Queue *q)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    printf("Enter data to enqueue: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    if (isEmpty(q))
    {
        q->front = q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    printf("%d enqueued successfully.\n", newNode->data);
}

void dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return;
    }

    Node *temp = q->front;
    printf("%d dequeued.\n", temp->data);
    q->front = q->front->next;

    if (q->front == NULL)
    {
        q->rear = NULL; // Queue is now empty
    }

    free(temp);
}

void peek(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Front element: %d\n", q->front->data);
}

void display(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return;
    }

    Node *temp = q->front;
    printf("Queue elements: ");
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void size(Queue *q)
{
    int count = 0;
    Node *temp = q->front;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    printf("Size of queue: %d\n", count);
}

void search(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return;
    }

    int key, pos = 1;
    printf("Enter value to search: ");
    scanf("%d", &key);

    Node *temp = q->front;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            printf("Element %d found at position %d.\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }

    printf("Element %d not found in queue.\n", key);
}

void clearQueue(Queue *q)
{
    Node *temp;
    while (q->front != NULL)
    {
        temp = q->front;
        q->front = q->front->next;
        free(temp);
    }

    q->rear = NULL;
    printf("Queue cleared successfully.\n");
}

int main()
{
    Queue q;
    init(&q);

    int choice;

    do
    {
        printf("\n--- Queue Menu ---\n");
        printf("1] Enqueue\n2] Dequeue\n3] Peek\n4] Display\n5] Size\n6] Search\n7] Clear Queue\n0] Exit\n");
        printf("Enter your choice: ");
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
                clearQueue(&q);
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }

    } while (choice != 0);

    clearQueue(&q); // Cleanup before exit
    return 0;
}
