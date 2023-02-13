#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

void solve(){
  ll dest;
  cin>>dest;
  ll step = 0;
  while( (step*(step+1)/2)<dest ) step++;

  if( (step*(step+1)/2)-dest==1 )
    cout<<step+1<<endl;
  else 
    cout<<step<<endl;
}

int main()
{
    ll t; cin>>t;
    while( t-- ){
     solve();
    }
    return 0;
}