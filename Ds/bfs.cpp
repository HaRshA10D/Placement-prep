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
  void BFS(int start);
};
Graph::Graph(int v){
  this->v = v;
  adj = new list<int>[v];
}
void Graph::addEdge(int from,int to){
  adj[from].push_back(to);
}
void Graph::BFS(int start){
  bool visited[v] = {};
  queue<int> bfsQ;
  bfsQ.push(start);
  visited[start] = true;
  while(!bfsQ.empty()){
    int cur = bfsQ.front();
    cout << cur << " ";
    bfsQ.pop();
    for(list<int>::iterator i=adj[cur].begin();i!=adj[cur].end();++i){
      if(visited[*i] == false){
        visited[*i] = true;
        bfsQ.push(*i);
      }
    }
  }
  cout << endl;
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
  g.BFS(0);
}
