#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

bool solve(){
  int n,k; cin>>n>>k;
  vector<int> v(n);
  vector<bool> dp(k+1,false);
  for(int i=0; i<k; i++)
    cin>>v[i];

  dp[0] = false;
  for(int i=1; i<=k; i++)
  {
    for(int j=0; j<n; j++)
    {
      if( i-v[j]>=0 and dp[i-v[j]]==false ) {
        dp[i] = true;
        break;
      }
    }
  }

  // for(int i=0; i<=k; i++)
  // {
  //   cout<<dp[i]<<" ";
  // }
  // cout<<endl;

  return dp[k];
}

int main()
{
  if( solve() ) 
    cout<<"First"<<endl;
  else 
    cout<<"Second"<<endl;
}