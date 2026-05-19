#include<iostream>
using namespace std;

class Graph{
    int vertices;
    int adjMatrix[100][100];

public:
    Graph(int v){
        vertices = v;
        
        for(int i=0;i<vertices;i++){
            for(int j=0;j<vertices;j++){
                adjMatrix[i][j]=0;
            }
        }
    }

    void addEdge(int u,int v){
        adjMatrix[u][v]=1;
        adjMatrix[v][u]=1;
    }

    void display() {

        for(int i=0;i<vertices;i++){
            for(int j=0;j<vertices;j++){
                cout<<adjMatrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    int n;
    cin >> n;
    Graph g(n);
    int u, v;

    do{
        cin>>u>>v;
        if(u!=-1 && v!=-1){
            g.addEdge(u,v);
        }

    }while(u!=-1 && v!=-1);
    g.display();
    return 0;
}