// https://codeforces.com/problemset/problem/478/B
#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,m; cin>>n>>m;
  long long max = n-m+1;
  long long min = n/m;
  long long rem = n%m;
  long long minAns =0;

  max = (max*(max-1))/2;
  minAns += (rem) * (min*(min+1))/2;
  minAns += (m-rem) * (min*(min-1))/2;
  

  cout<<minAns<<" "<<max<<endl;
    
  return 0;
}