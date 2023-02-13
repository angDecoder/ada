#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll weight[107],value[107];
ll n,w; 
const int INF = 1e9+7;
vector<ll> dp((int)1e5+7,INF);
ll maxvalue = 0;

ll knapsack2(){
  for(int j=0; j<n; j++)
  {
    for(int i=maxvalue; i>=0; i--)
    {
      if( dp[i]==INF or i+value[j]>maxvalue or dp[i]+weight[j]>w ) continue;
      dp[i+value[j]] = min( dp[i+value[j]],dp[i]+weight[j] );
    }
  }

  ll ans = -1;
  for(int i=0; i<=maxvalue; i++)
  {
    // cout<<dp[i]<<" ";
    if( dp[i]!=INF ) ans = i;
  }
  cout<<endl;

  return ans;

}

int main()
{
  cin>>n>>w;
  for(int i=0; i<n; i++)
  {
    cin>>weight[i]>>value[i];
    maxvalue+=value[i];
  }
  dp[0] = 0;
  cout<<knapsack2();
    
  return 0;
}