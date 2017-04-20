#include <bits/stdc++.h>

#define ll long long int

#define pb push_back
#define mp make_pair
#define F first
#define S second

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define all(v) (v).begin(),(v).end()

using namespace std;
///////////////////////////////////////////////////////

int n;
ll arr[500010];
ll cum_arr[500010];

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    cum_arr[0]=0;
    FOR(i,1,n){
	    cin>>arr[i];
	    cum_arr[i]=cum_arr[i-1]+arr[i];
	}
	ll sum = cum_arr[n];

	// DEBUG(sum);

	if(3*((ll)(sum/3))!=(sum)){
		cout<<0<<endl;
		return 0;
	}

	// cout<<"hi"<<endl;

	ll sum_indiv = sum/3;
	ll sum_twice = 2*sum_indiv;
	ll ans=0;

	int plus=0;
	FOR(i,1,n-1){
		if(cum_arr[i]==sum_twice){
			ans+=plus;
		}
		if(cum_arr[i]==sum_indiv){
			plus++;
		}
	}
	cout<<ans<<endl;
}
