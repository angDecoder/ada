#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

void solve(){
  int n; cin>>n;
  int div = 0;
  for(int i=1; i*i<=n; i++)
  {
    if( n%i==0 ){
      div++;
      if( n/i!=i ) div++;
    }
  }
  cout<<div<<endl;
}

int main()
{
    solve();
    return 0;
}