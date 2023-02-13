#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

const int N = 15*1e6+7;
vector<int> spf(N);
vector<int> cnt(N);
void seive(){
  for(int i=1; i<=N; i++)
    spf[i] = i;

  for(int i=2; i*i<=N; i++)
  {
    if( spf[i]!=i ) continue;
    for(int j=i*i; j<=N; j+=i)
    {
      spf[j] = i;
    }
  }
}

void solve(){
  int n; cin>>n;
  vector<int> v(n);
  int gcd = 0;
  for(int i=0; i<n; i++)
  {
    cin>>v[i];
    gcd = __gcd(v[i],gcd);
  }

  int maxDiv = 0;
  for(int i=0; i<n; i++)
  {
    int elem = v[i]/gcd;
    while( elem!=spf[elem] ){
      int num = spf[elem];
      maxDiv = max( maxDiv,++cnt[num] );
      while( elem%num==0 ) elem = elem/num;
    }
    if( elem!=1 )
    maxDiv = max( maxDiv,++cnt[elem] );
  }

  if( maxDiv==0 ){
    cout<<-1<<endl;
  }
  else{
    cout<<n-maxDiv<<endl;
  }
}

int main()
{
  seive();
  solve();
  return 0;
}