#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

ll n,k;
const int M = 1e9+7;
vector<vector<int>> graph(51,vector<int>(51));
// vector<vector<int>> mul(51,vector<int>(51));

vector<vector<int>> multiply( vector<vector<int>> a, vector<vector<int>> b ){
  vector<vector<int>> res(n,vector<int>(n,0));
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<n; j++)
    {
      for(int k=0; k<n; k++)
      {
        res[i][j] = (res[i][j] + (a[i][k] * b[k][j])%M)%M;
      }
    }
  }

  return res;
}

vector<vector<int>> matrixExpo( ll n ){

  if( n==1 )
    return graph;
  if( n==2 )
    return multiply(graph,graph);
  vector<vector<int>> res = matrixExpo(n/2);

  if( n%2==0 ) 
    return multiply(res,res);
  return multiply( graph,multiply( res,res ) );
}

int main()
{
  cin>>n>>k;
  for(int i=1; i<=n; i++)
  {
    for(int j=1; j<=n; j++)
    {
      cin>>graph[i][j];
    }
  }

  vector<vector<int>> res = matrixExpo(k);

  ll ans = 0;
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<n; j++)
    {
      cout<<res[i][j]<<" ";
    }
    cout<<endl;
  }

  cout<<ans<<endl;
  
  return 0;
}