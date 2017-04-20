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

ll arr[100010];
ll brr[100010];



int main()
{
    std::ios::sync_with_stdio(false);

    int t; cin>>t;

    while(t--)
    {
        ll n,m,x; cin>>n>>m>>x;

        FOR(i,1,n) cin>>arr[i];
        FOR(i,1,m) cin>>brr[i];

        FOR(i,2,n)
        {
            arr[i]+=arr[i-1];
            brr[i]+=brr[i-1];
        }

        arr[0]=0;
        brr[0]=0;

        // FOR(i,1,n)
        // {
        //     cout<<arr[i]<<" ";
        // }
        // cout<<endl;

        // FOR(i,1,n)
        // {
        //     cout<<brr[i]<<" ";
        // }
        // cout<<endl;

        ll ans;
        

        ll hi=n+m,lo=0;

        while(abs(hi-lo)>1)
        {
            // DEBUG(hi);
            // DEBUG(lo);
            ll mid=(hi+lo)/2;
            ans=LONG_MAX;

            ll loop=0;

            FOR(j,0,mid)
            {
                if(j<=n and mid-j<=m)
                {
                    ans=min(ans,arr[j]+brr[mid-j]);
                }
                loop++;
            }
            if(ans<x)
            {
                lo=mid;
            }
            else
            {
                hi=mid;
            }
            // DEBUG(x);
            // DEBUG(ans);
            // DEBUG(loop);
        }

        ans=LONG_MAX;

        FOR(j,0,hi)
        {
            if(j<=n and hi-j<=m)
            {
                ans=min(ans,arr[j]+brr[hi-j]);
            }
        }

        // DEBUG(hi);
        // DEBUG(lo);
        // DEBUG(ans);

        if(ans<=x)
        {
            cout<<hi<<endl;
        }
        else
        {
            cout<<lo<<endl;
        }
    }
}