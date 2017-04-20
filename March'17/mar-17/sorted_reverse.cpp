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

ll grid[310][310]={0};
map<ll,pair<ll,ll> > M;


int main()
{
    std::ios::sync_with_stdio(false);

    ll n; cin>>n;

    ll index[n+10];
    ll curr_elem[310]={0};
    ll final_cost=0;

    FOR(i,1,n)
    {
        index[i]=n;
    }

    FOR(i,1,n)
    {
        FOR(j,1,n)
        {
            ll temp; cin>>temp;
            M[temp]=mp(i,j);
        }
    }

    FORD(i,n*n,1)
    {
        pair<ll,ll> p=M[i];
        ll x=p.F,y=p.S;

        ll cost=LLONG_MAX;
        ll curr_index=n;

        FOR(j,1,n)
        {
            if(index[j]!=0)
            {
                ll new_cost=(x-j)*(x-j) + (y-index[j])*(y-index[j]);

                if(new_cost<cost)
                {
                    cost=new_cost;
                    curr_index=j;
                }
            }
        }

        final_cost+=cost;
        grid[curr_index][index[curr_index]]=i;

        index[curr_index]-=1;
    }

    FOR(i,1,n)
    {
        FOR(j,1,n)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }

    // cout<<final_cost*1.0/(n*n*n)<<endl;
}