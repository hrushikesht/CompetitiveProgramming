#include <bits/stdc++.h>
#include <unordered_map>
#include <utility>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define ll long long int

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
inline bool sortPairSecond( std::pair< ll,ll > p1, std::pair< ll,ll > p2){ return p1.S>p2.S;}
inline bool sortDownByLen( std::pair< ll,ll > p1, std::pair< ll,ll > p2 ){ return p1.S-p1.F > p2.S-p2.F;}


#define MOD 1000000007
using namespace std;
/////////////////////////////////////////////////////////////////////

ll x[2010];
ll y[2010];
ll z[2010];
ll r[2010];

ll adj_x[4020];
ll adj_z[4020];
ll adj_y[4020];



int main()
{
    std::ios::sync_with_stdio(false);

    ll t; cin>>t;

    FOR(o,1,t)
    {
        ll n; cin>>n;

        FOR(i,1,n)
        {
            cin>>x[i]>>y[i]>>z[i]>>r[i];
        }

        vector< pair<ll,ll> > adj[6];

        FOR(i,1,n)
        {
            adj_x[2*i-1] = x[i]-r[i];
            adj_x[2*i] = x[i]+r[i];
            adj_y[2*i-1] = y[i]-y[i];
            adj_y[2*i] = y[i]+y[i];
            adj_z[2*i-1] = z[i]-z[i];
            adj_z[2*i] = z[i]+z[i];
        }

        FOR(i,1,3)
        {
            ll ex_left=adj[i].F;
            ll ex_right=adj[i].S;

            ll mid=(ex_left+ex_right)/2;

            for(auto it=adj[i];it<adj[i].end();++it)
            {
                if(mid)
            }
        }
    }
}