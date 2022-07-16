#include<iostream>
#include<vector>

using namespace std;

#define VV 4

bool isSafeColor(int node, bool graph[VV][VV], int V, int c, vector<int> color){

    for(int i = 0; i < V; i++)
        if(graph[node][i] and c == color[i])
            return false;

    return true;
}

bool graphMColorUtil(int node, bool graph[VV][VV], int &V, int &m, vector<int> &color){

    // base case for recursion
    if(node == V)
        return true;

    for(int c = 1; c <= m; c++){

        if(isSafeColor(node, graph, V, c, color)){
            
            color[node] = c;

            if(graphMColorUtil(node + 1, graph, V, m, color))
                return true;

            color[node] = 0;

        }

    }

    return false;
}

bool graphMColor(bool graph[VV][VV], int V, int m){

    vector<int> color(V, 0);

    if(graphMColorUtil(0, graph, V, m, color)){
        return true;
    }

    return false;
}

int main(void){

    bool graph[VV][VV] = {
        { 0, 1, 1, 1 },
        { 1, 0, 1, 0 },
        { 1, 1, 0, 1 },
        { 1, 0, 1, 0 },
    };

    int m = 3;

    cout << graphMColor(graph, VV, m) << endl;
    
    return 0;
}