#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* addr;
};

struct Graph {
    int vertices;
    struct Node** adjlst;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->addr = NULL;
    return newNode;
}

struct Graph* createGraph(int v){

    struct Graph* g = (struct Graph*)malloc(sizeof(struct Graph));
    g->vertices = v;
    g->adjlst = (struct Node**)malloc(v * sizeof(struct Node*));

    for(int i = 0; i < v; i++) {
        g->adjlst[i] = NULL;
    }
    return g;
}

void addEdge(struct Graph* g,int u,int v) {

    struct Node* newNode1 = createNode(v);
    newNode1->addr = g->adjlst[u];
    g->adjlst[u] = newNode1;

    struct Node* newNode2 = createNode(u);
    newNode2->addr = g->adjlst[v];
    g->adjlst[v] = newNode2;
}

void display(struct Graph* g){

    for(int i=0; i<g->vertices;i++){
        printf("%d - ",i);
        struct Node* temp = g->adjlst[i];

        while(temp!=NULL){
            printf("%d ", temp->data);
            temp = temp->addr;
        }
        printf("\n");
    }
}

int main() {

    int n;
    scanf("%d", &n);

    struct Graph* g = createGraph(n);

    int u,v;
    do{
        scanf("%d %d", &u, &v);
       
        if(u!=-1 && v!=-1) {
            addEdge(g,u,v);
       
        }

    }while(u!=-1 && v!=-1);

    display(g);
    return 0;
}