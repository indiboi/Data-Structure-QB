#include<stdio.h>
#define MAX 100
int visited[MAX];

void BFS(int Graph[MAX][MAX], int n, int vertex){
    int queue[MAX], front = -1, rear = -1; 
    visited[vertex] = 1;
    printf("%d ", vertex);
    queue[++rear] = vertex;
    if(front == -1){
        front = 0;
    }
    while(front <= rear){
        int current = queue[front++];
        for(int i = 0; i < n; i++){
            if(Graph[current][i] == 1 && !visited[i]){
                visited[i] = 1;
                printf("%d ", i);
                queue[++rear] = i;
            }
        }
    }
}

int main(){
    int n, startVertex; 
    int Graph[MAX][MAX];
    printf("Enter the number of vertices: \n");
    scanf("%d", &n);
    printf("Enter the relation of vertices through adjacency matrix:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &Graph[i][j]);
        }
    }
    for(int i = 0; i < n; i++){
        visited[i] = 0;
    }
    printf("Enter the starting vertex: \n");
    scanf("%d", &startVertex);
    BFS(Graph, n, startVertex);
    printf("\n");
    
}