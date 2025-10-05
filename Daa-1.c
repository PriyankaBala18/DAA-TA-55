#include<stdio.h>
#include<limits.h>
#define N 4  
int minCost=INT_MAX;
int bestPath[N+1];
void tsp(int graph[N][N],int visited[],int path[],int level,int cost) {
    if(level==N) {
        if(graph[path[level-1]][0]>0) {
            int totalCost=cost+graph[path[level-1]][0];
            if(totalCost<minCost) {
                minCost=totalCost;
                for (int i=0;i<N;i++)
                    bestPath[i]=path[i];
                bestPath[N]=0; 
            }
        }
        return;
    }
    for(int city=0;city<N;city++) {
        if (!visited[city]&&graph[path[level-1]][city]>0) {
            visited[city]=1;
            path[level]=city;
            tsp(graph,visited,path,level+1,cost+graph[path[level-1]][city]);
             visited[city]=0;
        }
    }
}
int main() {
    int graph[N][N]={
        {0,10,15,20},
        {10,0,35,25},
        {15,35,0,30},
        {20,25,30,0}
    };
    int visited[N]={0};
    int path[N+1];
    path[0]=0;
    visited[0]=1;
    tsp(graph,visited,path,1,0);
    printf("\nShortest Path:");
    for(int i=0;i<=N;i++) {
        printf("%c",'A'+bestPath[i]);
        if(i!=N)
            printf("→");
    }
    printf("\nMinimum Cost:%d\n",minCost);
    return 0;
}
