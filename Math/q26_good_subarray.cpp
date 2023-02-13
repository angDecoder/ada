#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

void solve(){
  int n; cin>>n;
  string s; cin>>s;
  ll sum = 0;
  map<ll,ll> m;
  m[0]++;
  for(int i=0; i<n; i++)
  {
    sum+= s[i]-'0';
    m[sum-(i+1)]++;
  }
  ll res = 0;
  for( auto elem : m ){
    ll num = elem.second;
    res += (num*(num-1))/2;
  }

  cout<<res<<endl;
}

int main()
{
    ll t; cin>>t;
    while( t-- ){
     solve();
    }
    return 0;
}