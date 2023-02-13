#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

vector<vector<int>> graph;
vector<ll> dp(1e5+7,-1);

ll findPath( int i ){
  
  ll ans = 0;
  for( auto elem : graph[i] ){
    if( dp[elem]==-1 ) dp[elem] = findPath(elem);
    ans = max( ans,dp[elem]+1 );
  }

  return ans;
}

int main()
{
  int n,m; cin>>n>>m;
  graph.resize(n+1);
  for(int i=0; i<m; i++)
  {
    int a,b; cin>>a>>b;
    graph[a].push_back(b);
  }

  ll ans = 0;
  for(int i=1; i<=n; i++)
  {
    if( dp[i]==-1 ) dp[i] = findPath(i);
    ans = max( ans,dp[i] );
  }

  cout<<ans<<endl;
  
  return 0;
}