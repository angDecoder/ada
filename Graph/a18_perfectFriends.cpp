#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> vis;

int dfs( int v ){
  vis[v] = true;
  int ans=1;
  for( auto elem : graph[v] ){
    if( vis[elem] ) continue;
    ans+=dfs(elem);
  }

  return ans;
}

int main()
{
  int n,e; cin>>n>>e;
  graph = vector<vector<int>> (n);
  vis = vector<int> (n);
  vector<int> groups;
  for(int i=0; i<e; i++)
  {
    int a,b; cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }


  for( int i=0; i<n; i++ ){
    if( vis[i] ) continue;
    int a = dfs(i);
    groups.push_back(a);
  }
  int g = groups.size();
  int sum[g];
  sum[g-1] = groups[g-1];

  for(int i=g-2; i>=0; i--)
  {
    sum[i] = groups[i]+sum[i+1];
  }

  int ans = 0;
  for(int i=0; i<g-1; i++)
  {
    ans += groups[i]*sum[i+1];
  }

  cout<<ans<<endl;

  
  return 0;
}