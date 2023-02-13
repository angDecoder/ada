#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> sum;

void dfs_tree( int vertex, int parent = 0 ){
  sum[vertex] = vertex;
  for( auto elem : graph[vertex] ){
    if( elem == parent ) continue;
    dfs_tree(elem,vertex);
    sum[vertex] += sum[elem];
  }
}

void maxSubtreeMultiply(){
  
  int ans = 0;
  for(int i=2; i<=graph.size(); i++)
  {
    int part1 = sum[i];
    int part2 = sum[1] - part1;
    ans = max( ans,part1*part2 );
  }

  cout<<ans;
}

int main()
{
  int n; cin>>n;
  
  graph = vector<vector<int>> (n+1);


  for(int i=0; i<n-1; i++)
  {
    int a,b; cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  dfs_tree(1);
    
  return 0;
}