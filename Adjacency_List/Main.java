import java.util.Scanner;

class Node{
    int data;
    Node addr;

    Node(int val){
        data = val;
        addr = null;
    }
}

class Graph{
    int vertices;
    Node adjlst[];

    Graph(int v){
        vertices = v;
        adjlst = new Node[v];
    }

    void addEdge(int u,int v){
        
        Node newNode1 = new Node(v);
        newNode1.addr = adjlst[u];
        adjlst[u] = newNode1;

        Node newNode2 = new Node(u);
        newNode2.addr = adjlst[v];
        adjlst[v] = newNode2;
    }

    void display(){
        for(int i=0;i<vertices;i++){
            System.out.print(i+" -> ");

            Node temp = adjlst[i];

            while(temp!=null){
                System.out.print(temp.data+" ");
                temp=temp.addr;
            }
            System.out.println();
        }
    }
}

public class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        Graph g = new Graph(n);

        int u,v;

        do{
            u = sc.nextInt();
            v = sc.nextInt();

            if(u!=-1 && v!=-1)
                g.addEdge(u,v);
        }while(u!=-1 && v!=-1);

        g.display();
    }
}