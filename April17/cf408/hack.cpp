#include <bits/stdc++.h>
#include <unordered_map>
#include <utility>
#include <tuple>

#define ll long long int
#define vi vector<int>
#define vl vector<ll>
#define pi pair<int>
#define tiii tuple<int,int,int> >
#define tiiii tuple<int,int,int,int>
#define pl pair<ll> pl
#define vpi vector< pair<int,int> >>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define mt make_tuple

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)

#define all(v) (v).begin(),(v).end()

inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const ll INF = 1<<29;
inline ll two(ll n) { return 1 << n; }
inline ll test(ll n, ll b) { return (n>>b)&1; }
inline void setBit(ll & n, ll b) { n |= two(b); }
inline void unsetBit(ll & n, ll b) { n &= ~two(b); }
inline ll last_bit(ll n) { return n & (-n); }
inline ll ones(ll n) { ll res = 0; while(n && ++res) n-=n&(-n); return res; }

inline int parent(int x){return floor((x-1)/2);};
inline int left(int x) {return 2*x+1;};
inline int right(int x){return 2*x+2;};

inline bool sortDown(ll x,ll y){return x>y;}
inline bool sortPairSecondInc( std::pair< ll,ll > p1, std::pair< ll,ll > p2){ return p1.S<p2.S;}
inline bool sortPairSecondDec( std::pair< ll,ll > p1, std::pair< ll,ll > p2){ return p1.S>p2.S;}
inline bool sortPairFirstDec( std::pair< ll,ll > p1, std::pair< ll,ll > p2){ return p1.F>p2.F;}

inline bool sortDownByLen( std::pair< ll,ll > p1, std::pair< ll,ll > p2 ){ return p1.S-p1.F > p2.S-p2.F;}


const int mod = 1000000007;
const int N = 4e5+5;
const int ifact_n_minus_1 = 977041169;
using namespace std;
/////////////////////////////////////////////////////////////////////

int n;
ll str[300010];
vector<int> adj[300010];
ll maxito = LLONG_MIN;
ll max_index;
bool visited[300010]={false};

void dfs(int node){
	visited[node]=true;

	for(auto u:adj[node]){
		if(!visited[u]){
			str[u]+=2;
			ll temp = str[u];
			DEBUG(u);
			DEBUG(temp);
			maxito=max(temp,maxito);
			DEBUG(maxito);
			dfs(u);
		}
	}
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;


    FOR(i,1,n){
    	cin>>str[i];
    }

    FOR(i,1,n-1){
    	int a,b; cin>>a>>b;
    	adj[a].pb(b);
    	adj[b].pb(a);
    }

    max_index=1;
    FOR(i,1,n){
       	if(maxito<str[i]){
       		maxito = str[i];
       		max_index=i;
       	}
       	else if(maxito==str[i]){
       		if(adj[max_index].size()<adj[i].size()){
       			max_index = i;
       		}
       	}
    }

    visited[max_index]=true;
    DEBUG(max_index);
    for(auto u:adj[max_index]){
    	str[u]+=1;
    	DEBUG(u);
    	ll temp = str[u];
    	DEBUG(temp);
    	maxito = max(temp,maxito);
    	DEBUG(maxito);
    	dfs(u);
    }

    FOR(i,1,n){
    	cout<<str[i]<<"  ";
    }
    cout<<endl;

    cout<<maxito<<endl;
    return 0;
}
