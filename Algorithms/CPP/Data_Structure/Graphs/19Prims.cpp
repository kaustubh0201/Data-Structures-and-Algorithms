#include<iostream>
#include<vector>
#include<climits>
#include <numeric>

using namespace std;

int PrimsAlgo(vector<vector<int>> adj[], int V){

    vector<int> parent(V);
    vector<int> dist(V);
    vector<int> mst(V);

    for(int i = 0; i < V; i++){

        parent[i] = -1;
        dist[i] = INT_MAX;
        mst[i] = 0;

    }

    dist[0] = 0;

    for(int i = 0; i < V; i++){

        int mini = INT_MAX;
        int u;

        for(int v = 0; v < V; v++){
            
            if(mst[v] == 0 and mini < dist[v]){
                mini = dist[v];
                u = v;
            }

        }

        mst[u] = 1;

        for(auto neighbor: adj[u]){

            if(mst[neighbor[0]] == 0 and neighbor[1] < dist[neighbor[0]]){
                dist[neighbor[0]] = neighbor[1];
                parent[neighbor[0]] = u;
            }

        }
    }

    return accumulate(dist.begin(), dist.end(), 0);

}

int main(void){

    return 0;
}