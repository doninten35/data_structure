
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
//인접행렬
AdjGraph* create_adjacent(int size)

{
    AdjGraph* adj = (AdjGraph*)malloc(sizeof(AdjGraph));
    int i, j;
    if (size > MAX_VERTICES) {
        printf("크기가 최대 크기보다 클 수 없습니다. 최대 크기: %d\n", MAX_VERTICES);
        return NULL;

    }
    if (adj == NULL) {
        printf("error: create adjacent");
        return NULL;
    }
    else {
        adj->size = size;
        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++) {
                adj->adj_mat[i][j] = 0;
            }
        }
        return adj;
    }
    return adj;
}

void insert_edge_adj(AdjGraph* g, int start, int end)
{
    if (start < g->size || end < g->size) {
        g->adj_mat[start][end] = 1;
        g->adj_mat[end][start] = 1;
    }
    else {
        printf("error: insert edge\n");
    }
}
void print_adj_mat(AdjGraph* g)
{
    int i, j;
    for (i = 0; i < g->size; i++) {
        for (j = 0; j < g->size; j++) {
            printf("%2d ", g->adj_mat[i][j]);
        }
        printf("\n");
    }
}


/*void insert_vertex_adj(AdjGraph* g)
{
    if (g->size < MAX_VERTICES) {
        g->size++;
    }
    else {
        printf("error: insert vertex\n");
    }
}*/

//인접리스트
NodeGraph* create_node(int value)
{
    NodeGraph* g = (NodeGraph*)malloc(sizeof(NodeGraph));
    int i;
    if (g != NULL) {
        for (i = 0; i < MAX_VERTICES; i++) {
            g->adj[i] = NULL;
        }
        g->number_of_adj = 0;
        g->vertex = value;
    }
    return g;
}

int main(void)
{
    AdjGraph* adj = create_adjacent(4);
    insert_edge_adj(adj, 0, 1);
    insert_edge_adj(adj, 0, 2);
    insert_edge_adj(adj, 0, 3);
    insert_edge_adj(adj, 1, 2);
    print_adj_mat(adj);

    printf("graph\n");
    return 0;
}
    

  /*AdjGraph* adj = (AdjGraph*)malloc(sizeof(AdjGraph));

    int i, j;

    if (adj == NULL) 
    {
      printf("error: create adjacent");
    }
    else 
    {
      for (i = 0; i < MAX_VERTICES; i++) {
        for (j = 0; j < MAX_VERTICES; j++) {
          adj->adj_mat[i][j] = 0;
        }
      }
    }*/

    


