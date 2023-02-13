#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> depth, height;

void dfs_tree( int vertex, int parent = 0 ){
  cout<<vertex<<" ";
  for( auto elem : graph[vertex] ){
    if( elem == parent ) continue;
    depth[elem] = depth[vertex]+1;
    dfs_tree(elem,vertex);
    height[vertex] = max( height[vertex],height[elem]+1 );
  }
}

int main()
{
  int n; cin>>n;
  graph = vector<vector<int>> (n+1);
  depth = height = vector<int> (n+1,0);

  for(int i=0; i<n-1; i++)
  {
    int a,b; cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  for(int i=1; i<=n; i++)
  {
    cout<<i<<"--> ";
    for( auto elem : graph[i] ){
      cout<<elem<<" ";
    }
    cout<<endl;
  }
  dfs_tree(9);
  // cout<<endl;
  // for(int i=1; i<graph.size(); i++)
  // {
  //   cout<<i<<"--> "<<depth[i]<<" "<<height[i]<<endl;
  // }
    
    return 0;
}