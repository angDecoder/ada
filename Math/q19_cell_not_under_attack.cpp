#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

int n,m;
set<int> xarr;
set<int> yarr;

void solve( int i ){
  z total = n*n;
  int x,y; 
  cin>>x>>y;
  xarr.insert(x);
  yarr.insert(y);

  ll covered = (xarr.size()*n) + (yarr.size()*n) - (xarr.size()*yarr.size());
  cout<<max(total-covered,0ll)<<" ";
}

int main()
{
  cin>>n>>m;
  for(int i=1; i<=m; i++)
  {
    solve( i );
  }
  cout<<endl;
  return 0;
}