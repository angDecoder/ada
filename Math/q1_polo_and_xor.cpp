// polo and xor operation - https://codeforces.com/contest/288/problem/C
#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n; cin>>n;
  vector<int> arr(n+1,0);
  long long sum = 0;
  for(int i=n; i>0; i--)
  {
    if( arr[i]==0 ){
      int x = (1<<(1+(int)log2(i)))-1;
      int num = x&(~i);
      arr[i] = num;
      arr[num] = i;
    }

    sum += arr[i]^i;
  }
  // sum+=arr[0]^0;

  cout<<sum<<endl;
  for(int i=0; i<=n; i++)
  {
    cout<<arr[i]<<" ";
  }
    
  return 0;
}