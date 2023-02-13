#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

ll m = 998244353 ;

void solve(){
  int n; cin>>n;
vector<ll> v1(n),v2(n);
  for(int i=0; i<n; i++)
  {
    cin>>v1[i];
  }

  for(int i=0; i<n; i++)
  {
    cin>>v2[i];
  }

  sort(v1.begin(),v1.end(),greater<int>());
  sort(v2.begin(),v2.end());

  ll res = 0;
  for(int i=0; i<n; i++)
  {
    res = ( res +  (v1[i]*v2[i]*(i+1)*(n-i))%m )%m;
  }
  cout<<res<<endl;
}

int main()
{
    solve();
    return 0;
}