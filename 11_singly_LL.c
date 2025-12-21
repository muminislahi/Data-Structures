#include<stdio.h>
#include<stdlib.h>
//has functions for traversal, insertion, insertion sort etc

typedef struct nodes{

    int data;
    struct nodes *next;

}n;


n* cr_node(n *prev){

    n *p =(n*) malloc(sizeof(n));

    prev->next = p;
    p->next = NULL;

    return p;
}

//do traversal once here making it return the next address and loop through wherever you want it
n* traverse_to(n* base_addr, int node_num)
{
    n* x=base_addr;
    int i=1;
    while(i<node_num)
    {
        x=x->next;
        i++;
    }

    return x;
}

n* traverse(n* head)
{
    n* x=head;
    int i=1;

    while(x)
    {
   
        printf("\n  N%d\n",i);
        printf(" ----\n");
        printf("| ");
        printf(" %d  |\n",x->data);
        printf(" ----\n");

    
        if(x->next)
        {
            printf(" \\|/");
            x=x->next;
        }

        else 
            break;

        i++;
    
    }
    return x;


}

void insert_node (n* base_addr,int num, int insert_after)
{
    int i=1;
    n* x=base_addr;
    x=traverse_to(base_addr,insert_after);

    n*temp=x;
    n* y=x->next;

    while(num--)
    {
        temp->next=x;
        x=cr_node(x);

        printf("Enter data\n");
        scanf("%d",&x->data);

        x->next=y;

    }
} 


int t_nodes(n* base_add)
{
    int no=1;
    while(base_add->next!=NULL)
    {
        no++;
        base_add=base_add->next;
    }

    return no;
}

void simple_sort(n** base_addr)
{
    n* x=*base_addr,*y=x->next,*temp;

    int no_nodes=t_nodes(*base_addr);

    for(int i=0;i<no_nodes-1;i++)
    {   

        for(int j=0;j<no_nodes&&y!=NULL;j++)
        {

            if(x->data<y->data)
            {
                x->next=y->next;
                y->next=x;

                if(x==*base_addr)
                {
                    *base_addr =y;
                }
                else 
                {
                    temp->next=y;
                    temp=temp->next;
                }
                temp=y;

                y=x->next;
            }
            else 
            {
                x=y;
                y=x->next;
            }


        }
        x=*base_addr;
        y=x;
    }
    
}



// n* insertion_sort(n* node)
// {
//     printf("check check4\n");
//     //assume list needs to be sorted in ascending order 
//     n* shead=NULL,*tptr;//tptr->traversal ptr
    
//     if((shead==NULL)|| (shead->data>node->data))
//         {
//             node->next=shead;
//             shead=node;
//         }
//     else 
//     {while(tptr!=NULL)
//     {
//         printf("Check2\n");
       
//             if(tptr->next->data>node->data)
//             {
//                 node->next=tptr->next;
//                 tptr->next=node;
//             }

//             else if(tptr->next==NULL)
//             {
//                 node->next=tptr->next;
//                 tptr->next=node;
//             }
//         }
//         tptr=tptr->next;
//         printf("%d",tptr->data);

//     }
//     printf("%d",shead->data);

//     return shead;
// }

// n* select_for_IS(n* base_add)
// {

//     printf("Check1\n");
//     n* sptr=base_add,*head,*temp;//sptr->selection ptr
//     while(sptr!=NULL)
//     {
//         printf("check3\n");
//         temp=sptr->next;
//         head=insertion_sort(sptr);
//         sptr=temp;
//         printf("check end of out function\n");
//         printf("%d",head->data);

//     }
//     printf("End of selection func\n");
    
//     return head;
    
// }

void sorted_ins_asc(n** head, n* node);
void ins_sort(n **addr_of_head);

int main()
{
    n *head,*p;
    n n1;
    head = p = &n1;

    while (1)
    {

        int operation;
        printf("\n1] Create a node\n2] Create multiple nodes\n3] Traverse through the list\n4] Insert in the list\n5]Sort in descending order\n6] Sort in ascending order (IS)\nEnter a num: ");
        scanf(" %d",&operation);

        switch (operation)
        {
            case 1:
                
                printf("\nEnter int data: ");
                scanf(" %d",&p->data);
                p = cr_node(p);
                break;

            case 2:
            {
                int num;
                printf("\nEnter how many nodes to create: ");
                scanf(" %d",&num);

                if (num<=0)
                {
                    printf("\nInvalid input");
                    break;    
                }
                while (num--)
                {
                    if(num)
                    {
                        printf("\nEnter int data: ");
                        scanf(" %d",&p->data);
                        p = cr_node(p);
                    }
                    else 
                    {
                        printf("\nEnter int data: ");
                        scanf(" %d",&p->data);
                    }
                }
                break;
            }

            case 3:
                traverse(head);
                break;

            case 4:
            {
                int num,new_posi,ins_choice;
                //using tail to avoid traversal when inserting at the end
                n* tail=traverse(head),*x;
                printf("1] Insert 1 at beginning\n2]Insert one at end\n3] Insert multiple at any position\n");
                scanf("%d",&ins_choice);

                switch (ins_choice)
                {
                    case 1:
                        x=(n*)malloc(sizeof(n));
                        x->next=head;
                        head=x;
                        printf("Enter data\n");
                        scanf("%d",&head->data);

                        break;
                        
                    case 2:
                        insert_node(tail,1,0);
                        break;

                    case 3:
                        printf("How many nodes do you want to insert?\n");
                        scanf("%d",&num);

                        printf("After which node do you want to insert the node?\n");
                        scanf("%d",&new_posi);
                        insert_node(head,num,new_posi);
                        break;
                }

                break;    
            }

            case 5:
            {
                n** ptr_to_head=&head;
                simple_sort(ptr_to_head);
                traverse(head);
                break;
            }

            case 6:
            {
                
                ins_sort(&head);
                traverse(head);
                break;
            }
            default:
                break;

            }
    }

    return 0;
}

void sorted_ins_asc(n** head, n* node)
{
//ascending order
    if(*head==NULL||(*head)->data>node->data)
{        node->next=*head;
        *head=node;
        return;
    }

    n* temp=*head;//points to the node next to which new node is to be inserted

    while(temp->next!=NULL && temp->next->data<node->data)
    {
        
        temp=temp->next;
    }

    node->next=temp->next;
    temp->next=node;


    return;

}


void ins_sort(n **addr_of_head)
{

    n* x=(*addr_of_head),*y=x;

    *addr_of_head=NULL;

    do
    {
      
                y=y->next;

        sorted_ins_asc(addr_of_head,x);
        x=y;

    }while(y!=NULL);

return;
}
