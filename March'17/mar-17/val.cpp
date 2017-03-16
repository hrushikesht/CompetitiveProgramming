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

#define MOD 1000000007
using namespace std;
/////////////////////////////////////////////////////////////////////

ll xeny[100010];
ll yana[100010];


int main()
{
    std::ios::sync_with_stdio(false);

    ll t; cin>>t;

    while(t--)
    {
        ll n; cin>>n;

        ll xeny_even=0,xeny_odd=0;
        ll yana_even=0,yana_odd=0;

        FOR(i,1,n)
        {
            cin>>xeny[i];

            if((i&1) == 0)
            {   
                xeny_even += xeny[i];
            }
            else
            {
                xeny_odd += xeny[i];
            }
        }
        FOR(i,1,n)
        {
            cin>>yana[i];
        
            if((i&1) == 0)
            {   
                yana_even += yana[i];
            }
            else
            {
                yana_odd += yana[i];
            }
        }

        cout<<min(xeny_odd+yana_even , xeny_even+yana_odd)<<endl;
    }
}