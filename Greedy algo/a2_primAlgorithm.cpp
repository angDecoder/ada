#include<bits/stdc++.h>
using namespace std;
const int INF = 1e5;
vector<vector<pair<int,int>>> graph;
vector<int> weight(INF,INF);
vector<int> par(INF,-1);
vector<bool> vis (INF,false);
int n,e;

void primAlgorithm(){
  priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> q;
  q.push({0,1});
  par[1] = 0;

  while( !q.empty() ){
    pair<int,int> v = q.top();
    q.pop();
    if( vis[v.second] ) continue;
    vis[v.second] = true;

    for( auto elem : graph[v.second] ){
      if( vis[elem.first] ) continue;
      if( elem.second < weight[elem.first] ){
        weight[elem.first] = elem.second;
        par[elem.first] = v.second;
        q.push({elem.second,elem.first});
      }
    }
  }
}

void printPath(){
  for(int i=1; i<=n; i++)
  {
    int j = i;
    cout<<j<<"--> "<<j<<" ";
    while( par[j]!=0 ){
      cout<<par[j]<<" ";
      j = par[j];
    }
    cout<<endl;
  }
}

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

  primAlgorithm();

  printPath();
    
  return 0;
}
  
