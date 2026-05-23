#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *addr;

    Node(int val){
        data = val;
        addr = nullptr;
    }
};

class Graph{
    int vertices;
    Node **adjlst;

public:
    Graph(int v){
        vertices = v;
        adjlst = new Node*[vertices];

        for(int i = 0; i < vertices; i++) {
            adjlst[i] = NULL;
        }
    }

    void addEdge(int u, int v) {
        Node* newNode1 = new Node(v);
        newNode1->addr = adjlst[u];
        adjlst[u] = newNode1;

        Node* newNode2 = new Node(u);
        newNode2->addr = adjlst[v];
        adjlst[v] = newNode2;
    }

    void display(){
        for(int i = 0; i < vertices; i++) {
            cout << i << " - ";

            Node* temp = adjlst[i];

            while(temp != NULL) {
                cout << temp->data << " ";
                temp = temp->addr;
            }
            cout << endl;
        }
    }

};


int main(){
    int n;
    cin>>n;

    Graph g(n);

    int u,v;

    do{
        cin>>u>>v;
        if(u!=-1 && v!=-1){
            g.addEdge(u,v);
        }
    }while(u!=-1 && v!=-1);
    
    g.display();
    return 0;
}