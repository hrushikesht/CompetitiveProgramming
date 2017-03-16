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

int a[100010];

int interval[100010][4]={0};
//1 : l
//2 : r
//3 : repeated Number

int main()
{
    std::ios::sync_with_stdio(false);

    int n,m; cin>>n>>m;

    FOR(i,1,n) cin>>a[i];

    int start=1;
    int end=1;

    interval[1][1]=1;
    interval[1][2]=0;
    interval[1][3]=a[1];

    FOR(i,2,n)
    {
        if(a[i]==a[i-1])
        {
            // DEBUG(i);
            // DEBUG(start);
            interval[i][1]=start;
            end++;  
        }
        else
        {
            // cout<<"not equal"<<endl;
            // DEBUG(i);
            interval[i-1][1]=start;
            interval[i-1][2]=end;
            interval[i-1][3]=a[i-1];
            start=i;
            end=i;
            interval[i][1]=start;
            interval[i][3]=a[i];
        }

        if(i==n)
        {
            interval[i][1]=start;
            interval[i][2]=end;
            interval[i][3]=a[i];   
        }
    }

    // DEBUG(start);
    // DEBUG(end);
    // FOR(i,1,n)
    // {
    //     // DEBUG(i);
    //     cout<<interval[i][1]<<"  "<<interval[i][2]<<"  "<<interval[i][3]<<endl;
    // }

    int r_index=n;
    int curr=a[n];

    FORD(i,n-1,1)
    {
        if(interval[i][2]==0)
        {
            interval[i][2]=r_index;
            interval[i][3]=curr;
        }
        else
        {
            r_index=interval[i][2];
            curr=interval[i][3];
        }
    }

    // DEBUG(start);
    // DEBUG(end);
    // FOR(i,1,n)
    // {
    //     // DEBUG(i);
    //     cout<<interval[i][1]<<"  "<<interval[i][2]<<"  "<<interval[i][3]<<endl;
    // }

    FOR(i,1,m)
    {
        // DEBUG(i);
        int l,r,k; cin>>l>>r>>k;

        int mid=(l+r)/2;
        // DEBUG(mid);

        // int pivot=a[mid];
        // DEBUG(pivot);

        int left=interval[mid][1];
        int right=interval[mid][2];

        int size=0;
        // DEBUG(l);
        // DEBUG(r);
        // DEBUG(ac);
        // DEBUG(b);
        if(left<=l and right>=r)
        {
            if(r-l+1>=k) cout<<a[mid]<<endl;
            else cout<<-1<<endl;
        }
        else
        {
            if(l<=left and right<=r)
            {
                // cout<<"hi"<<endl;
                if(right-left+1>=k) cout<<a[mid]<<endl;
                else cout<<-1<<endl;
            }
            else
            {
                if(r<right)
                {
                    if(r-left+1 >= k) cout<<a[mid]<<endl;
                    else cout<<-1<<endl;
                }
                else
                {
                    if(right-l+1 >= k) cout<<a[mid]<<endl;
                    else cout<<-1<<endl;
                }
            }
        }
    
    }
        // cout<<endl;
    
}