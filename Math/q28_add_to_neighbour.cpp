#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int
vector<int> v(1e5);
vector<int> sum(1e5);
int n;

int findSteps( int i, int s ){
	int j = i+1;
	int currSum = 0;
	while( j<n and currSum<s ) {
		currSum+=v[j];
		j++;
	}
	if( currSum==s ) return 

}

void solve(){
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>v[i];
		if( i==0 ) 
			sum[i] = v[i];
		else 	
			sum[i] = sum[i-1]+v[i];
	}

	int steps = INT_MAX;
	int currSum = 0;
	for(int i=0; i<n; i++)
	{
		int currStep = i+findSteps(i,sum[i]);
		steps = min(steps,currStep);
	}

	cout<<steps<<endl;
}

int main()
{
    ll t; cin>>t;
    while( t-- ){
     solve();
    }
    return 0;
}