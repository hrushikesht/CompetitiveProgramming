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

inline int parent(int x){return floor((x-1)/2);};
inline int left(int x) {return 2*x+1;};
inline int right(int x){return 2*x+2;};

template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
using namespace std;
/////////////////////////////////////////////////////////////////////

int a[1000010];
int segMid[1000010];

vector< int > segInfo;
// vector< pair<int,int> > segRight;
 
void build(int l,int r,int index)
{
    if(l==r)
    {
        seg[index]=a[l];
        segInfo[index]=1;
        // segRight[index]=mp(a[r],1);
    }
    else
    {
        int mid=(l+r)/2;

        build(l,mid,left(index));
        build(mid+1,r,right(index));

        // int llf,lls,lrf,lrs,rlf,rls,rrf,rrs;

        // llf = segLeft[left(index)].F;
        // lls = segLeft[left(index)].S;

        // lrf = segLeft[right(index)].F;
        // lrs = segLeft[right(index)].S;

        // rlf = segRight[left(index)].F;
        // rlf = segRight[left(index)].S;

        // rrf = segRight[right(index)].F;
        // rrs = segRight[right(index)].S;

        int left_len=mid-l+1;
        int right_len=r-mid;
        int half=(r-l+1)/2;

        // segMid[index]=max(segMid[left(index)],segMid[right(index)]);
        // if(segRight[left(index)].F == segLeft[right(index)].F)
        // {
        //     segMid[index]=max(segMid[index],segRight[left(index)].S + segLeft[right(index)].S);
        // }

        // if(llf == lrf and lrf==rlf and rlf==rrf)
        // {
        //     if(lls=left_len and )
        // }

        // if(segInfo[left(index)] + segInfo[right(index)] > half and )
        // {

        // }
    }
}

int query(int x,int y,int node,int l,int r)
{
    if(x>r or y<l) return 0;
    if(x<=l and y>=r) return seg[node];

    int mid=(l+r)/2;

    int q1=query(x,y,left(node),l,mid);
    int q2=query(x,y,right(node),mid+1,r);

    return q1+q2;
}

int main()
{
    segLeft.resize(100000);
    segRight.resize(100000);

    int n,m; cin>>n>>m;



    for(int i=0;i<=20;i++)
    {
        DEBUG(i);
        cout<<segMid[i]<<endl;
    }
}