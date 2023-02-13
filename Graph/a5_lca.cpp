#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> vis;
vector<int> par;

void dfs( int vertex ){
  vis[vertex] = true;
  for( auto elem : graph[vertex] ){
    if( !vis[elem] ) {
      par[elem] = vertex;
      dfs(elem);
    }
  }
}

vector<int> findSeq( int a ){
  vector<int> seq;
  int b = a;
  while( b!=0 ){
    seq.push_back(b);
    b = par[b];
  }

  return seq;
}

int lca( int a, int b ){
  dfs(1);
  vector<int> seq_a = findSeq(a);
  vector<int> seq_b = findSeq(b);
  int i=seq_a.size()-1;
  int j=seq_b.size()-1;
  int ans = -1;
  while( i>=0 and j>=0 and seq_a[i]==seq_b[j] ){
    ans = seq_a[i];
    i--,j--;
  }
  return ans;
}

int main()
{
  int n,e; cin>>n>>e;
  graph = vector<vector<int>> (n+1);
  vis = vector<bool>(n+1);
  par = vector<int> (n+1);
  
  for(int i=0; i<e; i++)
  {
    int a,b; cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  par[1] = 0;

  int a,b; cin>>a>>b;
  cout<<lca(a,b)<<endl;

  return 0;
}