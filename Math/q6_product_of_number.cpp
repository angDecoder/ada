#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

void solve(){
  ll n; cin>>n;
  ll a=0,b=0,c=0;
  for(ll i=2; i*i*i<=n; i++)
  {
    if( n%i==0 ){
      a = i;
      break;
    }
  }
  if( a==0 ){
    cout<<"NO"<<endl;
    return;
  }

  ll m = n/a;
  for(ll i=a+1; i*i<=m; i++)
  {

    if( m%i==0 ) {
      b = i;
      c = m/i;
      break;
    }
  }

  if( a*b*c==n and (a!=b and a!=c and b!=c) ){
    cout<<"YES"<<endl;
    cout<<a<<" "<<b<<" "<<c<<endl;
  }
  else 
    cout<<"NO"<<endl;
}

int main()
{
    ll t; cin>>t;
    while( t-- ){
     solve();
    }
    return 0;
}