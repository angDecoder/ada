#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

ll n;
vector<double> v(3007);
vector<vector<double>> dp(3007,vector<double>(3007,-1));
double solve( int i=0, int head=0 ){
  if( i>=n ){
    if( head>n-head ) return 1;
    else return 0;
  }

  if( dp[i][head]!=-1 ) return dp[i][head];

  dp[i][head] = v[i]*solve(i+1,head+1) + (1.0-v[i])*solve(i+1,head);
  return dp[i][head];
}

int main()
{
  cin>>n;
  for(int i=0; i<n; i++)
  {
    cin>>v[i];
  }
  // memset(dp,-1.00,sizeof(dp));
  cout<< fixed << setprecision(10)<<solve(0,0)<<endl;
}