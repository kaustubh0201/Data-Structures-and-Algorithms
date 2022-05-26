#include<iostream>
#include<map>
#include<list>
#include<queue>

using namespace std;

template<typename T>
class graph{
  public:
    
    map<T, list<pair<T, int>>> adjList;

    void addEdge(T u, T v, int dist, bool bidirect = 1){
      
      adjList[u].push_back(make_pair(v, dist));

      if(bidirect){
        adjList[v].push_back(make_pair(u, dist));
      }
    }

    void printGraph(){
      
      for(auto x: adjList){
        cout << x.first << " : ";

        for(auto y: x.second){
          cout << " ( " << y.first << " , " << y.second << " ) ";
        }
        cout << endl;
      }

    }

};

int main(void){
  
  	graph<char> g;
	  g.addEdge('0', '1', 4, 0);
	  g.addEdge('0', '7', 8, 0);
	  g.addEdge('1', '7', 11, 0);
	  g.addEdge('1', '2', 8, 0);
	  g.addEdge('7', '8', 7, 0);
	  g.addEdge('2', '8', 2, 0);
	  g.addEdge('8', '6', 6, 0);
	  g.addEdge('2', '5', 4, 0);
	  g.addEdge('6', '5', 2, 0);
	  g.addEdge('2', '3', 7, 0);
	  g.addEdge('3', '3', 14, 0);
	  g.addEdge('3', '4', 9, 0);
	  g.addEdge('5', '4', 10, 0);
	  g.addEdge('7', '6', 1, 0);
	  g.printGraph();


  return 0;
}
