#include<bits/stdc++.h>
using namespace std;

int lowerBound( vector<int> &v,int target ){
  int start=0,end=v.size()-1;
  while( end-start>1 ){
    int mid = (start+end)/2;
    if( v[mid]<target )
      start = mid+1;
    else 
      end = mid;
  }

  if( v[start]>=target ) 
    return start;
  if( v[end]>=target )
    return end;

  return -1;
}

int upperBound( vector<int> &v,int target ){
  int start = 0, end = v.size()-1;
  while( end-start>1 ){
    int mid = (start+end)/2;
    if( v[mid]<=target )
      start = mid+1;
    else 
      end = mid;
  }

  if( v[start]>target )
    return start;
  if( v[end]>target )
    return end;
  return -1;
}

int main()
{
  vector<int> v = {1,2,4,5,8,10};
  int target; cin>>target;
  cout<<lowerBound(v,target)<<endl;
  cout<<upperBound(v,target)<<endl;
    
    return 0;
}