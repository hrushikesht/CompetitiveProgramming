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

int n,a,b,pointer;
vector< pair<int,int> > exam;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    FOR(i,1,n){
    	cin>>a>>b;
    	exam.pb(mp(a,b));
    }
    sort(all(exam));
    pointer=exam[0].S;

    FOR(i,1,n-1){
    	if(pointer<=exam[i].S){
    		pointer=exam[i].S;
    	}
    	else{
    		pointer=exam[i].F;
    	}
    }
    cout<<pointer<<endl;
}
