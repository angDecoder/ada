#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

void solve(){
  ll n,x,y;
  cin>>n>>x>>y;
  ll res;
  ll d;
  for(ll diff=1; diff<=y-x; diff++)
  {
    if( (y-x)%diff==0 ){
      // cout<<endl<<" diff:"<<diff;
      ll mid = ((y-x)/diff)+1;
      // cout<<" mid:"<<mid;
      if( mid>n ) continue;


      if( mid==n ){
        res = y;
        d = diff;
        break;
      }
      
      ll before = ceil((double(x-diff)/diff));
      // cout<<" before:"<<before;

      if( before+mid>=n ){
        res = y;
        d = diff;
        break;
      }

      ll after = n - (mid+before);
      // cout<<" after:"<<after;
      res = y+(after)*diff;
      d = diff;
      break;

    }
  }

  // cout<<endl;
  
  for(ll i=0; i<n; i++)
  {
    cout<<res<<" ";
    res-=d;
  }
  cout<<endl;
  
}

int main()
{
    ll t; cin>>t;
    while( t-- ){
     solve();
    }
    return 0;
}