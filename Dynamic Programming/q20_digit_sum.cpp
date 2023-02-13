#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

string l;
int d;
int n; 
const int M = 1e9+7;

ll dp[10001][101][2];

ll digit_sum( int i, int rem, bool tight ){

  if( i==n-1 ){
    int ub = tight ? l[i]-'0' : 9;
    // int lb = 
    ll ans = 0;
    for(int dig=0; dig<=ub; dig++)
    {
      if( dig%d==rem ) ans++;
    }

    return ans;
  }

  if( dp[i][rem][tight]!=-1 )
    return dp[i][rem][tight];

  int ub = tight ? l[i] - '0' : 9;
  ll ans = 0;
  for(int dig=0; dig<=ub; dig++)
  {
    ll num = digit_sum(i+1,(2*d-(dig%d))%d,(tight and dig==ub));
    // cout<<dig<<" "<<num<<" "<<((tight and dig==ub))<<endl;
    ans = ( ans+num )%M;
  }

  return dp[i][rem][tight] =  ans;
}

int main()
{
  cin>>l;
  cin>>d;
  n = l.size();
  memset(dp,-1,sizeof(dp));
  // cout<<dp[100][10][1];
  // for(int i=0; i<100; i++)
  // {
  //   int rem = (2*d-(i%d))%d;
  //   cout<<i<<" "<<rem<<" "<<(i+rem)%d<<endl;
  // }

  cout<<digit_sum(0,0,true)-1;
  
  return 0;
}