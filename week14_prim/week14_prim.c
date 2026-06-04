#include <stdlib.h>
#include <stdio.h>
#include "def14.h"
#include <math.h>
#include <limits.h>

MatGraph* create_adj_mat()
{
    int i, j;

    MatGraph* g = (MatGraph*)malloc(sizeof(MatGraph));
    if (g != NULL) {
        g->n = 0;
        g->number_of_edge = 0;
        for (i = 0; i < MAX_VERTICES; i++) {
            for (j = 0; j < MAX_VERTICES; j++) {
                g->adj_mat[i][j] = INT_MAX;
            }
            g->visited[i] = 0;
        }
        for (i = 0; i < MAX_EDGES; i++) {
            g->edges[i].vertex_a = 0;
            g->edges[i].vertex_b = 0;
            g->edges[i].weight = INT_MAX;
        }
    }
    else {
        printf("error: create adj graph\n");
    }

    return g;
}

void insert_weight_edge_mat(MatGraph* g, int start, int end, int weight)
{
    g->edges[g->number_of_edge].weight = weight;
    g->edges[g->number_of_edge].vertex_a = start;
    g->edges[g->number_of_edge].vertex_b = end;
    g->number_of_edge++;
    if (g->adj_mat[start][start] == INT_MAX) {
        g->adj_mat[start][start] = 0;
        g->n++;
    }
    if (g->adj_mat[end][end] == INT_MAX) {
        g->adj_mat[end][end] = 0;
        g->n++;
    }
    g->adj_mat[start][end] = weight;
    g->adj_mat[end][start] = weight;
}

void make_weight_mat_graph(MatGraph* g)
{
    insert_weight_edge_mat(g, 0, 1, 29);
    insert_weight_edge_mat(g, 1, 2, 16);
    insert_weight_edge_mat(g, 2, 3, 12);
    insert_weight_edge_mat(g, 3, 4, 22);
    insert_weight_edge_mat(g, 4, 5, 27);
    insert_weight_edge_mat(g, 5, 0, 10);
    insert_weight_edge_mat(g, 6, 1, 15);
    insert_weight_edge_mat(g, 6, 3, 18);
    insert_weight_edge_mat(g, 6, 4, 25);
}



Edge find_min_edge(MatGraph* g)
{
    int i, j;
    int min_weight = INT_MAX;
    Edge min_edge;

    // 버그 3 수정: 안전한 초기화
    min_edge.vertex_a = -1;
    min_edge.vertex_b = -1;
    min_edge.weight = INT_MAX;

    for (i = 0; i < g->n; i++) {
        if (g->visited[i] == 1) {
            for (j = 0; j < g->n; j++) {
                if (g->visited[j] == 0 &&
                    min_weight > g->adj_mat[i][j] &&
                    g->adj_mat[i][j] != INT_MAX &&
                    i != j) {
                    min_weight = g->adj_mat[i][j];
                    min_edge.vertex_a = i;
                    min_edge.vertex_b = j;
                    min_edge.weight = min_weight;
                }
            }
        }
    }
    // 버그 3 수정: visited 중복 설정 제거
    return min_edge;
}

int* prim(MatGraph* g, int start)
{
    int i;
    int count = 0;
    Edge min_edge;
    int* result = (int*)malloc(sizeof(int) * g->n);

    // 버그 4 수정: 모든 원소 -1로 초기화
    for (i = 0; i < g->n; i++) result[i] = -1;

    g->visited[start] = 1;

    while (1) {
        count = 0;
        for (i = 0; i < g->n; i++) {
            if (g->visited[i] == 0) count++;
        }
        if (count == 0) break;

        min_edge = find_min_edge(g);
        g->visited[min_edge.vertex_b] = 1;  // 버그 3 수정: 여기서만 visited 설정
        result[min_edge.vertex_b] = min_edge.vertex_a;

        printf("%d %d %d\n", min_edge.vertex_a, min_edge.vertex_b, min_edge.weight);
    }
    return result;
}

void make_dijstra_graph(MatGraph* g)
{
    insert_weight_edge_mat(g, 0, 1, 7);
    insert_weight_edge_mat(g, 0, 4, 3);
    insert_weight_edge_mat(g, 0, 5, 10);
    insert_weight_edge_mat(g, 1, 2, 4);
    insert_weight_edge_mat(g, 1, 3, 10);
    insert_weight_edge_mat(g, 1, 4, 2);
    insert_weight_edge_mat(g, 1, 5, 6);
    insert_weight_edge_mat(g, 2, 3, 2);
    insert_weight_edge_mat(g, 3, 4, 11);
    insert_weight_edge_mat(g, 3, 5, 9);
    insert_weight_edge_mat(g, 3, 6, 4);
    insert_weight_edge_mat(g, 4, 6, 5);
}

void min_value_example(int* array, int length)
{
    int MAX= NULL;
    int min_value = MAX;
    int min_index = NULL;
    int i;
    for (i = 0; i < length; i++) {
        if (min_value > array[i]) {
            min_value = array[i];
            min_index = i;
        }
    }
}

int find_min_distance_vertex(int* distance, int* visited, int length)
{
    int min_weight = INT_MAX;
    int min_vertex = -1;
    int i;
    for (i = 0; i < length; i++) {
        if (distance[i] < min_weight && !visited[i]) {
            min_weight = distance[i];
            min_vertex = i;
        }
    }
    return min_vertex;
}

int* dijkstra(MatGraph* g, int start)
{
    int* distance = (int*)malloc(sizeof(int) * g->n);
    int* visited = (int*)malloc(sizeof(int) * g->n);
    int i, j;
    int min_vertex;
    for (i = 0; i < g->n; i++) {
        visited[i] = 0;
        distance[i] = g->adj_mat[start][i];
    }
    distance[start] = 0;
    visited[start] = 1;

    for (i = 0; i < g->n - 1; i++) {
        min_vertex = find_min_distance_vertex(distance, visited, g->n);
        visited[min_vertex] = 1;
        for (j = 0; j < g->n; j++) {
            if (!visited[j] && g->adj_mat[min_vertex][j] != INT_MAX) {
                if (distance[min_vertex] + g->adj_mat[min_vertex][j] < distance[j]) {
                    distance[j] = distance[min_vertex] + g->adj_mat[min_vertex][j];
                }
            }
        }
    }
    free(visited);
    return distance;
}

void test_floyd_using_dijkstra()
{
    // dijkstra를 이용
    MatGraph* g = create_adj_mat();
    int* distance = NULL;
    int floyd_array[MAX_VERTICES][MAX_VERTICES];
    int i, j;
    make_dijstra_graph(g);
    for (i = 0; i < g->n; i++) {
        distance = dijkstra(g, i);
        for (j = 0; j < g->n; j++) {
            floyd_array[i][j] = distance[j];
        }
    }
    for (i = 0; i < g->n; i++) {
        for (j = 0; j < g->n; j++) {
            printf("%2d ", floyd_array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void test_floyd_normal()
{
    {
        //배열을 이용
        int i, j, k;
        MatGraph* g = create_adj_mat();
        int* distance = NULL;
        int floyd_array[MAX_VERTICES][MAX_VERTICES];
        make_dijstra_graph(g);
        for (i = 0; i < g->n; i++) {
            for (j = 0; j < g->n; j++) {
                floyd_array[i][j] = g->adj_mat[i][j];
            }
        }
        for (k = 0; k < g->n; k++) {
            for (i = 0; i < g->n; i++) {
                for (j = 0; j < g->n; j++) {
                    if (floyd_array[i][k] + floyd_array[k][j] < floyd_array[i][j] &&
                        g->adj_mat[i][k] != INT_MAX && g->adj_mat[j][k] != INT_MAX) {
                        floyd_array[i][j] = floyd_array[i][k] + floyd_array[k][j];
                    }
                }
            }
        }
        //계산량을 줄이는 방법
       /* for (k = 0; k < g->n; k++) {
            for (i = 0; i < g->n; i++) {
                if (g->adj_mat[i][k] != INT_MAX) {
                    for (j = 0; j < g->n; j++) {
                        if (g->adj_mat[j][k] != INT_MAX) {
                            if (floyd_array[i][k] + floyd_array[k][j] < floyd_array[i][j]) {
                                floyd_array[i][j] = floyd_array[i][k] + floyd_array[k][j];
                            }
                        }
                    }
                }
            }
        }*/
        for (i = 0; i < g->n; i++) {
            for (j = 0; j < g->n; j++) {
                printf("%2d ", floyd_array[i][j]);
            }
            printf("\n");
        }
    }
}


void test_prim()
{
    int i;
    MatGraph* g = create_adj_mat();
    Edge min_edge;
    int* prim_result;
    make_weight_mat_graph(g);
    prim_result = prim(g, 0);
    for (i = 0; i < g->n; i++) {
        printf("%d ", prim_result[i]);
    }
    printf("\n");
    printf("\n");
}

void test_dijkstra()
{
    MatGraph* g = create_adj_mat();
    int* distance;
    int i;
    make_dijstra_graph(g);
    distance = dijkstra(g, 0);
    for (i = 0; i < g->n; i++) {
        printf("%d ", distance[i]);
    }
    printf("\n");
    printf("\n");
}


int main(void) {

    test_prim();
    test_dijkstra();
    test_floyd_using_dijkstra();
    test_floyd_normal();
}

