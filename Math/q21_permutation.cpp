#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int


void solve(){
  int n,l,r,s;
  cin>>n>>l>>r>>s;

  int k = r-l+1;
  int low = (k*(k+1))/2;
  int high = (k*(2*n+1-k))/2;

  if( s<low or s>high ){
    cout<<-1<<endl;
    return;
  }
  vector<int> arr(n+1,0);
  vector<bool> placed(n+1,false);

  for(int i=l; i<=r; i++)
  {
    arr[i] = i-l+1;
  }

  int j = n;
  int i = r;
  int currSum = (k*(k+1))/2;
  while( i>=l ){
    currSum-=arr[i];

    arr[i] = min(s-currSum,j);
    currSum+=arr[i];

    if( currSum==s ) break;
    i--,j--;
  }

  for(int i=l; i<=r; i++)
  {
    placed[arr[i]] = true;
  }
  j = 1;
  for(int i=1; i<=n; i++)
  {
    if( arr[i] )
      cout<<arr[i]<<" ";
    else{
      while( j<n and placed[j] ) j++;
      cout<<j++<<" ";
    }
  }
  cout<<endl;
  
  
}

int main()
{
    ll t; cin>>t;
    while( t-- ){
     solve();
    }
    return 0;
}