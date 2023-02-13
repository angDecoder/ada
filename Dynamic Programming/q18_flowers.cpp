#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

int n; 
const int N = 2*100007;
vector<pair<ll,ll>> h(N);
vector<ll> v(N),tree(4*N),origToNew(N);

int indexToNode( int i ){
  return origToNew[i] + n;
}

ll query( int i ){
  int l = n;
  int r = indexToNode(i);

  ll res = -1;
  while( r>=l ){
    if( l&1 )
      res = max( res,tree[l++] );
    if( !(r&1) )
      res = max( res,tree[r--] );

    l = l/2;
    r = r/2;
  }

  return res;
}

void update( int i, ll val ){
  int node = indexToNode(i);
  tree[node] = val;
  node = node/2;

  while( node!=0 ){
    tree[node] = max(tree[node*2],tree[node*2+1]);
    node = node/2;
  }
}


ll solve(){
  ll res = -1;
  for(int i=0; i<n; i++)
  {
    ll curr = query(i)+v[i];
    res = max( res,curr );

    update(i,curr);
  }

  return res;
}

int main()
{
  cin>>n;
  for(int i=0; i<n; i++)
  {
    cin>>h[i].first;
    h[i].second = i;
  }
  for(int i=0; i<n; i++)
  {
    cin>>v[i];
  }

  sort( h.begin(),h.begin()+n );

  for(int i=0; i<n; i++)
  {
    origToNew[ h[i].second ]  = i;
  }

  cout<<solve()<<endl;
  
  return 0;
}