#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

void solve(){
  ll n; cin>>n;
  double sum = 0;
  ll maxelem = -1;
  for(ll i=0; i<n; i++)
  {
    ll a; cin>>a;
    sum+=a;
    maxelem = max(maxelem,a);
  }

  ll ans = ceil(sum/(n-1));
  cout<<max(ans,maxelem)<<endl;
}

int main()
{
  solve();
  return 0;
}
