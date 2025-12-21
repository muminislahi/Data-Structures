#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left_child;
    struct node *right_child;
};

struct node* create_node(int value)
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->left_child = NULL;
    new_node->right_child = NULL;
    return new_node;
}

// Queue for level insertion
// fq = front_queue_index, bq = back_queue_index
struct node* insert_level_order(struct node *root, int value)
{
    if(root == NULL)
    {
        return create_node(value);
    }

    struct node *queue[100];
    int fq = 0, bq = 0;   // front and back

    queue[bq++] = root;

    while(fq < bq)
    {
        struct node *current_node = queue[fq++];

        if(current_node->left_child == NULL)
        {
            current_node->left_child = create_node(value);
            break;
        }
        else
        {
            queue[bq++] = current_node->left_child;
        }

        if(current_node->right_child == NULL)
        {
            current_node->right_child = create_node(value);
            break;
        }
        else
        {
            queue[bq++] = current_node->right_child;
        }
    }
    return root;
}

void inorder(struct node *root)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->left_child);
    printf("%d ", root->data);
    inorder(root->right_child);
}

void preorder(struct node *root)
{
    if(root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left_child);
    preorder(root->right_child);
}

void postorder(struct node *root)
{
    if(root == NULL)
    {
        return;
    }
    postorder(root->left_child);
    postorder(root->right_child);
    printf("%d ", root->data);
}

void level_order(struct node *root)
{
    if(root == NULL)
    {
        return;
    }

    struct node *queue[100];
    int fq = 0, bq = 0;

    queue[bq++] = root;

    while(fq < bq)
    {
        struct node *current_node = queue[fq++];
        printf("%d ", current_node->data);

        if(current_node->left_child != NULL)
        {
            queue[bq++] = current_node->left_child;
        }

        if(current_node->right_child != NULL)
        {
            queue[bq++] = current_node->right_child;
        }
    }
}

int main()
{
    struct node *root = NULL;
    int choice, value;

    while(1)
    {
        printf("\n1. Insert\n2. Inorder\n3. Preorder\n4. Postorder\n5. Level Order\n6. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            printf("Enter value: ");
            scanf("%d", &value);
            root = insert_level_order(root, value);
        }
        else if(choice == 2)
        {
            inorder(root);
            printf("\n");
        }
        else if(choice == 3)
        {
            preorder(root);
            printf("\n");
        }
        else if(choice == 4)
        {
            postorder(root);
            printf("\n");
        }
        else if(choice == 5)
        {
            level_order(root);
            printf("\n");
        }
        else
        {
            break;
        }
    }

    return 0;
}
