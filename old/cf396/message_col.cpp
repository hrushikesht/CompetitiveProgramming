#include <bits/stdc++.h>
#include <unordered_map>
#include <utility>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define i64 long long int

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(i64 i=0;i<(n);i++)
#define FOR(i,a,b) for(i64 i=(a);i<=(b);i++)
#define FORD(i,a,b) for(i64 i=(a);i>=(b);i--)

#define all(v) (v).begin(),(v).end()

inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const i64 INF = 1<<29;
inline i64 two(i64 n) { return 1 << n; }
inline i64 test(i64 n, i64 b) { return (n>>b)&1; }
inline void setBit(i64 & n, i64 b) { n |= two(b); }
inline void unsetBit(i64 & n, i64 b) { n &= ~two(b); }
inline i64 last_bit(i64 n) { return n & (-n); }
inline i64 ones(i64 n) { i64 res = 0; while(n && ++res) n-=n&(-n); return res; }

inline bool sortDown(i64 x,i64 y){return x>y;}
inline bool sortPairSecond( std::pair< i64,i64 > p1, std::pair< i64,i64 > p2){ return p1.S>p2.S;}

#define MOD 1000000007
using namespace std;
/////////////////////////////////////////////////////////////////////

int arr[30];
int dp[1010];
int dp2[1010];

int main()
{
    std::ios::sync_with_stdio(false);

    int n; cin>>n;

    string s; cin>>s;

    dp[0]=1;
    dp2[0]=0;

    int l=0;

    FOR(i,0,n-1) cin>>arr[i];

    FOR(i,1,n)
    {   
        DEBUG(i);
        dp[i]=1;
        dp2[i]=i;

        int f=0;
        DEBUG(f);

        FORD(j,i-1,0)
        {
            cout<<"hi"<<endl;
            f=max(f,arr[s[j-1]-'a'+1]);
            DEBUG(f);
            DEBUG(j);

            if(f>= i-j)
            {
                DEBUG(j);
                dp[i]=(dp[i]+dp[j])%MOD;
                dp2[i]=min(dp2[i],dp2[j]+1);
                int k=i-j+1;
                l=max(2,k);
                DEBUG(l);
            }
        }
        cout<<endl;
    }

    FOR(i,1,n)
    {
        DEBUG(i);
        DEBUG(dp[i]);
        DEBUG(dp2[i]);
    }

    cout<<dp[n]<<endl<<l<<endl<<dp2[n]<<endl;
}