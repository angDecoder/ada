#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> par(N);
vector<int> size(N);

void make( int v ){
  par[v] = v;
  size[v] = 1;
}

int find( int v ){
  if( par[v]==v ) return v;
  return par[v] = find(par[v]);
}

void _union( int a, int b ){
  a = find(a);
  b = find(b);
  if( a==b ) return;
  if( size[a]<size[b] ) swap(a,b);
  par[b] = a;
  size[a] += size[b];
}

int main()
{
  
    
  return 0;
}