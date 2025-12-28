#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

void preorder(struct node *root) {
    if (root == NULL)
        return;

    struct node *stack[50];
    int top = -1;

    stack[++top] = root;

    while (top != -1) {
        root = stack[top--];
        printf("%d ", root->data);

        if (root->right)
            stack[++top] = root->right;
        if (root->left)
            stack[++top] = root->left;
    }
}

struct node* newNode(int x) {
    struct node* t = (struct node*)malloc(sizeof(struct node));
    t->data = x;
    t->left = t->right = NULL;
    return t;
}

int main() {
    struct node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(15);

    preorder(root);
    return 0;
}
