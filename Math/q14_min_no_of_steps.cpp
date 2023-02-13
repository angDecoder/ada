#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

ll M = 1e9+7;

void solve(){
  string s; cin>>s;
  ll n = s.size();
  ll bcount = 0;
  ll res = 0;
  for(ll j = n-1; j>=0; j--)
  {
    if( s[j]=='b' ) bcount++;
    else {
      res = (res + bcount)%M;
      bcount = (bcount*2)%M;
    }
  }

  cout<<res<<endl;
}

int main()
{solve();
    return 0;
}