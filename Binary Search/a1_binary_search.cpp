#include<bits/stdc++.h>
using namespace std;

int binarySearch( vector<int> v, int target ){
  int start = 0,end = v.size()-1;
  while( end-start>1 ){
    int mid = (start+end)/2;
    if( v[mid]<target )
      start = mid+1;
    else 
      end = mid;
  }

  if( v[start]==target ) return start;
  if( v[end]==target ) return end;
}

int main()
{
  vector<int> v = {1,3,4,5,8,10,11,14,18};
  int target; cin>>target;
  cout<<binarySearch(v,target);
    
  return 0;
}