#include<bits/stdc++.h>
using namespace std;
#define LL long long int
#define ul unsigned long long int

int n,m; 
vector<pair<int,int>> pos = {
  {0,1},{0,-1},{1,0},{-1,0},{-1,-1},{1,1},{1,-1},{-1,1}
};

bool isValid( int i, int j ){
  return i>=0 and j>=0 and i<n and j<m;

}

void solve(){
  cin>>n>>m;
  int arr[n][m];
  int maxNo = -1;
  queue<pair<int,int>> q;
  int level[n][m];
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<m; j++)
    {
      cin>>arr[i][j];
      level[i][j] = -1;
      maxNo = max(maxNo,arr[i][j]);
    }
  }

  for(int i=0; i<n; i++)
  {
    for(int j=0; j<m; j++)
    {
      if( arr[i][j]==maxNo ){
        q.push({i,j});
        level[i][j] = 0;
      }
    }
  }

  int ans = 0;

  while( !q.empty() ){
    pair<int,int> v = q.front();
    q.pop();

    for( auto elem : pos ){
      int i = elem.first + v.first;
      int j = elem.second + v.second;
      if( isValid(i,j) and level[i][j]==-1 ){
        q.push({i,j});
        level[i][j] = level[v.first][v.second]+1;
        ans = max(ans,level[i][j]);
      }
    }
  }

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