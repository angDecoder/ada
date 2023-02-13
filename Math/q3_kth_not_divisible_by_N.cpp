// https://codeforces.com/problemset/problem/1352/C
#include<bits/stdc++.h>
using namespace std;
#define LL long long int
#define ul unsigned long long int

void solve(){
  LL n,k;
  cin>>n>>k;
  LL ans = k*n/(n-1);
  if( ans%n==0 )
    ans--;

  cout<<ans<<endl;

}

int main()
{
    LL t; cin>>t;
    while( t-- ){
     solve();
    }
    return 0;
}