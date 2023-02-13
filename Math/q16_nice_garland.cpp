#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

void solve(){
  int n; cin>>n;
  string s; cin>>s;
  map<int,char> m;
  m[0] = 'G';
  m[1] = 'B';
  m[2] = 'R';
  vector<vector<int>> poss = {{0,1,2},{0,2,1},{1,2,0},{1,0,2},{2,0,1},{2,1,0}};

  int res = INT_MAX;
  int ans = -1;
  for(int i=0; i<poss.size(); i++)
  {
    int curr = 0;
    for(int j=0; j<n; j++)
    {
      if( s[j]!=m[poss[i][j%3]] ) curr++;
    }

    if( curr<res ){
      res = curr;
      ans = i;
    }
  }

  cout<<res<<endl;
  for(int i=0; i<n; i++)
  {
    cout<<m[ poss[ans][i%3] ];
  }
  cout<<endl;
}

int main()
{
    solve();
    return 0;
}