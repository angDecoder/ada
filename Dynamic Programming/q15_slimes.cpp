#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

int n;
vector<ll> v(407),pre(407);
vector<vector<ll>> dp(407,vector<ll>(407,-1));
ll solve( int i, int j ){
  if( i==j or i>j ) 
    return 0;
  
  if( dp[i][j]>=0 ) 
    return dp[i][j];

  ll ans = __LONG_LONG_MAX__;
  for(int k=i; k<j; k++)
  {
    ans = min( ans,solve(i,k)+solve(k+1,j) );
  }

  return dp[i][j] =  ans + pre[j] - ( i?pre[i-1]:0 );
}

int main()
{
  cin>>n;
  for(int i=0; i<n; i++)
  {
    cin>>v[i];
    pre[i] = v[i] + ( i?pre[i-1]:0 );
  }
  cout<<solve(0,n-1)<<endl;
  return 0;
}