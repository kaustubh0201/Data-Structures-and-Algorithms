#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

#define iPair pair<int, int>

class Graph{

    public:
        int V;
        unordered_map<int, vector<int>> adj;

        Graph(int V) : V(V) {}

        void addEdge(int u, int v){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
};

vector<int> graphColor(int V, unordered_map<int, vector<int>> &adj){

    // color of each of the node in the graph
    vector<int> result(V, -1);

    // utility array that will be used to know which colors are left for use
    vector<int> remaining(V, 0);

    // putting color 0 for the first graph node
    result[0] = 0;

    // iterating through all the other nodes to set their color
    for(int u = 1; u < V; u++){

        // iterating through the nodes to know which all color are taken
        for(auto neighbor: adj[u]){

            if(result[neighbor] != -1)
                remaining[result[neighbor]] = 1;

        }

        // getting the first available color from the remaining array
        int cr;
        for(cr = 0; cr < V; cr++)
            if(remaining[cr] == 0)
                break;

        // setting the current color in the result
        result[u] = cr;

        // reinstating the remaining color array
        for(auto neighbor: adj[u]){

            if(result[neighbor] != -1) 
                remaining[result[neighbor]] = 0;

        }

    }

    for(auto x: result)
        cout << x << " ";
    cout << endl;

    return result;

}

int main(void){

    int V = 5;
    Graph g1(5);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(1, 3);
    g1.addEdge(2, 3);
    g1.addEdge(3, 4);

    graphColor(V, g1.adj);

    Graph g2(5);
    g2.addEdge(0, 1);
    g2.addEdge(0, 2);
    g2.addEdge(1, 2);
    g2.addEdge(1, 4);
    g2.addEdge(2, 4);
    g2.addEdge(4, 3);

    graphColor(V, g2.adj);


    return 0;
}