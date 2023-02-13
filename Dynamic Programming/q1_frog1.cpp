#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

void solve(){
  int n; cin>>n;
  vector<int> h(n);
  for(int i=0; i<n; i++)
  {
    cin>>h[i];
  }
  vector<int> cost(n);
  cost[0] = 0;
  for(int i=1; i<n; i++)
  {
    cost[i] = cost[i-1] + abs(h[i]-h[i-1]);
    if( i>1 )
      cost[i] = min( cost[i],cost[i-2] + abs(h[i]-h[i-2]) );
  }

  cout<<cost[n-1]<<endl;

}

int main()
{
  solve();
  return 0;
}