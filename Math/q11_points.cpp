#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

void solve(){
  ll n; cin>>n;
  vector<pair<ll,ll>> v(n);
  vector<pair<ll,ll>> sum(n);
  for(ll i=0; i<n; i++)
  {
    cin>>v[i].first>>v[i].second;
    if( i==0 ){
      sum[i].first = v[i].first;
      sum[i].second = v[i].second;
    }
    else{
      sum[i].first = sum[i-1].first+v[i].first;
      sum[i].second = sum[i-1].second+v[i].second;
    }
  }

  ll res = 0;
  for(ll i=0; i<n; i++)
  {
    res+=(v[i].first*v[i].first*(n-1)) + (v[i].second*v[i].second*(n-1));
    res -= (2*v[i].first*(sum[n-1].first-sum[i].first)) + (2*v[i].second*(sum[n-1].second-sum[i].second));
  }

  cout<<res<<endl;
}

int main()
{
   solve();
    return 0;
}