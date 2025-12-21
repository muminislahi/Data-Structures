#include <stdio.h>

#define MAX 100

void create_graph(int adjacency_matrix[][MAX], int vertices_count)
{
    for(int row = 0 ; row < vertices_count ; row++)
    {
        for(int col = 0 ; col < vertices_count ; col++)
        {
            adjacency_matrix[row][col] = 0;
        }
    }
}

void add_edge(int adjacency_matrix[][MAX], int source_vertex, int destination_vertex)
{
    adjacency_matrix[source_vertex][destination_vertex] = 1;
    adjacency_matrix[destination_vertex][source_vertex] = 1;  // undirected
}

void remove_edge(int adjacency_matrix[][MAX], int source_vertex, int destination_vertex)
{
    adjacency_matrix[source_vertex][destination_vertex] = 0;
    adjacency_matrix[destination_vertex][source_vertex] = 0;
}

void display_graph(int adjacency_matrix[][MAX], int vertices_count)
{
    printf("\nAdjacency Matrix:\n");

    for(int row = 0 ; row < vertices_count ; row++)
    {
        for(int col = 0 ; col < vertices_count ; col++)
        {
            printf("%d ", adjacency_matrix[row][col]);
        }
        printf("\n");
    }
}

void bfs(int adjacency_matrix[][MAX], int vertices_count, int start_vertex)
{
    int queue[MAX];
    int front_queue_index = 0;
    int back_queue_index = 0;

    int visited_vertices[MAX] = {0};

    queue[back_queue_index++] = start_vertex;
    visited_vertices[start_vertex] = 1;

    printf("\nBFS Traversal: ");

    while(front_queue_index < back_queue_index)
    {
        int current_vertex = queue[front_queue_index++];
        printf("%d ", current_vertex);

        for(int adj_vertex = 0 ; adj_vertex < vertices_count ; adj_vertex++)
        {
            if(adjacency_matrix[current_vertex][adj_vertex] == 1 && visited_vertices[adj_vertex] == 0)
            {
                visited_vertices[adj_vertex] = 1;
                queue[back_queue_index++] = adj_vertex;
            }
        }
    }

    printf("\n");
}

void dfs_recursive(int adjacency_matrix[][MAX], int vertices_count, int current_vertex, int visited_vertices[])
{
    visited_vertices[current_vertex] = 1;

    printf("%d ", current_vertex);

    for(int adj_vertex = 0 ; adj_vertex < vertices_count ; adj_vertex++)
    {
        if(adjacency_matrix[current_vertex][adj_vertex] == 1 && visited_vertices[adj_vertex] == 0)
        {
            dfs_recursive(adjacency_matrix, vertices_count, adj_vertex, visited_vertices);
        }
    }
}

void dfs(int adjacency_matrix[][MAX], int vertices_count, int start_vertex)
{
    int visited_vertices[MAX] = {0};

    printf("\nDFS Traversal: ");
    dfs_recursive(adjacency_matrix, vertices_count, start_vertex, visited_vertices);
    printf("\n");
}


int main()
{
    int adjacency_matrix[MAX][MAX];
    int vertices_count;
    int choice;
    int source_vertex, destination_vertex, start_vertex;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices_count);

    create_graph(adjacency_matrix, vertices_count);

    while(1)
    {
        printf("\n1. Add edge\n2. Remove edge\n3. Display graph\n4. BFS\n5. DFS\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            printf("Enter source vertex: ");
            scanf("%d", &source_vertex);
            printf("Enter destination vertex: ");
            scanf("%d", &destination_vertex);

            add_edge(adjacency_matrix, source_vertex, destination_vertex);
        }
        else if(choice == 2)
        {
            printf("Enter source vertex: ");
            scanf("%d", &source_vertex);
            printf("Enter destination vertex: ");
            scanf("%d", &destination_vertex);

            remove_edge(adjacency_matrix, source_vertex, destination_vertex);
        }
        else if(choice == 3)
        {
            display_graph(adjacency_matrix, vertices_count);
        }
        else if(choice == 4)
        {
            printf("Enter start vertex: ");
            scanf("%d", &start_vertex);

            bfs(adjacency_matrix, vertices_count, start_vertex);
        }
        else if(choice == 5)
        {
            printf("Enter start vertex: ");
            scanf("%d", &start_vertex);

            dfs(adjacency_matrix, vertices_count, start_vertex);
        }
        else
        {
            break;
        }
    }

    return 0;
}
