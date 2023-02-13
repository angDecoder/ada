#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

void solve(){
  int n,k; cin>>n>>k;
  vector<int> h(n),cost(n);
  for(int i=0; i<n; i++)
  {
    cin>>h[i];
  }
  cost[0] = 0;
  for(int i=1; i<n; i++)
  {
    cost[i] = INT_MAX;
    for(int j=1; j<=k and i-j>=0; j++)
    {
      cost[i] = min( cost[i],cost[i-j]+abs( h[i]-h[i-j] ) );
    }
  }

  cout<<cost[n-1]<<endl;
}

int main()
{
  solve();
  return 0;
}