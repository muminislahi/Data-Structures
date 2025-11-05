#include <stdio.h>
#include <stdlib.h>

typedef struct nodes{
    int data;
    struct nodes *next;
} n;

n* cr_node(n *prev){
    n *p = (n*) malloc(sizeof(n));
    p->next = prev->next;
    prev->next = p;
    return p;
}

n* trav(n* head, int final_node_num)
{
    n* trav_ptr = head;
    if (head == NULL) return NULL;

    if(final_node_num < 0)
    {
        while(trav_ptr->next != head)
            trav_ptr = trav_ptr->next;
    }
    else
    {
        while(--final_node_num && trav_ptr->next != head)
            trav_ptr = trav_ptr->next;
    }

    return trav_ptr;
}

void ins_node(n **head, int node_num)
{
    if (*head == NULL) return;

    n* trav_ptr = trav(*head, node_num);
    if (trav_ptr == NULL) return;

    n* x = cr_node(trav_ptr);
    printf("ENter data for the node\n");
    scanf("%d",&x->data);

    /* cr_node already wired next pointers correctly */
    /* no additional action needed */
}

void display_list(n* head)
{
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    n* trav_ptr = head;
    while(trav_ptr->next != head)
    {
        printf("%d\t", trav_ptr->data);
        trav_ptr = trav_ptr->next;
    }
    printf("%d\t\n", trav_ptr->data);
}

void del_node(n** head,int node_num_to_del);

int main() {

    n* head = NULL;
    n* x;
    int menu_choice;

    /* initialize first node */
    head = (n*)malloc(sizeof(n));
    printf("Enter data for first node\n");
    scanf("%d",&head->data);
    head->next = head;
    x = head;

    do
    {
        printf("1] Create n nodes\n2] Insert a node\n3] Delete a node\n4] Display the list\n0] Exit\n");
        scanf("%d",&menu_choice);

        switch (menu_choice)
        {
            case 1:
            {
                int cr_choice;
                printf("How many nodes do you want to add\n");
                scanf("%d",&cr_choice);
                while(cr_choice--)
                {
                    x = cr_node(x);
                    printf("Enter data for the node\n");
                    scanf("%d",&x->data);
                }
                x->next = head;
                break;
            }

            case 2:
            {
                int ins_choice;
                printf("1] Enter a node in the beginning\n2] Enter at any position\n3] Enter at the end\n");
                scanf("%d",&ins_choice);

                switch (ins_choice)
                {
                    case 1:
                    {
                        display_list(head);
                        n* trav_ptr;
                        n* a = (n*)malloc(sizeof(n));

                        printf("ENter data for the node\n");
                        scanf("%d",&a->data);

                        a->next = head;
                        trav_ptr = trav(head,-1); /* tail */
                        head = a;
                        trav_ptr->next = head;
                        break;
                    }

                    case 2:
                    {
                        display_list(head);
                        int node_num;
                        printf("After which node number do you want to add a node?");
                        scanf("%d",&node_num);
                        ins_node(&head,node_num);
                        break;
                    }

                    case 3:
                    {
                        display_list(head);
                        ins_node(&head,-1);
                        break;
                    }
                }
                break;
            }

            case 3:
            {
                printf("1] Delete a node from the beginning\n2] Delete a node at the end\n3] Delete a node at any position\n");
                int del_choice;
                scanf("%d",&del_choice);

                switch (del_choice)
                {
                    case 1:
                        del_node(&head,1);
                        break;
                    case 2:
                        del_node(&head,-1);
                        break;
                    case 3:
                    {
                        int node_num_to_del;
                        printf("Enter the node number ot delete\n");
                        scanf("%d",&node_num_to_del);
                        del_node(&head,node_num_to_del);
                        break;
                    }
                }

                break;
            }

            case 4:
                display_list(head);
                break;

            case 0:
                break;
        }

    } while(menu_choice != 0);

    /* free remaining nodes (optional tidy-up) */
    if (head != NULL) {
        n *t = head->next;
        while (t != head) {
            n *tmp = t;
            t = t->next;
            free(tmp);
        }
        free(head);
        head = NULL;
    }

    return 0;
}


void del_node(n** head,int node_num_to_del)
{
    if (*head == NULL) return;

    /* single node case */
    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        return;
    }

    /* delete first node */
    if (node_num_to_del == 1) {
        n* tail = trav(*head, -1);
        n* node_to_free = *head;
        *head = (*head)->next;    /* move head to second node before freeing */
        tail->next = *head;       /* close the circle */
        free(node_to_free);
        return;
    }

    /* delete last node */
    if (node_num_to_del == -1) {
        n* tail = trav(*head, -1);
        /* find node before tail */
        n* prev = *head;
        while (prev->next != tail)
            prev = prev->next;
        prev->next = tail->next; /* tail->next is head */
        free(tail);
        return;
    }

    /* delete any other node (position given by node_num_to_del) */
    n* trav_ptr = trav(*head, node_num_to_del - 1);
    if (trav_ptr == NULL || trav_ptr->next == NULL) return;
    n* node_to_free = trav_ptr->next;
    trav_ptr->next = node_to_free->next;
    free(node_to_free);
}

