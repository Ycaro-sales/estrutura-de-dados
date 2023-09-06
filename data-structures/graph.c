#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 10000

typedef struct adj_list adj_list;
struct adj_list {
    int item;
    struct adj_list *next;
};

typedef struct graph graph;
struct graph {
    struct adj_list *vertices[MAX_SIZE];
    short visited[MAX_SIZE];
};

adj_list* create_adj_list(int item){
    adj_list *new_adj_list = malloc(sizeof(adj_list));
    new_adj_list->item = item;
    new_adj_list->next = NULL;
    return new_adj_list;
}

graph* create_graph(){
    graph *graph = malloc(sizeof(graph));
    int i;

    for (i = 1;i <= MAX_SIZE-1; i++){
        graph->vertices[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void add_edge(graph *graph, int vertex1, int vertex2){
    adj_list *vertex = create_adj_list(vertex2);
    vertex->next = graph -> vertices[vertex1];
    graph->vertices[vertex1] = vertex;
}

void dfs(graph *graph, int source){
    graph->visited[source] = 1;
    printf("%d\n", source);

    adj_list *adj_list = graph->vertices[source];

    while (adj_list != NULL){
        if (!graph->visited[adj_list->item]){
            dfs(graph,adj_list->item);
        }
        adj_list = adj_list->next;
    }
}

int main(int argc, char *argv[])
{
    graph *undirected_graph = create_graph();

    add_edge(undirected_graph,1,2);
    add_edge(undirected_graph,1,5);
    add_edge(undirected_graph,2,5);
    add_edge(undirected_graph,2,3);
    add_edge(undirected_graph,2,4);
    add_edge(undirected_graph,3,4);
    add_edge(undirected_graph,4,5);

    return EXIT_SUCCESS;
}
