//Q0. Second Largest Element in an Array

#include <stdio.h>
int main() {
    int a[50], n, i, max1, max2;
    scanf("%d", &n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);

    max1 = max2 = -9999;

    for(i=0;i<n;i++) {
        if(a[i] > max1) {
            max2 = max1;
            max1 = a[i];
        } else if(a[i] > max2 && a[i] != max1) {
            max2 = a[i];
        }
    }

    printf("Second Largest = %d", max2);
    return 0;
}


//Q1. Detect Cycle in Linked List
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int detectCycle(struct node *head) {
    struct node *slow = head, *fast = head;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return 1;
    }
    return 0;
}


//Q2. Find Middle of Singly Linked List

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void findMiddle(struct node *head) {
    struct node *slow = head, *fast = head;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("Middle element = %d", slow->data);
}
  



//Q4. Stack Using Two Queues
#include <stdio.h>
#define MAX 50

int q1[MAX], q2[MAX];
int f1=-1,r1=-1,f2=-1,r2=-1;

void enqueue(int q[], int *f, int *r, int x) {
    if(*f == -1) *f = 0;
    q[++(*r)] = x;
}

int dequeue(int q[], int *f, int *r) {
    int x = q[*f];
    if(*f == *r) *f = *r = -1;
    else (*f)++;
    return x;
}
//Q5. Inorder Traversal Without Recursion
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

void inorder(struct node *root) {
    struct node *stack[50];
    int top = -1;

    while(root || top != -1) {
        while(root) {
            stack[++top] = root;
            root = root->left;
        }
        root = stack[top--];
        printf("%d ", root->data);
        root = root->right;
    }
}

//Q7. Postorder Traversal Without Recursion

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

void postorder(struct node *root) {
    struct node *s1[50], *s2[50];
    int t1=-1, t2=-1;

    s1[++t1] = root;

    while(t1 != -1) {
        root = s1[t1--];
        s2[++t2] = root;

        if(root->left) s1[++t1] = root->left;
        if(root->right) s1[++t1] = root->right;
    }

    while(t2 != -1)
        printf("%d ", s2[t2--]->data);
}

//Q8. Check if Binary Tree is Balanced (Concept Code)
int height(struct node *root) {
    if(root == NULL) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh > rh ? lh : rh) + 1;
}

//Q12. Lowest Common Ancestor in BST
struct node* LCA(struct node* root, int n1, int n2) {
    if(root == NULL) return NULL;

    if(n1 < root->data && n2 < root->data)
        return LCA(root->left, n1, n2);

    if(n1 > root->data && n2 > root->data)
        return LCA(root->right, n1, n2);

    return root;
}

//Q10. Nearest Available Driver (Ride-Booking System)
#include <stdio.h>

int main() {
    int drivers, i;
    float dist[50], min;
    int index = 0;

    printf("Enter number of drivers: ");
    scanf("%d", &drivers);

    for(i = 0; i < drivers; i++) {
        printf("Enter distance of driver %d: ", i+1);
        scanf("%f", &dist[i]);
    }

    min = dist[0];
    for(i = 1; i < drivers; i++) {
        if(dist[i] < min) {
            min = dist[i];
            index = i;
        }
    }

    printf("Nearest driver is Driver %d at distance %.2f\n", index+1, min);
    return 0;
}

//Q11. Load Balancing Across Servers (Round Robin)
#include <stdio.h>

int main() {
    int servers, requests, i;

    printf("Enter number of servers: ");
    scanf("%d", &servers);

    printf("Enter number of requests: ");
    scanf("%d", &requests);

    for(i = 0; i < requests; i++) {
        printf("Request %d handled by Server %d\n",
               i+1, (i % servers) + 1);
    }

    return 0;
}

