#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

ll M = 1e9+7;

ll solve(){
  ll n,k; cin>>n>>k;
  vector<ll> dp(k+2,0);
  dp[0] = 1;

  for(int i=0; i<n; i++)
  {
    ll lim; cin>>lim;
    vector<ll> fake(k+2,0);
    for(ll used=k; used>=0; used--)
    {
      int l = used+1;
      int r = min(lim+used,k)+1;
      fake[l] = (fake[l] + dp[used])%M;
      fake[r] = (fake[r] - dp[used]+M)%M;
    }

    for(int i=0; i<=k+1; i++)
    {
      fake[i] = (fake[i] + ( i?fake[i-1]:0 ))%M;
      dp[i] = (dp[i] + fake[i])%M;
    }

  }

  // for(int i=0; i<=k; i++)
  // {
  //   cout<<dp[i]<<" ";
  // }
  // cout<<endl;

  return dp[k];
}

int main()
{
  cout<<solve()<<endl;
  return 0;
}