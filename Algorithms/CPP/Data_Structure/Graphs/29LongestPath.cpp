#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

vector<int> topologicalSort(vector<vector<int>> &adj, int V){

    vector<int> inDegree(V, 0);

    for(int i = 0; i < V; i++){
        
        for(int neighbor: adj[i]){

            inDegree[neighbor]++;

        }

    }

    queue<int> q;

    for(int i = 0; i < V; i++){
        if(inDegree[i] == 0)
            q.push(i);
    }

    vector<int> ans;

    while(not q.empty()){

        int front = q.front(); q.pop();

        ans.push_back(front);

        for(int neighbor: adj[front]){

            inDegree[neighbor]--;

            if(inDegree[neighbor] == 0){
                q.push(neighbor);
            }

        }

    }

    return ans;
}

vector<int> longDistance(vector<vector<int>> adj[], int V){

    vector<int> dist(V, INT_MIN);

    vector<vector<int>> topAdj(V);

    for(int i = 0; i < V; i++){

        for(auto neighbor: adj[i]){

            topAdj[i].push_back(neighbor[0]);
            
        }

    }

    vector<int> topOrder = topologicalSort(topAdj, V);

    for(auto node: topOrder){

        if(dist[node] != INT_MIN){

            for(auto neighbor: adj[node]){

                if(dist[neighbor[0]] < dist[node] + neighbor[1])
                    dist[neighbor[0]] = dist[node] + neighbor[1];

            }

        }

    }

    return dist;

}

int main(void){


    return 0;
}