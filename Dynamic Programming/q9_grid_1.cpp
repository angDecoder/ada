#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define ul unsigned long long int

int n,m;
ll dp[1007][1007] = {0};
const int mod = 1e9+7;

int grid1(){
  for(int i=1; i<=n; i++)
  {
    for(int j=1; j<=m; j++)
    {
      char c; cin>>c;
      if( c=='#' ) dp[i][j] = 0;
      else if( i==1 and j==1 ) dp[i][j] = 1;
      else dp[i][j] = (dp[i-1][j]%mod + dp[i][j-1]%mod)%mod;
      // cout<<dp[i][j]<<" ";
    }
    // cout<<endl;
  }


  return dp[n][m];
}

int main()
{
  cin>>n>>m;
  cout<<grid1()<<endl;
  
  return 0;
}
