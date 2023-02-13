#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> vis;

void hamiltonian(){
  
}

int main()
{
  int n,e; cin>>n>>e;
  graph = vector<vector<int>>(n+1);
  vis = vector<int>(n+1);
  for(int i=0; i<e; i++)
  {
    int a,b; cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  hamiltonian();
    
  return 0;
}