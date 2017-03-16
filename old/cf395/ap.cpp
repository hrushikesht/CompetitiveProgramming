#include <bits/stdc++.h>
#include <unordered_map>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define i64 long long int

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(i64 i=0;i<(n);i++)
#define FOR(i,a,b) for(i64 i=(a);i<=(b);i++)
#define FORD(i,a,b) for(i64 i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = 1<<29;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void setBit(int & n, int b) { n |= two(b); }
inline void unsetBit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
inline bool sortDown(int x,int y){return x>y;}
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
using namespace std;
/////////////////////////////////////////////////////////////////////

int a[100010];
int m;

int yo_mod(int x)
{
    if(x>=0)
    {
        return (x%m);
    }
    else
    {
        return (m-(abs(x)%m));
    }
}

int main()
{
    std::ios::sync_with_stdio(false);

    int n; cin>>m>>n;

    FOR(i,1,n) cin>>a[i];

    sort(a,a+n);

    int pivot=a[1];

    FOR(i,1,n)
    {
        FOR(j,1,n)
        {
            if(i==j)
            {
                continue;
            }

            int d=yo_mod(a[j]-a[i]);

            DEBUG(d);

            DEBUG(i);
            DEBUG(j);
            DEBUG(a[i]);
            DEBUG(a[j]);

            bool flag=true;

            int icr;

            if(i<j)
            {
                icr=j-i;
            }
            else
            {
                icr=n-i+j;
            }
            
            for(int k=(i+icr)%n;k!=icr;k=(k+icr)%m)
            {
                DEBUG(k);
                DEBUG(a[k]);
                DEBUG(a[k]-a[(k-icr)%m]);
                if(d!=a[k]-a[(k-icr)%m])
                {
                    flag=false;
                    break;
                }
            }

            if(flag)
            {
                cout<<a[i]<<" "<<d<<endl;
                return 0;
            }
        }
    }

    cout<<-1<<endl;
    return 0;
}