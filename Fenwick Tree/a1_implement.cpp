#include<bits/stdc++.h>
using namespace std;

int n,q;
vector<long long> ftree,v;

long long getSum( int idx ){
  long long sum = 0;
  while( idx>0 ){
    sum+=ftree[idx];
    idx -= idx&(-1*idx);
  }

  return sum;
}

long long query( int l, int r ){
  return getSum(r) - getSum(l-1);
}

void build(){
  for(int i=1; i<=n; i++)
  {
    int idx = i-(i&(-1*i));
    ftree[i] = v[i] - v[idx];
  }
}

int main()
{
  cin>>n>>q;
  v.resize(n+1,0);
  ftree.resize(n+1,0);

  for(int i=1; i<=n; i++)
  {
    cin>>v[i];
    v[i] += v[i-1];
  }

  build();

  for(int i=0; i<q; i++)
  {
    int l,r;
    cin>>l>>r;
    cout<<query(l,r)<<endl;
  }
    
  return 0;
}