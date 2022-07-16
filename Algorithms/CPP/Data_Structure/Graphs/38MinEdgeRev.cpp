#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<climits>

using namespace std;

#define iPair pair<int, int>

int getMinReverseEdge(vector<vector<int>> &edges, int E, int V, int src, int dst){

    unordered_map<int, vector<iPair>> adj;

    for(auto edge: edges){

        adj[edge[0]].push_back({edge[1], 0});
        adj[edge[1]].push_back({edge[0], 1});

    }

    vector<int> dist(V, INT_MAX);

    dist[src] = 0;

    set<iPair> st;

    st.insert({0, src});

    while(not st.empty()){

        auto top = *(st.begin());
        st.erase(st.begin());

        int nodeDist = top.first;
        int nodeVal = top.second;

        for(auto neighbor: adj[nodeVal]){

            if(nodeDist + neighbor.second < dist[neighbor.first]){

                auto record = st.find({dist[neighbor.first], neighbor.first});

                if(record != st.end())
                    st.erase(record);

                dist[neighbor.first] = nodeDist + neighbor.second;

                st.insert({dist[neighbor.first], neighbor.first});
            }

        }
    }

    return dist[dst];
}

int main(void){

    int V = 7;
 
    vector<vector<int>> edges = {{0, 1}, {2, 1}, {2, 3}, {5, 1}, {4, 5}, {6, 4}, {6, 3}};
    int E = edges.size();

    int src = 0;
    int dst = 6;
 
    cout << getMinReverseEdge(edges, E, V, 0, 6) << endl;


    return 0;
}