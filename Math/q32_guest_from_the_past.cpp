#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

void solve(){
  ll n,a,b,c;
  cin>>n>>a>>b>>c;
  if( a<b-c  and n>=a ){
    cout<<n/a<<endl;
  }
  else {
    ll res = 0;
     if( n>=b ){
      res = (n-b)/(b-c)+1;
      n -= (b-c)*res;
     }

     if( n>=a ) 
      res += n/a;
    
    cout<<res<<endl;
  }
}

int main()
{
  solve();
    return 0;
}