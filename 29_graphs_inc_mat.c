#include <stdio.h>

#define MAX 100

void create_incidence_matrix(int incidence_matrix[][MAX], int vertices_count, int edges_count)
{
    for(int row = 0 ; row < vertices_count ; row++)
    {
        for(int col = 0 ; col < edges_count ; col++)
        {
            incidence_matrix[row][col] = 0;
        }
    }
}

void add_edge(int incidence_matrix[][MAX], int edge_index, int source_vertex, int destination_vertex)
{
    incidence_matrix[source_vertex][edge_index] = 1;
    incidence_matrix[destination_vertex][edge_index] = 1;  
}

void display_incidence_matrix(int incidence_matrix[][MAX], int vertices_count, int edges_count)
{
    printf("\nIncidence Matrix:\n");

    for(int row = 0 ; row < vertices_count ; row++)
    {
        for(int col = 0 ; col < edges_count ; col++)
        {
            printf("%d ", incidence_matrix[row][col]);
        }
        printf("\n");
    }
}

int main()
{
    int vertices_count;
    int edges_count;
    int incidence_matrix[MAX][MAX];
    int source_vertex, destination_vertex;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices_count);

    printf("Enter number of edges: ");
    scanf("%d", &edges_count);

    create_incidence_matrix(incidence_matrix, vertices_count, edges_count);

    for(int edge_index = 0 ; edge_index < edges_count ; edge_index++)
    {
        printf("\nEnter source and destination for edge %d:\n", edge_index);
        scanf("%d%d", &source_vertex, &destination_vertex);
        add_edge(incidence_matrix, edge_index, source_vertex, destination_vertex);
    }

    display_incidence_matrix(incidence_matrix, vertices_count, edges_count);

    return 0;
}
