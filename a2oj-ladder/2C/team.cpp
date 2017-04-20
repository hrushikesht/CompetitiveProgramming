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

int n,m;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;

    if(n>m+1 or 2*(n+1)<m){
    	cout<<-1<<endl;
    	return 0;
    }

    if(n==m or m==n+1){
    	FOR(i,1,n){
    		cout<<"10";
    	}
    	if(n<m) cout<<"1";
    	cout<<endl;
    	return 0;
    }

    if(n-1==m){
    	FOR(i,1,m) cout<<"01";
    	cout<<"0"<<endl;
    	return 0;
    }

    while(m!=n and n>0){
    	cout<<"110";
    	m-=2;
    	n-=1;
    }

    if(n==0){
    	FOR(i,1,m) cout<<"1";
    }
    else if(m==n){
    	FOR(i,1,m) cout<<"10";
    }
    cout<<endl;
}
