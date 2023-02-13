#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> vis;

bool findLoop( int vertex,int par=0 ){
  vis[vertex] = true;
  cout<<vertex<<" "<<par<<endl;
  bool loopExists = false;
  for( auto elem : graph[vertex] ){
    if( vis[elem] and elem!=par ) {
      cout<<elem<<"--"<<vertex<<endl;
      loopExists = true;
    }
    if( !vis[elem] ) loopExists |= findLoop(elem,vertex);
  }

  return loopExists;
}

int main()
{
  int n, e;
  cin >> n >> e;
  graph = vector<vector<int>>(n + 1);
  vis = vector<int>(n + 1);
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    int b;
    cin >> b;
    graph[a].push_back(b);
    // graph[b].push_back(a);
  }

  cout<<findLoop(1,0)<<endl;

  return 0;
}