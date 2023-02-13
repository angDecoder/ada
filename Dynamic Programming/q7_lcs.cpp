#include<bits/stdc++.h>
using namespace std;

string s1,s2;
int dp[4000][4000];
string lcs(){

  for(int i=0; i<=s1.size(); i++)
  {
    for(int j=0; j<=s2.size(); j++)
    {
      if( i==0 || j==0 ) dp[i][j] = 0;
      else if( s1[i-1]==s2[j-1] ) dp[i][j] = dp[i-1][j-1]+1;
      else dp[i][j] = max( dp[i-1][j],dp[i][j-1] );
    }
  }
  string res = "";
  int i=s1.size(),j=s2.size();
  while( i>0 and j>0 ){
    if( s1[i-1]==s2[j-1] ) {
      res = s1[i-1] + res;
      i--,j--;
    }
    else if( dp[i-1][j]>=dp[i][j-1] )
      i--;
    else j--;
  }

  return res;

}

int main()
{
  cin>>s1>>s2;
  cout<<lcs()<<endl;
    
  return 0;
}