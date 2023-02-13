#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> depth;
int d;

void dfs_tree( int vertex, int parent = 0 ){
  // cout<<vertex<<" ";
  for( auto elem : graph[vertex] ){
    if( elem == parent ) continue;
    depth[elem] = depth[vertex]+1;
    if( depth[elem]>depth[d] ) d = elem;
    dfs_tree(elem,vertex);
  }
}

int find_diameter( int n ){
  dfs_tree(1);
  depth.clear();
  depth = vector<int> (n+1,0);
  dfs_tree(d);
  return depth[d];
}

int main()
{
  int n; cin>>n;
  
  graph = vector<vector<int>> (n+1);
  depth  = vector<int> (n+1,0);


  for(int i=0; i<n-1; i++)
  {
    int a,b; cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  cout<<find_diameter(n);
  // dfs_tree(9);

    
    return 0;
}