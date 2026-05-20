import java.util.Scanner;

class Graph{
    int vertices;
    int adjMatrix[][];

    Graph(int v){
        vertices = v;
        adjMatrix = new int[v][v];
    }

    void addEdge(int u,int v){
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    void display(){
        for(int i=0;i<vertices;i++) {
            for(int j=0;j<vertices;j++) {
                System.out.print(adjMatrix[i][j]+" ");
            }
            System.out.println();
       }
    }
}

public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        Graph g = new Graph(n);
        int u,v;

        do{
            u = sc.nextInt();
            v = sc.nextInt();

            if(u!=-1 && v!=-1){
                g.addEdge(u,v);
            }
        }while(u!=-1 && v!=-1);
        g.display();
    }
}