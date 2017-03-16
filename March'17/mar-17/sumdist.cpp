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
 
ll **dp=(ll**)malloc(100011*sizeof(ll*));
 
ll first[100010];
ll second[100010];
ll third[100010];
 
 
int main()
{
    std::ios::sync_with_stdio(false);
 
    ll t; cin>>t;
 
    FOR(i,0,100010)
    {
        dp[i]=(ll*)malloc(100010*sizeof(ll));
    }
 
    while(t--)
    {
        ll n; cin>>n;
        ll cost=0;
 
        FOR(i,1,n-1) cin>>first[i];
        FOR(i,1,n-2) cin>>second[i];
        FOR(i,1,n-3) cin>>third[i];
        
        
        FOR(i,1,n-1)
        {
            dp[i][i+1]=first[i];
            cost+=dp[i][i+1];
        }
 
        FOR(i,1,n-2)
        {
            dp[i][i+2]=min( second[i],first[i]+first[i+1] );
            cost+=dp[i][i+2];
        }
 
        FOR(i,1,n-3)
        {
            ll temp= min(first[i]+second[i+1],min(second[i]+first[i+2],first[i]+first[i+1]+first[i+2]));
            dp[i][i+3]=min( third[i], temp );
            cost+=dp[i][i+3];
        }


        // DEBUG(cost);
 
        FORD(i,n-4,1)
        {
            ll x=i,y=n;
            while(x>0)
            {
                // DEBUG(x); 
                // DEBUG(y);
                // dp[x][y]=LLONG_MAX;
                ll temp1=dp[x][y-1]+dp[y-1][y];
                ll temp2=dp[x][y-2]+dp[y-2][y];
                ll temp3=dp[x][y-3]+dp[y-3][y];
 
                dp[x][y]=min(temp1,min(temp2,temp3));
                cost+=dp[x][y];
                x--;
                y--;
            }
        }

        cout<<cost<<endl;

        // else
        // {
        //     cost=0;
     
        //     FOR(i,1,n-1)
        //     {
        //         cost+=i*(n-i)*first[i];
        //     }
     
        //     cout<<cost<<endl;
        // }
    }
}