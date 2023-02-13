#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> graph;
vector<int> cost;

void _01bfs(){
  deque<int> q;
  q.push_back(1);
  cost[1] = 0;

  while( !q.empty() ){
    int v = q.front();
    q.pop_front();

    for( auto &elem : graph[v] ){
      if( cost[v]+elem.second >= cost[elem.first] ) continue;

      if( elem.second ) q.push_back(elem.first);
      else q.push_front(elem.first);
      cost[elem.first] = cost[v]+elem.second;
    }
  }
}

int main()
{
  int n,e; cin>>n>>e;
  graph = vector<vector<pair<int,int>>> (n+1);
  cost = vector<int>(n+1,1e9);

  for(int i=0; i<e; i++)
  {
    int x,y; cin>>x>>y;
    if( x==y ) continue;
    graph[x].push_back({y,0});
    graph[y].push_back({x,1});
  }

  _01bfs();
  if( cost[n]==1e9 ) cost[n] = -1;
  cout<<cost[n]<<endl;
    
  return 0;
}