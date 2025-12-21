#include <stdio.h>
#define MAX 100

typedef struct 
{
    int arr[MAX];
    int top;
} Stack;

void init(Stack *s)
{
    s->top = -1;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

int isFull(Stack *s)
{
    return s->top == MAX - 1;
}

void push(Stack *s)
{
    if (isFull(s)) 
    {
        printf("Stack Overflow! Cannot push more elements.\n");
        return;
    }

    int val;
    printf("Enter value to push: ");
    scanf("%d", &val);

    s->arr[++(s->top)] = val;
    printf("%d pushed onto stack.\n", val);
}

void pop(Stack *s)
{
    if (isEmpty(s)) 
    {
        printf("Stack Underflow! Stack is empty.\n");
        return;
    }

    int val = s->arr[(s->top)--];
    printf("Popped element: %d\n", val);
}

void peek(Stack *s)
{
    if (isEmpty(s)) 
    {
        printf("Stack is empty.\n");
        return;
    }

    printf("Top element: %d\n", s->arr[s->top]);
}

void display(Stack *s)
{
    if (isEmpty(s)) 
    {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements (top -> bottom): ");
    for (int i = s->top; i >= 0; i--)
        printf("%d ", s->arr[i]);
    printf("\n");
}

void size(Stack *s)
{
    printf("Current stack size: %d\n", s->top + 1);
}

void search(Stack *s)
{
    if (isEmpty(s)) 
    {
        printf("Stack is empty.\n");
        return;
    }

    int val;
    printf("Enter element to search: ");
    scanf("%d", &val);

    for (int i = s->top; i >= 0; i--) 
    {
        if (s->arr[i] == val) 
        {
            printf("%d found at position %d from top.\n", val, s->top - i + 1);
            return;
        }
    }

    printf("%d not found in stack.\n", val);
}

void clearStack(Stack *s)
{
    s->top = -1;
    printf("Stack cleared successfully.\n");
}

int main()
{
    Stack s;
    init(&s);
    int choice;

    do {
        printf("\n--- Stack using Array ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Check if Empty\n");
        printf("6. Check if Full\n7. Size\n8. Search\n9. Clear Stack\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
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
                printf(isFull(&s) ? "Stack is full.\n" : "Stack is not full.\n"); 
                break;
            case 7: 
                size(&s); 
                break;
            case 8: 
                search(&s); 
                break;
            case 9: 
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
