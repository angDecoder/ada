#include<bits/stdc++.h>
using namespace std;

int bs_ascending( vector<int> &v,int i,int j,int target ){

  int start = i,end = j;
  while( end>=start ){
    int mid = (start+end)/2;
    if( v[mid]==target )
      return mid;
    else if( v[mid]>target )
      end = mid-1;
    else 
      start = mid+1;
  }

  return -1;
}

int timesRotated( vector<int>&v ){
  int ans = -1;
  int start = 0, end = v.size()-1;
  int n = v.size();
  while( end>=start ){
    int mid = (start+end)/2;
    int next = (mid+1)%n;
    int prev = (mid+n-1)%n;
    if( v[mid]<v[next] and v[mid]<v[prev] )
      return mid;
    else if( v[end]>v[mid] )
      end = mid-1;
    else 
      start = mid+1;
  }
}

int bs_rotated( vector<int> &v, int target ){
  int k = timesRotated(v);
  int n = v.size();
  int prev = (k+n-1)%n;

  int a = bs_ascending(v,0,prev,target);
  int b = bs_ascending(v,k,n-1,target);

  if( a!=-1 )
    return a;
  if( b!=-1 )
    return b;
  return -1;

}

int main()
{
  vector<int> v = {8,9,10,1,2,3,7};
  int target; cin>>target;
  cout<<bs_rotated(v,target);
    
  return 0;
}