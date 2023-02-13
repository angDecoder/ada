#include<bits/stdc++.h>
using namespace std;
vector<vector<bool>> vis;
vector<vector<int>> pos = {
  {0,1},{0,-1},{1,0},{-1,0}
};

bool isValid( int i, int j ){
  return ( i>=0 and j>=0 and i<vis.size() and j<vis[0].size() );
}

void dfs( int i, int j, vector<vector<char>> &grid ){
  vis[i][j] = true;

  for( auto elem : pos ){
    int x = elem[0] + j;
    int y = elem[1] + i;
      // cout<<j<<" "<<i<<"-->"<<x<<" "<<y<<endl;
  
    if( isValid(y,x) and !vis[y][x] and grid[y][x]=='1' ) {
      dfs(y,x,grid);
    }

  }
}

int numIslands( vector<vector<char>> &grid ){
  int n = (int)grid.size();
  int m = (int)grid[0].size();
  vis = vector<vector<bool>> (n,vector<bool>(m,false));
  int ans = 0;

  for(int i=0; i<n; i++)
  {
    for(int j=0; j<m; j++)
    {
      if( grid[i][j]=='1' and !vis[i][j] ) {
        // cout<<i<<" "<<j<<endl;
        dfs(i,j,grid);
        ans++;
      }
      vis[i][j] = true;
    }
  }
  return ans;
}

int main()
{
  vector<vector<char>> grid = 
{{'1','0','1','1','0','1','1'}};

  cout<<numIslands(grid)<<endl;
    
  return 0;
}