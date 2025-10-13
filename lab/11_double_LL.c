#include<stdio.h>
#include<stdlib.h>

typedef struct nodes{

    int data;
    struct nodes *prev;
    struct nodes *next;

}n;


n* cr_double_node(n *y){

    n *x =(n*) malloc(sizeof(n));

    x->prev=y;
    y->next = x;
    x->next = NULL;

    return x;
}


n* trav(n*head,int final_node_num)
{
    n* trav_ptr=head;
    if(final_node_num<0)
    {
        while(trav_ptr->next!=NULL)
            trav_ptr=trav_ptr->next;
        
    }
    else 
    {
        while(--final_node_num&&trav_ptr->next!=NULL)
            trav_ptr=trav_ptr->next;
        
    }

    return trav_ptr;

}


void display_list(n* head)
{
    n* trav_ptr=head;

    printf("Data in the nodes is: ");
    while(trav_ptr!=NULL)
        printf("%d\t",trav_ptr->data);
  
}

void dll_del_node(n** addr_of_head, int node_to_del)
{
    n* trav_ptr;
    int i=1;

    trav(*addr_of_head,node_to_del-1);
    //given: trav ptr is pointing to node on the left of node to be deleted

    if((*addr_of_head)->next==NULL)
    {

        n* temp=(*addr_of_head)->next;
        *addr_of_head=NULL;
        free(temp);
        printf("Deleted. List now empty\n");
        return;
    }

    trav_ptr->next=trav_ptr->next->next;
    trav_ptr->next->prev=trav_ptr;
    free(trav_ptr);
}


void ins_node(n* head,int node_num)
{
    n* trav_ptr=trav(head,node_num);
    n* x=cr_double_node(trav_ptr);

    x->next=trav_ptr->next;
    trav_ptr->next=x;

    if(x->next)
        x->next->prev=x;

    x->prev=trav_ptr;

}



int main()
{
    n n1;
    n* head,*x;
    head=&n1;
    x=head;
    int num;
    head->prev=NULL;


    do 
    {

        printf("1] Create list of n nodes\n2] Insert\n3] Delete\n4] Delete a node\nx]enter 0 for exit\n");
        scanf("%d",&num);

        switch (num)
        {
            case 1:
            {
                int num_nodes;
                printf("How mnay nodes do you have to make?\n");
                scanf("%d",&num_nodes);

                while(num--)
                {

                    if(num)
                    {
                        printf("Enter data");
                        scanf("%d",&x->data);

                        cr_double_node(x);
                    }
                    else 
                    {
                        printf("Enter data");
                        scanf("%d",&x->data);

                    }
                }
                break;

            }



            case 2:
            {
                int ins_choice;
                n*x;

                printf("1]Insert in the beginning\n2] Insert at the end\n3] Insert a nodes at any position\n");
                scanff("%d",&ins_choice);

                n* tail=trav(x,-1);
                display_list(head);


                switch (ins_choice)
                {
                    case 1:
                        x=(n*)malloc(sizeof(n));
                        head->prev=x;
                        x->next=head;
                        head=x;
                        x->prev=NULL;
                        break;

                    case 2:

                        ins_node(tail,0);
                        break;

                    case 3:
                    {
                        int ins_node_num;
                        printf("Enter the node num after which insertion should occur\n");
                        scanf("%d",&ins_node_num);

                        ins_node(head,ins_node_num);
                        break;
                    }

                    default:
                        break;

                }
            }

            case 3:
            {
                int dele_choice;
                printf("1] Delete a node at the beginning\n2] Delete a node at the end\n3]Delete a nodes at any position\n");
                scanf("%d",&dele_choice);

                switch (dele_choice)
                {
                    case 1:
                    {
                        n* x=head->next;
                        x->prev=NULL;
                        head=x;
                        break;

                    }

                    case 2:
                    {
                        n* x=traversal(head);
                        x=x->prev;
                        x->next=NULL;
                        break;
                    }

                    case 3:
                    {
                        int del_node_num;
                        printf("Enter the node num which should be deleted\n");
                        scanf("%d",&del_node_num);

                        dll_del_node(&head,del_node_num);
                        break;

                    }


                }

            }


        }


    }while(num);
    return 0;

}
