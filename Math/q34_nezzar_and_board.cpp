#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

void solve(){
  ll n,k; cin>>n>>k;
  ll g = 0;
  vector<ll> v(n);
  for(int i=0; i<n; i++)
  {
    cin>>v[i];
    g = __gcd(g,v[i]);
  }

  if( k%g ) {
    cout<<"NO"<<endl;
    return;
  }

  ll gdash = __gcd(g,k);
  if( (gdash%n)%(g%n)!=0 ) {
    cout<<"No"<<endl;
    return;
  }
  

  ll y = (gdash%n)/(g%n);

  if( (gdash - y*g)%n!=0 ){
    cout<<"NO"<<endl;
    return;
  }

  cout<<"YES"<<endl;

}

int main()
{
    ll t; cin>>t;
    while( t-- ){
     solve();
    }
    return 0;
}