#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

void solve(){
  ll n,k;
  cin>>n>>k;

  ll res = n;
  for(ll i=1; i*i<=n; i++)
  {
    if( n%i==0 ){
      ll b = n/i;
      if( i<=k )  
        res = min(res,b);

      if( b<=k )
        res = min(res,i);

    }
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