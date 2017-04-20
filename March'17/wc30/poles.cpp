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
inline bool sortDownByLen( std::pair< ll,ll > p1, std::pair< ll,ll > p2 ){ return p1.S-p1.F > p2.S-p2.F;}


#define MOD 1000000007
using namespace std;
/////////////////////////////////////////////////////////////////////

ll altitude[5010];
ll weight[5010];
// ll curr[]


int main()
{
    std::ios::sync_with_stdio(false);

    ll n,k; cin>>n>>k;
    ll cost=0;

    FOR(i,1,n){
        cin>>altitude[i]>>weight[i];
    }

    if(n==k){
        cout<<0<<endl;
        return 0;
    }

    FOR(i,k+1,n){
        ll minito=LLONG_MAX;
        ll idx=1;

        FOR(j,2,k){
            if(weight[j]*(altitude[j]-altitude[j-1]) <= minito){
                minito=weight[j]*(altitude[j]-altitude[j-1]);
                idx=j;
            }
        }

        if(weight[i]*(altitude[i]-altitude[k]) <= minito){
            minito=weight[i]*(altitude[i]-altitude[k]);
            idx=i;
        }


            
        cost+=minito;

        // DEBUG(idx);

        // DEBUG(altitude[1]);

        if(idx<i){
            // cout<<"hi"<<endl;
            weight[idx-1]+=weight[idx];
            // DEBUG(weight[idx-1]);
            FOR(j,idx,k-1){
                weight[j]=weight[j+1];
                altitude[j]=altitude[j+1];
            }

            weight[k]=weight[i];
            // DEBUG(weight[k]);
            altitude[k]=altitude[i];
        }
        else{
            weight[k]+=weight[idx];
            // altitude[k]=altitude[idx];
        }

        // DEBUG(minito);
        // DEBUG(i);
        // cout<<"wt: ";
        // FOR(i,1,k){
        //     cout<<weight[i]<<" ";
        // }
        // cout<<endl;
        // cout<<"alt: ";
        // FOR(i,1,k){
        //     cout<<altitude[i]<<" ";
        // }
        // cout<<endl<<endl;;
        
    }
    cout<<cost<<endl;
}