#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

int n;
vector<ll> v(3007);
vector<vector<ll>> dp(3007,vector<ll>(3007,-1));

ll solve( int i=0, int j=n-1 ){
  if( j<i ) return 0;
  if( i==j ) return v[i];

  if( dp[i][j]!=-1 )
    return dp[i][j];

  return dp[i][j] = max( v[i]+min( solve(i+2,j),solve(i+1,j-1) ),v[j] + min(solve(i+1,j-1),solve(i,j-2)) );
}

int main()
{
  cin>>n;
  ll sum = 0;
  for(int i=0; i<n; i++)
  {
    cin>>v[i];
    sum+=v[i];
  }
  ll a = solve(0,n-1);
  ll b = sum - a;

  cout<<(a-b)<<endl;
}