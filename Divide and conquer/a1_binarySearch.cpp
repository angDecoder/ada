#include<bits/stdc++.h>
using namespace std;

int binarySearch( int arr[],int num, int start, int end ){
  if( start>end )  return -1;
  int mid = (start+end)/2;
  if( arr[mid]==num ) return mid;
  if( arr[mid]>num ) return binarySearch(arr,num,start,mid-1);
  if( arr[mid]<num ) return binarySearch(arr,num,mid+1,end);
}

int main()
{
  int n; cin>>n;
  int arr[n];
  for(int i=0; i<n; i++)
  {
    cin>>arr[i];
  }
  sort(arr,arr+n);
  int num; cin>>num;
  cout<<binarySearch(arr,num,0,n-1);
    
  return 0;
}