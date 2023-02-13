#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<vector<pair<int,int>>> graph;
vector<bool> vis(N);
vector<int> par(N);

void printPath( int i ){
  if( i==0 ) return;
  cout<<i<<" ";
  return printPath(par[i]);
}

void primAlgo(){
  int totalCost = 0;
  set<pair<int,pair<int,int>>> pq; // wt, vertex, parent
  pq.insert({0,{1,0}});

  while( !pq.empty() ){
    int v = (*pq.begin()).second.first;
    int p = (*pq.begin()).second.second;
    int wt = (*pq.begin()).first;
    pq.erase(pq.begin());

    if( vis[v] ) continue;
    vis[v] = true;
    par[v] = p;
    totalCost+=wt;

    for( auto elem : graph[v] ){
      if( vis[elem.first] ) continue;
      pq.insert({elem.second,{elem.first,v}});
    }
  }
  cout<<totalCost<<endl;
  for(int i=1; i<graph.size(); i++)
  {
    cout<<i<<" --> ";
    printPath(i);
    cout<<endl;
  }
}

int main()
{
  int n,e; cin>>n>>e;
  graph = vector<vector<pair<int,int>>> (n+1);
  for(int i=0; i<e; i++)
  {
    int a,b,wt; cin>>a>>b>>wt;
    graph[a].push_back({b,wt});
    graph[b].push_back({a,wt});
  }
  primAlgo();
  return 0;
}