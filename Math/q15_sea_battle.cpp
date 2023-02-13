#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

void solve(){
  int n,a,b,k;
  cin>>n>>a>>b>>k;
  string s; cin>>s;
  vector<int> v;
  int c = 0;
  for(int i=0; i<s.size(); i++)
  {
    if( s[i]=='0' ) c++;
    else c = 0;

    if( c==b ){
      v.push_back(i+1);
      c=0;
    }
  }
  int fake = v.size()-a+1;
  cout<<fake<<endl;
  for(int i=0; i<fake; i++)
  {
    cout<<v[i]<<" ";
  }
  cout<<endl;
}

int main()
{
  solve();
  return 0;
}