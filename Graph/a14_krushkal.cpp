#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> par(N),size(N);
vector<vector<pair<int,int>>> graph;
int n,e;

void make( int i ){
  par[i] = i;
  size[i] = 1;
}

int find( int i ){
  if( par[i]==i ) return i;
  else par[i] = find(par[i]);
}

void _union( int a, int b ){
  a = find(a);
  b = find(b);
  if( a==b ) return ;
  if( size[a]<size[b] ) swap(a,b);
  size[a] += size[b];
  par[b] = a;
}

void kruskal(){
  vector<pair<int,pair<int,int>>> p;
  for(int i=1; i<graph.size(); i++)
  {
    make(i);
    for( auto elem : graph[i] ){
      int v = elem.first;
      int wt = elem.second;
      p.push_back({wt,{i,v}});
    }
  }
  int totalCost = 0;
  sort(p.begin(),p.end());

  for( auto elem : p ){
    int u = elem.second.first;
    int v = elem.second.second;
    int wt = elem.first;
    if( find(u)==find(v) ) continue;
    cout<<u<<","<<v<<" --> "<<wt<<endl;
    _union(u,v);
    totalCost+=wt;
  }

  cout<<totalCost<<endl;
}

int main()
{
  cin>>n>>e;
  graph = vector<vector<pair<int,int>>>(n+1);
  for(int i=0; i<e; i++)
  {
    int u,v,wt; cin>>u>>v>>wt;
    graph[u].push_back({v,wt});
  }
  kruskal();
    
  return 0;
}