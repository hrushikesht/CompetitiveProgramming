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
inline bool sortPairSecond( std::pair< ll,ll > p1, std::pair< ll,ll > p2){ return p1.S<p2.S;}
inline bool sortPairFirstDec( std::pair< ll,ll > p1, std::pair< ll,ll > p2){ return p1.F>p2.F;}
inline bool sortPairSecondDec( std::pair< ll,ll > p1, std::pair< ll,ll > p2){ return p1.S>p2.S;}
inline bool sortDownByLen( std::pair< ll,ll > p1, std::pair< ll,ll > p2 ){ return p1.S-p1.F > p2.S-p2.F;}


#define MOD 1000000007
using namespace std;
/////////////////////////////////////////////////////////////////////



int main()
{
    std::ios::sync_with_stdio(false);

    ll n,m; cin>>n;

    vector< pair<ll,ll> > chess;
    vector< pair<ll,ll > >  prog;

    FOR(i,1,n){
        ll l,r; cin>>l>>r;

        chess.pb(mp(l,r));
    }

    cin>>m;

    FOR(i,1,m){
        ll l,r; cin>>l>>r;

        prog.pb(mp(l,r));
    }

    sort(all(chess),sortPairSecond);
    sort(all(prog),sortPairFirstDec);

    // for(auto it=chess.begin();it!=chess.end();++it){
    //     cout<<it->F<<" "<<it->S<<endl;
    // }

    // for(auto it=prog.begin();it!=prog.end();++it){
    //     cout<<it->F<<" "<<it->S<<endl;
    // }


    ll len= prog[0].F - chess[0].S;

    sort(all(chess),sortPairFirstDec);
    sort(all(prog),sortPairSecond);

    // cout<<"second"<<endl;
    // for(auto it=chess.begin();it!=chess.end();++it){
    //     cout<<it->F<<" "<<it->S<<endl;
    // }

    // for(auto it=prog.begin();it!=prog.end();++it){
    //     cout<<it->F<<" "<<it->S<<endl;
    // }


    // DEBUG(len);

    len=max(chess[0].F-prog[0].S,len);

    if(len<=0){
        cout<<0<<endl;
    }
    else{
        cout<<len<<endl;
    }


}