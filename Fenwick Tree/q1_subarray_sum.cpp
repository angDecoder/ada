#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
  long long g,l,r,s;
  Node( long long g,long long l, long long r, long long s  )
    : g(g),l(l),r(r),s(s) {};
  Node( long long val )
    : g(max(0LL,val)),l(max(0LL,val)),r(max(0LL,val)),s(val) {};

  friend Node operator+( Node a,Node b ){
    Node ans = Node(0);
    ans.g = max(a.g,max(b.g,a.r+b.l));
    ans.l = max(a.l,a.s+b.l);
    ans.r = max(b.r,b.s+a.r);
    ans.s = a.s+b.s;

    return ans;
  }
};

void build(){
  for(int i=1; i<=n; i++)
  {

  }
}

int n,q;
vector<Node> ftree;
vector<int> v;

int main()
{
  cin>>n>>q;
  v.resize(n+1);
  ftree.resize(n+1,Node(0));

  build();
    
  return 0;
}