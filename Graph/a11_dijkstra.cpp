#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<vector<pair<int,int>>> graph;
vector<bool> vis;
int n,e; 

void dijkstra( int source=1 ){
  set<pair<int,int>> pq; // cost,vertex
  pq.insert({0,source});

  while( !pq.empty() ){
    int v = (*pq.begin()).second;
    int cost = (*pq.begin()).first;
    pq.erase(pq.begin());

    if( vis[v] ) continue;
    vis[v] = true;
    cout<<v<<" --> "<<cost<<endl;

    for( auto elem : graph[v] ){
      if( vis[elem.first] ) continue;
      pq.insert({elem.second+cost,elem.first});
    }
  }
}


int main()
{
  cin>>n>>e;
  graph = vector<vector<pair<int,int>>>(n+1);
  vis = vector<bool> (n+1);

  for(int i=0; i<e; i++)
  {
    int u,v,wt; cin>>u>>v>>wt;
    graph[u].push_back({v,wt});
  }

  dijkstra();
    
  return 0;
}