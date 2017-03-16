#include <bits/stdc++.h>
#include <unordered_map>
#include <utility>
#include <cmath>

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
const int INF = 1<<29;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void setBit(int & n, int b) { n |= two(b); }
inline void unsetBit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }

inline bool sortDown(int x,int y){return x>y;}
inline bool sortPairSecond( std::pair< int,int > p1, std::pair< int,int > p2){ return p1.S>p2.S;}
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
using namespace std;
/////////////////////////////////////////////////////////////////////

i64 m;
i64 power[60];



int main()
{
    std::ios::sync_with_stdio(false);

    int t; cin>>t;

    power[0]=1;
    power[1]=2;

    FOR(i,2,59)
    {
        // DEBUG(power[i-1]);
        power[i]=power[i-1]*2;
    }

    while(t--)
    {
        i64 a,n; cin>>a>>n>>m;

        i64 memo[50];
        i64 curr[50];

        int hi=9,lo=0;

        while(abs(lo-hi)>1)
        {
            int mid=(hi+lo)/2;

            // DEBUG(lo);
            // DEBUG(hi);

            if(pow(10,mid)>a)
            {
                hi=mid;
            }
            else
            {
                lo=mid;
            }
        }

        i64 d=hi;
        i64 mod=a%m;

        i64 power_mod=(int)pow(10,d) % m;
        // i64 prev = (mod*power_mod)%m;

        if(n==1)
        {
            cout<<a%m<<endl;
            continue;
        }
        
        // DEBUG(d);
        // DEBUG(m);

        int index=0;
        memo[index]=power_mod;
        curr[index]=power_mod;
        i64 ans=curr[index];

        // i64 power=2;

        // i64 rem=n

        // DEBUG(power_mod);

        // DEBUG(ans);

        while(power[index]<=n-1)
        {
            // ans=(ans+curr[index])%m;
            
            // DEBUG(power[index]);
            // DEBUG(index);
            // DEBUG(memo[index]);
            // DEBUG(ans);
            // DEBUG(curr[index]);

            index++;
            memo[index]=(memo[index-1]*memo[index-1])%m;
            curr[index]=(curr[index-1] + (curr[index-1]*memo[index-1])%m)%m;
            // cout <<endl;
        }

        // DEBUG(power[index-1]);

        i64 remain = n-power[index-1]-1;
        // DEBUG(remain);
        // DEBUG(mod);
        index--;

        i64 check_sum=memo[index];

        ans = curr[index];
        // DEBUG(ans);

        while(remain!=0)
        {
            // DEBUG(remain);
            int logo = floor(log2(remain));

            // DEBUG(logo);
            // DEBUG(check_sum);
            // DEBUG(curr[logo]);


            remain-=power[logo];
            // DEBUG(ans);
            // DEBUG(curr[logo]);
            // DEBUG(check_sum);
            ans=((ans+(curr[logo]*check_sum)%m)%m);
            // DEBUG(ans);

            check_sum= (check_sum*memo[logo])%m;
            // cout<<endl;
        }

        // DEBUG(mod);

        cout<<((ans+1)*mod)%m<<endl;

    }
}