#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

void solve(){
  int n,k,m;
  cin>>n>>k>>m;
  map<int,vector<int>> mp;
  for(int i=0; i<n; i++)
  {
    int a; cin>>a;
    mp[a%m].push_back(a);
  }

  for( auto elem : mp ){
    if( elem.second.size()>=k ){
      cout<<"Yes"<<endl;
      for(int i=0; i<k; i++)
      {
        cout<<elem.second[i]<<" ";
      }
      cout<<endl;
      return;
    }
  }

  cout<<"No"<<endl;
}

int main()
{
    solve();
    return 0;
}