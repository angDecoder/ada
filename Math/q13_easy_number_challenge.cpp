#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll M = 1<<30;

void solve(){
  ll a,b,c;
  cin>>a>>b>>c;
  vector<ll> v(a*b*c+1,2);
  v[1] = 1;
  for(ll i=2; i<v.size(); i++)
  {
    for(ll j=2*i; j<v.size(); j+=i)
      v[j] = (v[j]+1)%M;
  }

  ll res = 0;
  for(ll i=1; i<=a; i++)
  {
    for(ll j=1; j<=b; j++)
    {
      for(ll k=1; k<=c; k++)
      {
        res = (res + v[i*j*k])%M;
      }
    }
  }

  cout<<res<<endl;

}

int main()
{
  solve();
    
  return 0;
}