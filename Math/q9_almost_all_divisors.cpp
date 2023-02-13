#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

void solve(){
  ll n; cin>>n;
  vector<ll> arr(n);
  for(ll i=0; i<n; i++)
  {
    cin>>arr[i];
  }

  sort( arr.begin(),arr.end() );
  vector<ll> res;
  ll ans = arr[0]*arr[n-1];
  for(ll i=2; i*i<=ans; i++)
  {
    if( ans%i!=0 ) continue;

    res.push_back(i);
    if( ans/i!=i )
    res.push_back(ans/i);
  }

  sort(res.begin(),res.end());

  for(ll i=0; i<n; i++)
  {
    if( res[i]!=arr[i] ){
      cout<<-1<<endl;
      return;
    }
  }

  cout<<ans<<endl;
}

int main()
{
  ll t; cin>>t;
  while( t-- ){
    solve();
  }
  return 0;
}