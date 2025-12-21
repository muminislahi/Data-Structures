#include <stdio.h>

#define MAX 100

void init_tree(int tree_array[])
{
    for(int index = 0 ; index < MAX ; index++)
    {
        tree_array[index] = -1;
    }
}

void insert_node(int tree_array[], int index, int value)
{
    if(index >= MAX)
    {
        printf("Index out of range.\n");
        return;
    }

    tree_array[index] = value;
}

void delete_node(int tree_array[], int index)
{
    if(index >= MAX)
    {
        printf("Index out of range.\n");
        return;
    }

    tree_array[index] = -1;
}

void level_order(int tree_array[])
{
    for(int index = 0 ; index < MAX ; index++)
    {
        if(tree_array[index] != -1)
        {
            printf("%d ", tree_array[index]);
        }
    }
    printf("\n");
}

int main()
{
    int tree_array[MAX];
    int choice, index, value;

    init_tree(tree_array);

    while(1)
    {
        printf("\n1. Insert\n2. Delete\n3. Level Order\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            printf("Enter index: ");
            scanf("%d", &index);
            printf("Enter value: ");
            scanf("%d", &value);

            insert_node(tree_array, index, value);
        }
        else if(choice == 2)
        {
            printf("Enter index: ");
            scanf("%d", &index);

            delete_node(tree_array, index);
        }
        else if(choice == 3)
        {
            level_order(tree_array);
        }
        else
        {
            break;
        }
    }

    return 0;
}
