// #include<bits/stdc++.h>
// using namespace std;

// vector<vector<int>> graph;
// vector<int> vis;

// void bfs( int source=1 ){
//   queue<int> q; 
//   q.push(source);

//   while( !q.empty() ){
//     int v = q.front();
//     q.pop();

//     if( vis[v] ) continue;
//     vis[v] = true;
//     cout<<v<<" ";

//     for(  auto elem : graph[v] ){
//       if( vis[elem] ) continue;
//       q.push(elem);
//     }

//   }
// }

// int main()
// {
//   int n,e; cin>>n>>e;
//   graph = vector<vector<int>> (n+1);
//   vis = vector<int>(n+1);
//   for(int i=0; i<e; i++)
//   {
//     int a,b; cin>>a>>b;
//     graph[a].push_back(b);
//     graph[b].push_back(a);
//   }

//   bfs(1);
    
//   return 0;
// }
#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int>>> graph;
vector<int> vis;

void primAlgo(){
  set<pair<int,int>> pq;
  pq.insert({0,1});
  int totalCost = 0;

  while( !pq.empty() ){
    int v = (*pq.begin()).second;
    int wt = (*pq.begin()).first;
    pq.erase(pq.begin());

    if( vis[v] ) continue;
    vis[v] = true;
    cout<<v<<" "<<wt<<endl;
    totalCost+=wt;

    for( auto elem : graph[v] ){
      if( vis[elem.first] ) continue;
      pq.insert({elem.second,elem.first});
    }
  }

  cout<<totalCost<<endl;
}

int main(){
  int n,e;
  cin>>n>>e;
  graph = vector<vector<pair<int,int>>> (n+1);
  vis = vector<int>(n+1);
  for(int i=0; i<e; i++)
  {
    int u,v,wt; cin>>u>>v>>wt;
    graph[u].push_back({v,wt});
    graph[v].push_back({u,wt});
  }

  primAlgo();
}