#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

void solve(){
  int n; cin>>n;
  vector<int> v(4*n);
  for(int i=0; i<v.size(); i++)
  {
    cin>>v[i];
  }

  sort(v.begin(),v.end());

  int i=0,j=4*n-2;
  int area = v[0]*v.back();
  while( j>i ){
    if( v[i]!=v[i+1] or v[j]!=v[j+1] or v[i]*v[j]!=area ){
      cout<<"NO"<<endl;
      return;
    }

    i+=2,j-=2;
  }

  cout<<"YES"<<endl;

}

int main()
{
    ll t; cin>>t;
    while( t-- ){
     solve();
    }
    return 0;
}