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
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }

#define MOD 1000000007

using namespace std;
/////////////////////////////////////////////////////////////////////

i64 dp[1010][1010]={0};
i64 alpha_limit[30];
i64 minimum[1010][1010];

i64 longest=0;

string s;

void cal_dp(int n)
{

    FOR(i,1,n)
    {
        dp[i][i]=1;
    }

    for(i64 l=2;l<=n;++l)
    {
        for(i64 i=1;i<=n-l+1;++i)
        {
            i64 j=i+l-1;

            i64 local_long=0;
            
            i64 len=j-i+1;

            if(len<=minimum[i][j])
            {
                dp[i][j]+=1;
                longest=max(longest,len);
            }

            DEBUG(i);
            DEBUG(j);
            for(i64 k=i;k<=j-1;++k)
            {
                DEBUG(k);
                DEBUG(dp[i][j]);
                DEBUG(dp[i][k]);
                DEBUG(dp[k+1][j]);
                // DEBUG(dp[i][k]*dp[k+1][j]);
                // DEBUG((dp[i][j]+(dp[i][k]*dp[k+1][j])%MOD)%MOD);

                i64 temp=(dp[i][k]*dp[k+1][j])%MOD;
                dp[i][j]=(dp[i][j]+temp)%MOD;

                DEBUG(dp[i][j]);
                cout<<endl;
            }
            DEBUG(dp[i][j]);
            cout<<endl;
        }
    }
}

void cal_min(int n)
{
    FOR(i,1,n)
    {
        minimum[i][i]=alpha_limit[s[i-1]-'a'+1];
    }
    FOR(i,1,n)
    {
        FOR(j,i+1,n)
        {
            minimum[i][j]=min(minimum[i][j-1],alpha_limit[s[j-1]-'a'+1]);
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);

    int n; cin>>n;

    cin>>s;

    FOR(i,1,26)
    {
        cin>>alpha_limit[i];
    }

    cal_min(n);

    cal_dp(n);

    DEBUG(longest);

    cout<<dp[1][n]<<endl;

    // FOR(i,1,n)
    // {
    //     FOR(j,1,n)
    //     {
    //         cout<<minimum[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}