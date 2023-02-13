#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

const int M = 998244353;

void solve(){
  int n,m; cin>>n>>m;
  string s1,s2; cin>>s1>>s2;
  
  reverse(s1.begin(),s1.end());
  reverse(s2.begin(),s2.end());

  vector<ll> v(m,0);
  int pow = 1;
  for(int i=0; i<min(n,m); i++)
  {
    if( i!=0 )
      v[i] = v[i-1];
    v[i] = ( v[i]+pow*(s1[i]-'0') )%M;
    pow = (pow*2)%M;
  }

  for(int i=n; i<m; i++)
  {
    v[i] = v[i-1];
  }

  ll res = 0;
  for(int i=0; i<m; i++)
  {
    if( s2[i]=='0' ) continue;
    res = ( res+v[i] )%M;
  }

  cout<<res<<endl;

}

int main()
{
  solve();
    return 0;
}