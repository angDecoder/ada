#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int
ll M = 1e9+7;

void solve(){
  ll n,m;
  cin>>n>>m;
  vector<string> str(n);
  for(ll i=0; i<n; i++)
  {
    cin>>str[i];
  }
  // vector<ll> hash(n,0);
  ll res = 1;
  for(ll j=0; j<m; j++)
  {
    set<char> st;
    for(ll i=0; i<n; i++)
    {
      st.insert(str[i][j]);
      // cout<<str[i][j]<<" ";
    }
    // cout<<st.size()<<endl;

    res = (res * st.size())%M;
  }

  cout<<res<<endl;
}

int main()
{
    solve();
    return 0;
}