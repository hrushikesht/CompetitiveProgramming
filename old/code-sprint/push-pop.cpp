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

        ll sum=0;
        ll p1=1,p2=1;


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

        do
        {
            if(arr[p1]<brr[p2] and p1<=n and p2<=m)
            {
                sum+=arr[p1];
                p1++;
            }
            if(brr[p2]<=arr[p1] and p1<=n and p2<=m)
            {
                sum+=brr[p2];
                p2++;
            }
        }
        while(sum<=x);

        DEBUG(p1);
        DEBUG(p2);

        cout<<p1+p2-2<<endl;
    }
}