#include<bits/stdc++.h>
using namespace std;

int firstOccurence( vector<int> &v,int target ){
  int ans = -1;
  int start = 0, end = v.size()-1;
  while( end>=start ){
    int mid = (start+end)/2;
    if( v[mid]==target )
      ans = mid,end = mid-1;
    else if( v[mid]>target )
      end = mid-1;
    else 
      start = mid+1;
  }

  return ans;
}

int lastOccurence( vector<int> &v, int target ){
  int ans = -1;
  int start = 0, end = v.size()-1;

  while( end>=start ){
    int mid = (start+end)/2;
    if( v[mid]==target )
      ans = mid,start = mid+1;
    else if( v[mid]>target )
      end = mid-1;
    else 
      start = mid+1;
  }

  return ans;
}

int findOccurence( vector<int> &v,int target ){
  int i = firstOccurence(v,target);
  int j = lastOccurence(v,target);

  return j-i+1;
} 

int main()
{
  vector<int> v = {1,10,10,10,10,18,20};
  int target; cin>>target;
  
  cout<<findOccurence(v,target);
    
  return 0;
}