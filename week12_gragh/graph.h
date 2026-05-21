#ifndef  __DEF_GRAPH_H__
#define MAX_VERTICES 50

typedef struct AdjGraph{
int size;// 정점의 개수
int adj_mat[MAX_VERTICES][MAX_VERTICES];
} AdjGraph;


typedef struct NodeGraph{
int vertex;
int number_of_adj;
struct NodeGraph* adj[MAX_VERTICES];
} NodeGraph;


#endif