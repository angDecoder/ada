#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

ll n,k; 

bool check( ll mid ){
  return ( k*(k+1) )/2 - (mid*(mid-1))/2 - ( k-mid ) >= n;
}

ll findx( ll start, ll end ){

  while( end>start+1 ){
    ll mid = (start+end)/2;
    if( check(mid) )
      start = mid;
    else 
      end = mid-1;
  }

  if( check(end) ) return k-end+1;
  if( check(start) ) return k-start+1;
}

void solve(){
  cin>>n>>k;

  if( n==1 ){
    cout<<0<<endl;
    return;
  }
  if( k>=n ){
    cout<<1<<endl;
    return ;
  }

  ll maxPipes = (k*(k+1))/2 - 1 - (k-2);
  if( n>maxPipes ){
    cout<<-1<<endl;
    return;
  }

  ll x = findx(2,k);
  cout<<x<<endl;

}

int main()
{
  solve();
  return 0;
}