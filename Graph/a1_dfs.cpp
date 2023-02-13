#include<bits/stdc++.h>
using namespace std;
/*
  DFS --> It stands for depth first search 
  It is an algorithm to traverse the graph using recursion
*/

vector<vector<int>> graph;
vector<bool> vis;

void dfs( int vertex ){
  cout<<vertex<<" ";
  vis[vertex] = true;

  for( auto elem : graph[vertex] ){
    if( !vis[elem] ) dfs(elem);
  }
}

int count_component(){
  int c = 0;
  for(int i=1; i<graph.size(); i++)
  {
    if( !vis[i] ) dfs(i),c++;
  }
  return c;
}

int main()
{
  int n; cin>>n;
  int e; cin>>e;
  graph = vector<vector<int>> (n+1);
  vis = vector<bool> (n+1,false);
  for(int i=0; i<e; i++)
  {
    int a,b; cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  // dfs(1);
  for(int i=1; i<=n; i++)
  {
    if( !vis[i] ) dfs(i);
  }
  
  // cout<<count_component();
    
    return 0;
}