#include<stdio.h>
#define MAX 100
int visited[MAX];

void DFS(int Graph[MAX][MAX], int n, int vertex){
    visited[vertex] = 1;
    printf("%d ", vertex);
    for(int i = 0; i < n; i++){
        if(Graph[vertex][i] == 1 && !visited[i]){
            DFS(Graph, n, i);
        }
    }
}

int main(){
    int n, startVertex;
    int Graph[MAX][MAX];
    printf("Enter the number of vertices:\n");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &Graph[i][j]);
        }
    }
    
    for(int i = 0; i < n; i++){
        visited[i] = 0;
    }
    printf("Enter the start Vertex:\n");
    scanf("%d", &startVertex);
    DFS(Graph, n, startVertex);
    printf("\n");
    return 0;
}