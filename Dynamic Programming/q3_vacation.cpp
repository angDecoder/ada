#include<bits/stdc++.h>
using namespace std;

const int N = 2*1e5;
int n;
int v[N][3];
int dp[N][5];
int solve(){
  for(int i=n-2; i>=0; i--)
  {
    v[i][0] += v[i+1][1];
    v[i][1] += max( v[i+1][2],v[i+1][0] );
    v[i][2] += v[i+1][1];
  }

  int ans = -1;
  for(int j=0; j<3; j++)
  {
    ans = max(ans,v[0][j]);
  }

  return ans;
}

int solve1( int i=0, int pre=0 ){
  if( i==n )
    return 0;
  
  if( dp[i][pre]!=-1 )
    return dp[i][pre];
 
  int ans = -1;
  for(int j=0; j<3; j++)
  {
    if( j+1==pre ) continue;
    ans = max( ans,solve1(i+1,j+1)+v[i][j] );
  }
 
  return dp[i][pre] = ans;
}

int main()
{
  cin>>n;
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<3; j++)
    {
      cin>>v[i][j];
    }
  }
  memset(dp,-1,sizeof(dp));
  cout<<solve()<<endl;
    
  return 0;
}