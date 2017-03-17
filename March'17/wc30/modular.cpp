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
inline bool sortPairSecondInc( std::pair< ll,ll > p1, std::pair< ll,ll > p2){ return p1.S<p2.S;}
inline bool sortPairSecondDec( std::pair< ll,ll > p1, std::pair< ll,ll > p2){ return p1.S>p2.S;}
inline bool sortPairFirstDec( std::pair< ll,ll > p1, std::pair< ll,ll > p2){ return p1.F>p2.F;}
inline bool sortDownByLen( std::pair< ll,ll > p1, std::pair< ll,ll > p2 ){ return p1.S-p1.F > p2.S-p2.F;}

const int mod = 1000000007
const int N = 4e5+5
const int ifact_n_minus_1 = 977041169
using namespace std;
/////////////////////////////////////////////////////////////////////

// MO's algo
ll block_size;
ll n,q;
ll arr[40020];
vector< pair< pair<ll,ll> , pair< pair<ll,ll> ,ll> > > query;
ll ans[400020];

bool moCompare(pair< pair<ll,ll> , pair< pair<ll,ll> ,ll> > p1,pair< pair<ll,ll> , pair< pair<ll,ll> ,ll> >p2){

    if(p1.F.F/block_size != p2.F.F/block_size){
        return p1.F.F < p2.F.F;
    }

    return p1.F.S < p2.F.S;

}

void mo(){
    
    sort(all(v),Compare);

    ll curr_l=

    for(auto it=query.begin();it<query.end();++it){

    }

}

int main()
{
    std::ios::sync_with_stdio(false);

    cin>>n>>q;

    block_size=q/(int)sqrt(q);

    REP(i,n) cin>>arr[i];

    REP(i,q){
        ll l,r,x,y; cin>>l>>r>>x>>y;

        query.pb(mp(mp(l,r),mp(mp(x,y),i)));

    }

    mo();


}