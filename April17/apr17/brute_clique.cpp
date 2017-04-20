#include <bits/stdc++.h>
#include <unordered_map>
#include <utility>
#include <tuple>

#define ll long long int
#define vi vector<int>
#define vl vector<ll>
#define pi pair<int,int>
#define tiii tuple<int,int,int> >
#define tiiii tuple<int,int,int,int>
#define pl pair<ll> pl
#define vpi vector< pair<int,int> >

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
vector< pair<ll,ll> > adj[100010];
// bool is_present[100010]={false};

ll d1[100010];
ll d2[100010];
bool mark[100010]={false};

struct compare{
	bool operator()(pair<ll,ll> p1,pair<ll,ll> p2){
		return p1.first>p2.first;
	}
};

void dijkstra(ll s,ll *d){
	fill(d,d+n+5,INF);
	fill(mark,mark+n+5,false);

	pair<ll,ll> x;
	d[s]=0;
	priority_queue< pair<ll,ll> , vector< pair<ll,ll> > , compare > pq;
	pq.push(mp(0,s));

	while(!pq.empty()){
		x = pq.top();

		// DEBUG(x.second);
		pq.pop();
		if(mark[x.second]) continue;
		mark[x.second]=true;
		for(auto u:adj[x.second]){
			if(d[u.first]>d[x.second]+u.second){
				d[u.first]=d[x.second]+u.second;
				pq.push(mp(d[u.first],u.first));
			}
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

    	// DEBUG(n);

    	FOR(i,1,k){
    		FOR(j,i+1,k){
    			adj[i].pb(mp(j,x));
    			adj[j].pb(mp(i,x));
    		}
    	}
    	// DEBUG(n);

    	dijkstra(s,d1);
    	// DEBUG(n);
    	FOR(i,1,n){
    		cout<<d1[i]<<" ";
    	}
    	cout<<endl;

    	FOR(i,1,n){
    		adj[i].clear();
    	}
    }
}
