#include <stdio.h>
#define MAX 50

int s1[MAX], s2[MAX];
int top1 = -1, top2 = -1;

void push(int s[], int *top, int x) {
    s[++(*top)] = x;
}

int pop(int s[], int *top) {
    return s[(*top)--];
}

void enqueue(int x) {
    push(s1, &top1, x);
}

void dequeue() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty\n");
        return;
    }

    if (top2 == -1) {
        while (top1 != -1)
            push(s2, &top2, pop(s1, &top1));
    }

    printf("Deleted element: %d\n", pop(s2, &top2));
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    dequeue();
    dequeue();
    return 0;
}
