#include<bits/stdc++.h>
using namespace std;

void sortArray( int n, int p[], int w[] ){
  for(int i=0; i<=n-2; i++)
  {
    int maxPos = i;
    double ratio = p[i]/w[i];
    for(int j=i+1; j<n; j++)
    {
      if( p[j]/w[j]>ratio ){
        ratio = p[j]/w[j];
        maxPos = j;
      }
    }

    swap(p[i],p[maxPos]);
    swap(w[i],w[maxPos]);
  }
}

double fractionalKnapsack( int n, int m, int p[], int w[] ){
  double profit = 0;
  sortArray(n,p,w);
  int i=0;
  while( i<n and w[i]<=m ){
    m -= w[i];
    profit += p[i];
    i++;
  }

  if( i>=n||m==0 ) return profit;
  profit += p[i]/w[i] * m;
  return profit;
}

int main()
{
  int n,m; cin>>n>>m;
  int p[n],w[n];
  for(int i=0; i<n; i++)
  {
    cin>>p[i];
  }
  for(int i=0; i<n; i++)
  {
    cin>>w[i];
  }

  cout<<fractionalKnapsack(n,m,p,w);
    
  return 0;
}