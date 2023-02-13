#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

void solve(){
  int n,k; cin>>n>>k;
  if( (n%2==1 and k%2==0) or k>n ){
    cout<<"NO"<<endl;
    return;
  }
  if( k==1 ){
    cout<<"YES"<<endl;
    cout<<n<<endl;
    return;
  }

  int x = -1, y = -1;
  for(int i=1; n-i>=k-1; i++)
  {
    if( ((n-i)/(k-1))%2==i%2 and (n-i)%(k-1)==0 ){
      cout<<"YES"<<endl;
      for(int j=0; j<k-1; j++)
      {
        cout<<((n-i)/(k-1))<<" ";
      }
      cout<<i<<endl;
      return;
    }
  }

  cout<<"NO"<<endl;
}

int main()
{
    ll t; cin>>t;
    while( t-- ){
     solve();
    }
    return 0;
}