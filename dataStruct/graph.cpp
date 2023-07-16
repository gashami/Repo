#include <iostream>
#include<list>
#include<vector>

using namespace std;


class Graph{
    int V; //Number of vertices
    vector<list<int>> adj; //Pointer to an array containging adjacency lists

    public:
        Graph(int V);
        void addEdge(int v, int w);
        void BFS(int s);
};

Graph::Graph(int V){
    this->V = V;
    adj.resize(V);
}
void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}
void Graph::BFS(int s){
    vector<bool> visited;
    visited.resize(V, false);

    list<int> queue;
    visited[s] = true;
    queue.push_back(s);

    while(!queue.empty()){
        s = queue.front();
        cout << s <<" ";
        queue.pop_front();

        for(auto adjecency : adj[s]){
            if(!visited[adjecency]){
                visited[adjecency] = true;
                queue.push_back(adjecency);
            }
        }
    }
}

/*

int vertArr[20][20];
int count = 0;

void displayMatrix(int v){
    for(int i = 0; i < v; i ++){
        for(int j = 0; j < v; j++){
            cout <<vertArr[i][j] << " ";
        }
        cout <<endl;
    }
}
void add_Edge(int u, int v){
    vertArr[u][v] = 1;
    vertArr[v][u] = 1;
}

void AdjcencyMatrix(){
    int v = 6;
    add_Edge(0, 4);
    add_Edge(0, 3);
    add_Edge(1, 2);
    add_Edge(1, 4);
    add_Edge(1, 5);
    add_Edge(2, 3);
    add_Edge(2, 5);
    add_Edge(3, 5);
    add_Edge(4, 5);
    displayMatrix(v);
}
class graphList{
    public:
        list<int> *adjList;
        int n;

        graphList(int v){
            adjList = new list<int>[v];
            n=v;
        }
        void addEdge(int u, int v, bool bi){
            adjList[u].push_back(v);
            if(bi){
                adjList[v].push_back(u);
            }
        }
        void printGraph(){
            for(int i =0; i <n; i++){
                cout<< i << "-->";
                for(auto it:adjList[i]){
                    cout<< it <<" ";
                }
                cout<<endl;
            }
            cout<<endl;
        }
        

};
void AdjcencyList(){
    graphList g(5);
    g.addEdge(1, 2, true);
    g.addEdge(4, 2, true);
    g.addEdge(1, 3, true);
    g.addEdge(4, 3, true);
    g.addEdge(1, 4, true);
    g.printGraph();

}
*/
void BFSTraversal(){
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
}
int main(){
    //AdjcencyList();
    //AdjcencyMatrix();
     BFSTraversal();
    return 0;
}

