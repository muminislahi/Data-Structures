#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct node
{
    int vertex_value; 
    struct node *next_node;
};

struct node* create_node(int vertex_value)
{
    struct node *new_node = malloc(sizeof(struct node));
    new_node->vertex_value = vertex_value;
    new_node->next_node = NULL;
    return new_node;
}

void add_edge(struct node *adj_list[], int source_vertex, int destination_vertex)
{
    struct node *new_node = create_node(destination_vertex);
    new_node->next_node = adj_list[source_vertex];
    adj_list[source_vertex] = new_node;

    new_node = create_node(source_vertex);
    new_node->next_node = adj_list[destination_vertex];
    adj_list[destination_vertex] = new_node;
}

void display_graph(struct node *adj_list[], int vertices_count)
{
    printf("\nAdjacency List:\n");

    for(int vertex = 0 ; vertex < vertices_count ; vertex++)
    {
        printf("%d -> ", vertex);

        struct node *temp = adj_list[vertex];
        while(temp != NULL)
        {
            printf("%d ", temp->vertex_value);
            temp = temp->next_node;
        }

        printf("\n");
    }
}

vo
