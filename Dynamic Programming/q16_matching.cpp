#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

int n;
int lim = 1<<22;
int num;
vector<vector<int>> v(30,vector<int>(30));
vector<ll> dp(lim,0);

ll solve(){

  ll ans = 0;
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<n; j++)
    {
      if( v[i][j]==0 )
        continue;
      ans = ans + 
    }
  }
}

int main()
{
  cin>>n;
  
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<n; j++)
    {
      cin>>v[i][j];
    }
  }

  num = 1<<(n+1) - 1;
  dp[0][0] = 1;
  cout<<solve()<<endl;
  return 0;
}