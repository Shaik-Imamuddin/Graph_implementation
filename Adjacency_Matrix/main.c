#include<stdio.h>

struct Graph{
    int vertices;
    int adjMatrix[100][100];
};

void intializeGraph(struct Graph *g,int v){
    g->vertices = v;

    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            g->adjMatrix[i][j]=0;
        }
    }
}

void addEdge(struct Graph *g,int u,int v){
    g->adjMatrix[u][v]=1;
    g->adjMatrix[v][u]=1;
}

void display(struct Graph *g){
    for(int i=0;i<g->vertices;i++){
        for(int j=0;j<g->vertices;j++){
            printf("%d ",g->adjMatrix[i][j]);
        }
        printf("\n");
    }
}


int main(){

    int n;
    scanf("%d",&n);

    struct Graph g;
    intializeGraph(&g ,n);

    int u,v;

    do{
        scanf("%d%d",&u,&v);
        if(u!=-1 && v!=-1){
            addEdge(&g,u,v);
        }
    }while(u!=-1 && v!=-1);   
    display(&g);
    return 0;
}