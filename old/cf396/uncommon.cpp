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
using namespace std;
/////////////////////////////////////////////////////////////////////


int main()
{
    std::ios::sync_with_stdio(false);

    string a,b; cin>>a>>b;

    if(a == b)
    {
        cout<<-1<<endl;
        return 0;
    }
    else
    {
        cout<<max(a.size(),b.size());
    }
    cout<<endl;
    return 0;
}