#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int


vector<int> maxone(vector<int> &v, int b) {
  int n = v.size();
  int i = 0, j = 0;
  int c0 = 0, c1 = 0;
  int maxi = 0, maxj = 0,maxc = 0;
  
  while( i<n and j<n ){
      v[j] ? c1++ : c0++;
      j++;

      // cout<<i<<" "<<j<<" "<<c0<<" "<<c1<<endl;
      if( c0>b ){
        while( j>i and c0>b ){
            v[i] ? c1-- : c0--;
            i++;
        }
      }
      
      if( c0+c1>maxc ){
          maxc = c0+c1;
          maxi = i; 
          maxj = j - 1;
      }
      
      // j++;
  }
  
  vector<int> ans;
  for( int i=maxi; i<=maxj; i++ ){
    ans.push_back(i);
  }

  return ans;
}


int main()
{
  int n; cin>>n;
  vector<int> v(n);
  for(int i=0; i<n; i++)
  {
    cin>>v[i];
  }
  int k; cin>>k;
  vector<int> res = maxone(v,k);
  for( int i=0; i<res.size(); i++ ){
    cout<<res[i]<<" ";
  }
  
  return 0;
}