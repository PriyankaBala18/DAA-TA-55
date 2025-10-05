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
                for(int i=0;i<N;i++)
                    bestPath[i]=path[i];
                bestPath[N]=0;
            }
        }
        return;
    }
    for(int city=0;city<N;city++) {
        if(!visited[city]&&graph[path[level-1]][city]>0) {
            visited[city]=1;
            path[level]=city;
            tsp(graph,visited,path,level+1,cost+graph[path[level-1]][city]);
            visited[city]=0;
        }
    }
}
int main() {
    int graph[N][N]={
        {0,5,8,7},
        {5,0,4,6},
        {8,4,0,3},
        {7,6,3,0}
    };
    int visited[N]={0};
    int path[N+1];
    path[0]=0; 
    visited[0]=1;
    tsp(graph,visited,path,1,0);
    printf("\nShortest Path:");
    for(int i=0;i<=N;i++) {
        printf("%c",'D'+bestPath[i]);
        if(i!=N) printf("→");
    }
    printf("\nMinimum Cost:%d km\n",minCost);
    return 0;
}
