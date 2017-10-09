#include <iostream>
#include <list>
#include <queue>
using namespace std;
class Graph{
  int v;
  list<int> *adj;
public:
  Graph(int v);
  void addEdge(int from,int to);
  void DFS(int start);
  void DFSUtil(int start,bool visited[]);
};
Graph::Graph(int v){
  this->v = v;
  adj = new list<int>[v];
}
void Graph::addEdge(int from,int to){
  adj[from].push_back(to);
}
void Graph::DFSUtil(int start,bool visited[]){
  visited[start] = true;
  cout << start << " ";
  for(list<int>::iterator i=adj[start].begin();i!=adj[start].end();++i){
    if(!visited[*i]) DFSUtil(*i,visited);
  }
}
void Graph::DFS(int start){
  bool visited[v] = {};
  DFSUtil(start,visited);
}
int main(){
  Graph g(4);
  g.addEdge(0,1);
  g.addEdge(0,2);
  g.addEdge(1,2);
  g.addEdge(2,0);
  g.addEdge(2,3);
  g.addEdge(3,3);
  cout << "Start from 0: ";
  g.DFS(2);
  cout << endl;
}
