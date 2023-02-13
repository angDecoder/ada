#include<bits/stdc++.h>
using namespace std;
int n,e;
vector<vector<pair<int,int>>> graph;

int main()
{
  cin>>n>>e;
  graph = vector<vector<pair<int,int>>> (n+1);
  for(int i=0; i<e; i++)
  {
    int x,y,w; cin>>x>>y>>w;
    graph[x].push_back({y,w});
    graph[y].push_back({x,w});
  }
    
  return 0;
}