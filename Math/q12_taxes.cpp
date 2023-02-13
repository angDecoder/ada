#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

bool prime( ll n ){
  for(ll i=2; i*i<=n; i++)
  {
    if( n%i==0 ) return false;
  }

  return true;
}

void solve(){
  ll n; cin>>n;

  if( n%2==0 and n!=2 )
    cout<<2<<endl;
  else if( prime(n) )
    cout<<1<<endl;
  else if( prime(n-2) )
    cout<<2<<endl;
  else 
    cout<<3<<endl;
  
}

int main()
{
  solve();
    return 0;
}