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

ll arr[100000010];
int ans[100000010];

int main()
{
    std::ios::sync_with_stdio(false);

    ll n,l,r; cin>>n>>l>>r;

    ll index=2;
    arr[1]=n;
    ll temp=n;

    if(n==1)
    {
        cout<<1<<endl;
        return 0;
    }

    do
    {
        arr[index]=temp/2;
        index++;
        temp/=2;
    }
    while(temp!=1);


    ll size=index-1;
    ans[1]=arr[size-1]%2;
    ll x=2;

    // DEBUG(size);

    // FOR(i,1,size)
    // {
    //     cout<<arr[i]<<endl;
    // }

    FORD(i,size-2,1)
    {
        DEBUG(i);
        // DEBUG(arr[i]);
        ans[x]=arr[i]%2;
        x++;

        ll temp_x=x;


        FORD(j,temp_x-2,1)
        {
            // DEBUG(j);
            ans[x++]=ans[j];
        }
    }

    ll counter=0;
    // DEBUG(x);

    FOR(i,l,r)
    {
        if(i%2 == 1)
        {
            counter++;
        }
        else
        {
            // DEBUG(i%2);
            // DEBUG(ans[i%2])
            counter+=ans[i/2];
        }
    }

    cout<<counter<<endl;

}