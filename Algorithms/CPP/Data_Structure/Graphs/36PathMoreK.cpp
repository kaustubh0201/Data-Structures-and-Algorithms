#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

#define iPair pair<int, int>

class Graph{

    public:
        int V;
        unordered_map<int, vector<iPair>> adj;

        Graph(int V) : V(V) {}

        void addEdge(int u, int v, int w){
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
};

bool moreThanKUtil(int node, unordered_map<int, int> &path, int k, unordered_map<int, vector<iPair>> &adj){

    if(k <= 0)
        return true;

    for(auto neighbor: adj[node]){

        if(path[neighbor.first] == 1)
            continue;

        if(neighbor.second >= k)
            return true;

        path[neighbor.first] = 1;

        if(moreThanKUtil(neighbor.first, path, k - neighbor.second, adj))
            return true;

        path[neighbor.first] = 0;
    }
    
    return false;
}

bool moreThanK(int src, int k, unordered_map<int, vector<iPair>> &adj){

    unordered_map<int, int> path;

    path[src] = 1;

    return moreThanKUtil(src, path, k, adj);
}



int main(void){

    int V = 9;
    Graph g(V);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    int src = 0;
    int k = 62;

    cout << moreThanK(src, k, g.adj) << endl;

    k = 60;

    cout << moreThanK(src, k, g.adj) << endl;

    return 0;
}