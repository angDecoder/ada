#include<bits/stdc++.h>
using namespace std;

vector<int> arr;
vector<vector<int>> res;

void printPartition(){
  for(int i=0; i<res.size(); i++)
  {
    for(int j=1; j<res[i].size(); j++)
    {
      cout<<res[i][j]<<" ";
    }
    cout<<endl;
  }
}

bool k_partitionProblem( int n, int k, int sum = -1, int i=0 ){
  if( sum==-1 ){
    for(int j=0; j<n; j++)
      sum+=arr[j];

    if( sum%k!=0 ) return false;
    sum = sum/k;
    return k_partitionProblem(n,k,sum,i);
  }

  if( i>=n ){
    printPartition();
    return true;
  }

  for(int j=0; j<k; j++)
  {
    if( res[j][0]+arr[i]<=sum ){
      res[j][0] += arr[i];
      res[j].push_back(arr[i]);
      if( k_partitionProblem(n,k,sum,i+1) ) return true;
      res[j][0] -= arr[i];
      res[j].pop_back();
    }
  }
  
  return false;
}

int main()
{
  int n; cin>>n; 
  int k; cin>>k;

  for(int i=0; i<n; i++)
  {
    int a; cin>>a;
    arr.push_back(a);
  }

  res = vector<vector<int>> (k,vector<int>(1,0));

  cout<<k_partitionProblem(n,k);
    
  return 0;
}

// 12 5
// 7 3 5 12 2 1 5 3 8 4 6 4