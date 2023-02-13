#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

long long  solve( string s ){
  map<char,int> m;
  for(int i=0; i<s.size(); i++)
  {
    m[s[i]]++;
  }
  vector<bool> arr(26,false);
  for(int i=0; i<s.size(); i++)
  {
    if( arr[s[i]-'a']==false ){
      cout<<s[i]<<m[s[i]];
      arr[s[i]-'a'] = true;
    }
  }

  cout<<endl;

}

int main()
{
    ll t; cin>>t;
    while( t-- ){
    string s; cin>>s;
     solve(s);
    }
    return 0;
}