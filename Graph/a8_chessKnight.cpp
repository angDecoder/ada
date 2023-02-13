// #include<bits/stdc++.h>
// using namespace std;
// #define LL long long int
// #define ul unsigned long long int

// vector<vector<int>> level;
// pair<int,int> findCoordinate( string s){
//   return {s[0]-'a',s[1]-'1'};
// }

// pair<int,int> source;
// pair<int,int> dest;

// bool isValid( int i, int j ){
//   return i>=0 and j>=0 and i<8 and j<8;
// }

// vector<pair<int,int>> pos = {
//   {2,1},{2,-1},
//   {-2,1},{-2,-1},
//   {1,2},{-1,2},
//   {1,-2},{-1,-2},
// };

// void bfs(){
//   queue<pair<int,int>> q;
//   q.push(source);
//   level[source.first][source.second] = 0;
  
//   while( !q.empty() ){
//     pair<int,int> v = q.front();
//     // cout<<v.first<<" "<<v.second<<endl;
//     q.pop();
//     for( auto elem : pos ){
//       int x = elem.first + v.first;
//       int y = elem.second + v.second;
//       if( !isValid(x,y)||level[x][y]!=-1 ) continue;
//       q.push({x,y});
//       level[x][y] = level[v.first][v.second]+1;
//     }
//   }

//   cout<<level[dest.first][dest.second]<<endl;
// }

// void solve(){
//   level.clear();
//   level = vector<vector<int>> (8,vector<int>(8,-1));
//   string s1,s2; cin>>s1>>s2;
//   source = findCoordinate(s1);
//   dest = findCoordinate(s2);

//   bfs();
// }

// int main()
// {
//     LL t; cin>>t;
//     while( t-- ){
//      solve();
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define LL long long int
#define ul unsigned long long int

pair<int,int> findPos( string s ){
  return {s[0]-'a',s[1]-'1'};
}

bool isValid( int i, int j ){
  return ( i>=0 and j>=0 and i<8 and j<8 );
}

vector<vector<int>> pos = {
  {-1,2},{1,2},
  {-1,-2},{1,-2},
  {2,1},{2,-1},
  {-2,1},{-2,-1}
};

void solve(){
  string s1,s2; cin>>s1>>s2;
  pair<int,int> source = findPos(s1);
  pair<int,int> dest = findPos(s2);
  vector<vector<int>> vis(8,vector<int>(8,-1));
  queue<pair<int,int>> q;
  q.push(source);
  vis[source.first][source.second] = 0;

  while( !q.empty() ){
    pair<int,int> t = q.front();
    q.pop();
    for( auto elem : pos ){
      int i = elem[0]+t.first;
      int j = elem[1]+t.second;
      if( isValid(i,j) and vis[i][j]==-1 ){
        q.push({i,j});
        vis[i][j] = vis[t.first][t.second]+1;
      }
    }
  }

  cout<<vis[dest.first][dest.second]<<endl;

}

int main()
{
    LL t; cin>>t;
    while( t-- ){
     solve();
    }
    return 0;
}