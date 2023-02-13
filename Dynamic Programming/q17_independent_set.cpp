#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

vector<vector<int>> graph(100007);
vector<pair<int,int>> dp(100007,{1,1});
vector<bool> vis(100007,false);
int n; 
ll M = 1e9+7;

pair<ll,ll> solve( int node, int par ){
  if( vis[node] )
    return dp[node];

  pair<int,int> ans = {1,1};
  vis[node] = true;

  for( auto child : graph[node] ){
    if( child==par )
      continue;

    auto p = solve(child,node);
    ans.first = ( ans.first*(p.first+p.second)%M )%M;
    ans.second = ( ans.second*p.first )%M;
  }

  return dp[node] = { ans.first,ans.second };
}

int main()
{
  cin>>n;
  for(int i=1; i<=n-1; i++)
  {
    int a,b; cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  auto p = solve(1,-1);

  cout<<(p.first+p.second)%M<<endl;
  
  return 0;
}