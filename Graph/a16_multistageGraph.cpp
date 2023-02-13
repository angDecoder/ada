#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> graph;
vector<bool> vis;

void multistageGraph(){
  queue<int> q;
  stack<int> st;
  vector<int> ans(graph.size(),INT_MAX);
  q.push(1);

  while( !q.empty() ){
    int v = q.front();
    q.pop();

    if( vis[v] ) continue;
    vis[v] = true;
    st.push(v);
    
    for( auto elem : graph[v] ){
      if( vis[elem.first] ) continue;
      q.push(elem.first);
    }
  }
  ans[graph.size()-1] = 0;
  while( !st.empty() ){
    int v = st.top();
    st.pop();
    
    for( auto elem : graph[v] ){
      ans[v] = min(ans[v],elem.second+ans[elem.first]);
    }
  }
  cout<<ans[1];
}

int main()
{
  int n,e; cin>>n>>e;
  graph = vector<vector<pair<int,int>>>(n+1);
  vis = vector<bool>(n+1,false);
  for(int i=0; i<e; i++)
  {
    int a,b,wt; cin>>a>>b>>wt;
    graph[a].push_back({b,wt});
  }

  multistageGraph();
    
  return 0;
}