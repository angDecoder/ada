#include<bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
const int z = 500;
vector<vector<pair<int,int>>> graph;
int dist[z][z];
int n,e; 

void floydWarshall(){
  for(int k=1; k<=n; k++)
  {
    for(int i=1; i<=n; i++)
    {
      for(int j=1; j<=n; j++)
      {
        if( dist[i][k]==INF || dist[k][j]==INF ) 
          continue;
        dist[i][j] = min( dist[i][j],dist[i][k]+dist[k][j] );
      }
    }
  }

  for(int i=1; i<=n; i++)
  {
    for(int j=1; j<=n; j++)
    {
      if( dist[i][j]==INF ) cout<<"I ";
      else cout<<dist[i][j]<<" ";
    }
    cout<<endl;
  }

}

int main()
{
  cin>>n>>e;
  graph= vector<vector<pair<int,int>>> (n+1);
  for(int i=1; i<=n; i++)
  {
    for(int j=1; j<=n; j++)
    {
      if( i==j ) dist[i][j] = 0;
      else dist[i][j] = INF;
    }
  }

  for(int i=0; i<e; i++)
  {
    int x,y,w; cin>>x>>y>>w;
    graph[x].push_back({y,w});
    dist[x][y] = w;
  }
  
  floydWarshall();

  return 0;
}

// #include<bits/stdc++.h>
// using namespace std;
// const int INF = INT_MAX;

// int n,e; 
// vector<vector<pair<int,int>>> graph;

// void floydWarshall(){
//   vector<vector<int>> table(n+1,vector<int>(n+1,INF));
//   for(int i=1; i<=n; i++)
//   {
//     table[i][i] = 0;
//     for( auto elem : graph[i] ){
//       table[i][elem.first] = elem.second;
//     }
//   }

//   for(int k=1; k<=n; k++)
//   {
//     for(int i=1; i<=n; i++)
//     {
//       for(int j=1; j<=n; j++)
//       {
//         if( table[i][k]==INF||table[k][j]==INF ) 
//           continue;
//         table[i][j] = min(table[i][j],table[i][k]+table[k][j]);
//       }
//     }
//   }

//   for(int i=1; i<=n; i++)
//     {
//       for(int j=1; j<=n; j++)
//       {
//         if( table[i][j]==INF ) cout<<"I"<<" ";
//         else cout<<table[i][j]<<" ";
//       }
//       cout<<endl;
//     }
  
// }


// int main()
// {
//   cin>>n>>e;
//   graph = vector<vector<pair<int,int>>>(n+1);
//   for(int i=0; i<e; i++)
//   {
//     int u,v,wt;
//     cin>>u>>v>>wt;
//     graph[u].push_back({v,wt});
//   }

//   floydWarshall();
    
//   return 0;
// }