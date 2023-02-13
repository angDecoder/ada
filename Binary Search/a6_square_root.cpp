#include<bits/stdc++.h>
using namespace std;
#define LL long long int
#define ul unsigned long long int

void solve(){
  int n; cin>>n;
  vector<int> v(n,0); 
  for(int i=0; i<n; i++)
  {
    cin>>v[i];
  }
  int currMax = v[n-1];
  int ans = -1;
  for(int i=n-1; i>=0; i--)
  {
    currMax = max(currMax,v[i]);
    ans = max(ans,currMax-v[i]);
  }
  cout<<ans;
}

int main()
{
    LL t; cin>>t;
    while( t-- ){
     solve();
    }

    int a = 
    return 0;
}