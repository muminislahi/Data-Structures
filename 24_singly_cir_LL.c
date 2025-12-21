#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} n;

n* createNode(n *prev)
{
    n *p = (n*) malloc(sizeof(n));
    printf("Enter data for the node: ");
    scanf("%d", &p->data);
    p->next = prev->next;
    prev->next = p;
    return p;
}

n* traverse(n* head, int node_num)
{
    if (head == NULL)
        return NULL;

    n* temp = head;

    if (node_num < 0)
    {
        while (temp->next != head)
            temp = temp->next;
    }
    else
    {
        while (--node_num && temp->next != head)
            temp = temp->next;
    }

    return temp;
}

void insertNode(n **head, int node_num)
{
    if (*head == NULL)
        return;

    n* trav_ptr = traverse(*head, node_num);
    if (trav_ptr == NULL)
        return;

    n* newNode = (n*) malloc(sizeof(n));
    printf("Enter data for the node: ");
    scanf("%d", &newNode->data);

    newNode->next = trav_ptr->next;
    trav_ptr->next = newNode;
}

void deleteNode(n **head, int node_num)
{
    if (*head == NULL)
        return;

    n *temp = *head, *prev = NULL;

    if (node_num == 1)
    {
        if ((*head)->next == *head)
        {
            free(*head);
            *head = NULL;
            return;
        }

        while (temp->next != *head)
            temp = temp->next;

        n* del = *head;
        temp->next = (*head)->next;
        *head = (*head)->next;
        free(del);
        return;
    }

    if (node_num == -1)
    {
        while (temp->next->next != *head)
            temp = temp->next;

        n* del = temp->next;
        temp->next = *head;
        free(del);
        return;
    }

    int count = 1;
    while (count < node_num && temp->next != *head)
    {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (temp == *head)
        return;

    prev->next = temp->next;
    free(temp);
}

void displayList(n* head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    n* temp = head;
    while (temp->next != head)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

int main()
{
    n* head = NULL, *x;
    int menu_choice;

    head = (n*) malloc(sizeof(n));
    printf("Enter data for first node: ");
    scanf("%d", &head->data);
    head->next = head;
    x = head;

    do
    {
        printf("\n--- MENU ---\n");
        printf("1] Create n nodes\n");
        printf("2] Insert a node\n");
        printf("3] Delete a node\n");
        printf("4] Display the list\n");
        printf("0] Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &menu_choice);

        switch (menu_choice)
        {
            case 1:
            {
                int count;
                printf("How many nodes do you want to add: ");
                scanf("%d", &count);

                while (count--)
                {
                    x = createNode(x);
                }

                x->next = head;
                break;
            }

            case 2:
            {
                int choice;
                printf("1] Insert at beginning\n");
                printf("2] Insert after a specific node\n");
                printf("3] Insert at end\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice)
                {
                    case 1:
                    {
                        n* newNode = (n*) malloc(sizeof(n));
                        printf("Enter data for the node: ");
                        scanf("%d", &newNode->data);

                        n* last = traverse(head, -1);
                        newNode->next = head;
                        head = newNode;
                        last->next = head;
                        break;
                    }

                    case 2:
                    {
                        displayList(head);
                        int node_num;
                        printf("After which node number do you want to insert: ");
                        scanf("%d", &node_num);
                        insertNode(&head, node_num);
                        break;
                    }

                    case 3:
                    {
                        insertNode(&head, -1);
                        break;
                    }
                }
                break;
            }

            case 3:
            {
                int choice;
                printf("1] Delete from beginning\n");
                printf("2] Delete from end\n");
                printf("3] Delete from any position\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice)
                {
                    case 1:
                        deleteNode(&head, 1);
                        break;

                    case 2:
                        deleteNode(&head, -1);
                        break;

                    case 3:
                    {
                        int pos;
                        printf("Enter node position to delete: ");
                        scanf("%d", &pos);
                        deleteNode(&head, pos);
                        break;
                    }
                }
                break;
            }

            case 4:
                displayList(head);
                break;
        }
    }
    while (menu_choice != 0);

    return 0;
}
