#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> graph;
vector<int> vis;
int n,e; 

bool detectCycle( int v=1, int par=0 ){
  cout<<v<<" "<<par<<endl;
  bool ans = false;
  vis[v] = true;
  for( auto elem : graph[v] ){
    if( vis[elem.first] and elem.first!=par ) return true;
    if( vis[elem.first] ) continue;
    ans = ans | detectCycle(elem.first,v);
  }

  return ans;
}

int main()
{
  cin>>n>>e;
  graph = vector<vector<pair<int,int>>>(n+1);
  vis = vector<int> (n+1);

  for(int i=0; i<e; i++)
  {
    int u,v,wt; cin>>u>>v>>wt;
    graph[u].push_back({v,wt});
  }
  cout<<detectCycle()<<endl;

  return 0;
}