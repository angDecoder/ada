#include<bits/stdc++.h>
using namespace std;

void merge( int arr[], int start,int mid, int end ){
  int brr[end-start+1];
  int i=start,j=mid+1,k=0;

  while( i<=mid and j<=end ){
    if( arr[i]<=arr[j] ) brr[k++] = arr[i++];
    else brr[k++] = arr[j++];
  }

  while( i<=mid ) brr[k++] = arr[i++];
  while( j<=end ) brr[k++] = arr[j++];

  k=0,i=start;
  while( i<=end ) arr[i++] = brr[k++];
}

void mergeSort( int arr[], int start, int end ){
  if( start>=end ) return;

  int mid = (start+end)/2;
  mergeSort(arr,start,mid);
  mergeSort(arr,mid+1,end);

  merge(arr,start,mid,end);
}

int main()
{
  int n; cin>>n;
  int arr[n];
  for(int i=0; i<n; i++)
  {
    cin>>arr[i];
  }

  mergeSort(arr,0,n-1);

  for(int i=0; i<n; i++)
  {
    cout<<arr[i]<<" ";
  }
    
    return 0;
}