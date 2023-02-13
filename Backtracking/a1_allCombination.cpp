#include<bits/stdc++.h>
using namespace std;

vector<int> res;
vector<int> num;
int countNum ;

void printRes( int n ){
  for(int i=0; i<2*n; i++)
  {
    cout<<res[i]<<" ";
  }
  cout<<endl;
}

void findAllCombination( int n, int i=0 ){
  if( i>= 2*n ){
    printRes(n);
    ++countNum;
    return;
  }

  if( res[i]!=0 )  {
    findAllCombination(n,i+1);
    return;
  }

  for(int j=1; j<=n; j++)
  {
    if( num[j]==1 and i+j+1<2*n and res[i+j+1]==0 ){
      num[j] = 0;
      res[i] = j;
      res[i+j+1] = j;
      findAllCombination(n,i+1);
      res[i] = 0;
      res[i+j+1] = 0;
      num[j]=1;
    }
  }
}


int main()
{
  int n; cin>>n;
  num = vector<int> (n+1,1);
  res = vector<int> (2*n,0);

  findAllCombination(n);
  cout<<countNum;
    
    return 0;
}