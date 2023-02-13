#include<bits/stdc++.h>
using namespace std;

unordered_map<string,bool> m;
bool isScramble(string s1, string s2) { 

  if( m.find(s1+"#"+s2)!=m.end() )
    return m[s1+"#"+s2];

  if( s1==s2 ) 
    return m[s1+"#"+s2] =  true;
  
  int n = s1.size();
  for(int i=1; i<n; i++)
  {
    // check for not swapped
    if( isScramble(s1.substr(0,i),s2.substr(0,i)) and isScramble(s1.substr(i),s2.substr(i)) )
      return m[s1+"#"+s2] =  true;

    // check for swapped
    if( isScramble(s1.substr(0,i),s2.substr(n-i)) and isScramble(s1.substr(i),s2.substr(0,n-i)) )
      return m[s1+"#"+s2] =  true;
  }

  return m[s1+"#"+s2] =  false;
}

int main()
{
    cout<<isScramble("abcde","caebd");
    return 0;
}