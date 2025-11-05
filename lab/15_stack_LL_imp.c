#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node *next;
} Node;

typedef struct 
{
    Node *top;
} Stack;

void init(Stack *s)
{
    s->top = NULL;
}

int isEmpty(Stack *s)
{
    return s->top == NULL;
}

void push(Stack *s)
{
    int val;
    printf("Enter value to push: ");
    scanf("%d", &val);

    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) 
    {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = val;
    newNode->next = s->top;
    s->top = newNode;

    printf("%d pushed onto stack.\n", val);
}

void pop(Stack *s)
{
    if (isEmpty(s)) 
    {
        printf("Stack Underflow! Cannot pop.\n");
        return;
    }

    Node *temp = s->top;
    printf("Popped element: %d\n", temp->data);
    s->top = temp->next;
    free(temp);
}

void peek(Stack *s)
{
    if (isEmpty(s)) 
    {
        printf("Stack is empty.\n");
        return;
    }

    printf("Top element: %d\n", s->top->data);
}

void display(Stack *s)
{
    if (isEmpty(s)) 
    {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements (top → bottom): ");
    Node *temp = s->top;
    while (temp) 
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void size(Stack *s)
{
    int count = 0;
    Node *temp = s->top;
    while (temp) 
    {
        count++;
        temp = temp->next;
    }
    printf("Current stack size: %d\n", count);
}

void search(Stack *s)
{
    if (isEmpty(s)) 
    {
        printf("Stack is empty.\n");
        return;
    }

    int val, pos = 1;
    printf("Enter element to search: ");
    scanf("%d", &val);

    Node *temp = s->top;
    while (temp) 
    {
        if (temp->data == val) 
        {
            printf("%d found at position %d from top.\n", val, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }

    printf("%d not found in stack.\n", val);
}

void clearStack(Stack *s)
{
    Node *temp;
    while (s->top) 
    {
        temp = s->top;
        s->top = s->top->next;
        free(temp);
    }
    printf("Stack cleared successfully.\n");
}

int main()
{
    Stack s;
    init(&s);
    int choice;

    do {
        printf("\n--- Stack using Linked List ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Check if Empty\n");
        printf("6. Size\n7. Search\n8. Clear Stack\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                push(&s); 
                break;
            case 2: 
                pop(&s); 
                break;
            case 3: 
                peek(&s); 
                break;
            case 4: 
                display(&s); 
                break;
            case 5: 
                printf(isEmpty(&s) ? "Stack is empty.\n" : "Stack is not empty.\n"); 
                break;
            case 6: 
                size(&s); 
                break;
            case 7: 
                search(&s); 
                break;
            case 8: 
                clearStack(&s); 
                break;
            case 0: 
                printf("Exiting...\n"); 
                break;
            default: 
                printf("Invalid choice!\n");
        }

    } while (choice != 0);

    return 0;
}
