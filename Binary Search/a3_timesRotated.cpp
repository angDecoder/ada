#include<bits/stdc++.h>
using namespace std;

int timesRotated( vector<int> &v ){

  int n = v.size();
  int start = 0, end = v.size()-1;
  while( end>=start ){
    int mid = (start+end)/2;
    int prev = (start+n-1)%n;
    int next = (start+1)%n;

    if( v[mid]<v[prev] and v[mid]<v[next] )
      return mid;
    else if( v[end]>v[mid] )
      end = mid-1;
    else 
      start = mid+1;
  }

}

int main()
{

  vector<int> v = {8,9,10,1,2,3,7};
  cout<<timesRotated(v);
    
  return 0;
}