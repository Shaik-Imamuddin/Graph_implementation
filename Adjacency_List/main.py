class Node:
    def __init__(self, val):
        self.data = val
        self.addr = None

class Graph:
    def __init__(self, v):
        self.vertices = v
        self.adjlst = [None] * v

    def addEdge(self, u, v):

        newNode1 = Node(v)
        newNode1.addr = self.adjlst[u]
        self.adjlst[u] = newNode1

        newNode2 = Node(u)
        newNode2.addr = self.adjlst[v]
        self.adjlst[v] = newNode2

    def display(self):

        for i in range(self.vertices):
            print(i, "-> ",end="")
            temp = self.adjlst[i]

            while temp is not None:
                print(temp.data,end=" ")
                temp = temp.addr
            print()


n = int(input())
g = Graph(n)

while True:
    u,v = map(int,input().split())
    if u==-1 and v==-1:
        break
    g.addEdge(u,v)
g.display()