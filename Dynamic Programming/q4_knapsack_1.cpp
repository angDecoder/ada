#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int n;
const int N = 200;
int weight[N];
int value[N];
ll dp[N][(int)1e5];

ll knapsack( int i, int w ){
  if( i==n || w==0 )
    return 0;

  if( dp[i][w]!=-1 )
    return dp[i][w];

  ll ans = INT_MIN;
  if( w>=weight[i] )
    ans = max( ans,knapsack(i+1,w-weight[i])+value[i] );
  
  ans = max( ans,knapsack(i+1,w) );

  return dp[i][w] =  ans;

}

int main()
{
  int w;
  cin>>n>>w;
  for(int i=0; i<n; i++)
  {
    cin>>weight[i]>>value[i];
  }
  memset(dp,-1,sizeof(dp));
  cout<<knapsack(0,w)<<endl;
    
  return 0;
}