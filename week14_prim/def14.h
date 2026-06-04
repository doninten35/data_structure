#ifndef __DEF14_H__
#define __DEF14_H__
#define MAX_VERTICES 50
#define MAX_EDGES (MAX_VERTICES * (MAX_VERTICES-1) >> 1)

typedef struct {
	int vertex_a;
	int vertex_b;
	int weight;
}Edge;

typedef struct MatGraph {
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
	int visited[MAX_VERTICES];
	int number_of_edge;
	Edge edges[MAX_EDGES];
} MatGraph;

typedef struct NodeGraph {
	int vertex;
	int number_of_adj;
	struct NodeGraph* adj[MAX_VERTICES];
} NodeGraph;

typedef struct WeightMat {
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
	int sorting[MAX_VERTICES];

}WeightMat;
#endif