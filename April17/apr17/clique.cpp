#include <bits/stdc++.h>
#include <unordered_map>
#include <utility>
#include <tuple>

#define ll long long int
#define vi vector<ll>
#define vl vector<ll>
#define pi pair<ll,ll>
#define tiii tuple<ll,ll,ll> >
#define tiiii tuple<ll,ll,ll,ll>
#define vpi vector< pair<ll,ll> >

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

const ll INF=1e15;
const int mod = 1000000007;
const int N = 4e5+5;
const int ifact_n_minus_1 = 977041169;
using namespace std;
/////////////////////////////////////////////////////////////////////

ll t,n,k,x,m,s;
vector< pair<ll,ll> > adj[200010];
bool is_present[200010]={false};

ll d1[200010];
ll d2[200010];
bool mark[200010]={false};

// struct compare{
// 	bool operator()(pi p1,pi p2){
// 		return p1.F<p2.F;
// 	}
// };

void dijkstra(ll v,ll *d){
	fill(d,d + n+10, INF);
	fill(mark, mark + n+10, false);
	d[v] = 0;
	ll u;
	priority_queue<pi,vpi, greater< pi > > pq;
	pq.push({d[v], v});
	while(!pq.empty()){
		u = pq.top().second;
		pq.pop();
		// if(mark[u])
		// 	continue;
		// mark[u] = true;
		for(auto p : adj[u]) //adj[v][i] = pair(vertex, weight)
			if(d[p.first] > d[u] + p.second){
				d[p.first] = d[u] + p.second;
				pq.push({d[p.first], p.first});
			}
	}
}


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t--){
    	cin>>n>>k>>x>>m>>s;

    	FOR(i,1,m){
    		ll a,b,c; cin>>a>>b>>c;
    		// DEBUG(a);
    		// DEBUG(b);
    		// DEBUG(c);
    		// cout<<endl;
    		adj[a].pb(mp(b,c));
    		adj[b].pb(mp(a,c));
    	}

  		// FOR(i,1,n){
		// 	cout<<i<<" : ";
		// 	for(auto u:adj[i]){
		// 		cout<<u.F<<"<>"<<u.S<<" ";
		// 	}
		// 	cout<<endl;
		// }
		// cout<<endl;

    	if(s<=k){
    		FOR(i,1,s-1){
    			adj[s].pb(mp(i,x));
    		}
    		FOR(i,s+1,k){
    			adj[s].pb(mp(i,x));
    		}

    		dijkstra(s,d1);

    		FOR(i,1,s-1){
    			cout<<d1[i]<<" ";
    		}
    		cout<<0<<" ";
    		FOR(i,s+1,n){
    			cout<<d1[i]<<" ";
    		}
    		cout<<endl;
    	}
    	else{
    		dijkstra(s,d1);

    		// cout<<"d1 : "<<endl;
    		// FOR(i,1,n){
    		// 	cout<<i<<" :> "<<d1[i]<<endl;
    		// }
    		// cout<<endl;

    		ll idx=1;
    		ll minito=LLONG_MAX;
    		FOR(i,1,k){
    			if(minito>d1[i]){
    				minito=d1[i];
    				idx=i;
    			}
    		}

    		// DEBUG(idx);

    		FOR(i,1,idx-1){
    			adj[idx].pb(mp(i,x));
    		}
    		FOR(i,idx+1,k){
    			adj[idx].pb(mp(i,x));
    		}

    		dijkstra(idx,d2);

    		// cout<<"d2 : "<<endl;
    		// FOR(i,1,n){
    		// 	cout<<i<<" :> "<<d2[i]<<endl;
    		// }
    		// cout<<endl;

    		FOR(i,1,s-1){
    			cout<<min(minito+d2[i],d1[i])<<" ";
    		}
    		cout<<0<<" ";
    		FOR(i,s+1,n){
    			cout<<min(minito+d2[i],d1[i])<<" ";
    		}
    		cout<<endl;

    	}

    	FOR(i,1,n+5){
    		adj[i].clear();
    	}
    }
}
