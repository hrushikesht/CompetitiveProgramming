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
// inline bool sortPairSecond(pair<int,int> p1,pair<int,int> p2){ return p1.S>p2.S}
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
using namespace std;
/////////////////////////////////////////////////////////////////////

int a[100010];

int main()
{
    std::ios::sync_with_stdio(false);

    int t; cin>>t;

    while(t--)
    {
        int n; cin>>n;

        i64 cost=0;
        int temp; 

        bool flag=false;

        FOR(i,1,n)
        {
            cin>>temp;


            if(!flag and temp==0)
            {
                flag=true;
            }

            if(flag)
            {
                if(temp==0)
                {
                    cost+=1100;
                }
                else
                {
                    cost+=100;
                }
            }
        }

        cout<<cost<<endl;
    }
}