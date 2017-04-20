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
inline bool sortPairSecondI( std::pair< i64,i64 > p1, std::pair< i64,i64 > p2){ return p1.S<p2.S;}
inline bool sortPairSecondD( std::pair< i64,i64 > p1, std::pair< i64,i64 > p2){ return p1.S>p2.S;}
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
using namespace std;
/////////////////////////////////////////////////////////////////////
 
// i64 vector< pair<i64> > range;
 
// i64 a[1000010];

 
vector<i64> a;

// string hello("hello");

// i64 index;
 
int main()
{
    std::ios::sync_with_stdio(false);
 
    i64 n,l,r; cin>>n>>l>>r;

    vector< pair<i64,i64> > interval;

    // i64erval.resize(n-1);
 
    a.resize(n);
    FOR(i,0,n-1)
    {
        cin>>a[i];
    }
 
    if(n==1)
    {
        cout<<0<<endl;
        return 0;
    }
 
    sort(all(a),sortDown);

    // for(auto it=a.begin();it!=a.end();++it)
    // {
    //     cout<<*it<<" ";
    // }
    // cout<<endl;

    // for(i64 i=1;i<a.size()-1;i+=2)
    // {
    //     i64 x,y,z;
    //     x=a[i+1];
    //     y=a[i];
    //     z=a[i-1];

    //     // DEBUG(x);
    //     // DEBUG(y);
    //     // DEBUG(z);

    //     // DEBUG(i);

    //     if(2*y> z-x)
    //     {
    //         i64erval[pair_index++]=mp(y-x,z+y);
    //     }
    //     else
    //     {
    //         // DEBUG(x);
    //         i64erval[pair_index++]=mp(z-y,z+y);
    //         i64erval[pair_index++]=mp(y-x,y+x);
    //     }
    // }

    // if(rem_flag) i64erval[pair_index++]=mp(a[a.size()-1]-rem,a[a.size()-1]+rem);

    for(i64 i=0;i<n-1;++i)
    {
        interval.pb(mp(abs(a[i+1]-a[i])+1,a[i+1]+a[i]-1));
    }

    sort(all(interval),sortPairSecondD);



    // index=0;
    // partition(1,n);
 

   // DEBUG(rem_flag);


    // for(i64 i=0;i<n-1;++i)
    // {
    //     i64 gr=interval[i].S;
    //     i64 lr=interval[i].F;

    //     DEBUG(i);
    //     cout<<lr<<" "<<gr<<endl;
    // }

    i64 count=0;

    // DEBUG(hello);

    for(i64 i=0;i<n-1;++i)
    {
        i64 gr=interval[i].S;
        i64 lr=interval[i].F;

        // DEBUG(i);
        // cout<<lr<<" "<<gr<<endl;
        // DEBUG(l);
        // DEBUG(r);

        if(r>gr)
        {
            r=gr;
        }

        // DEBUG(r);

        if(r<l)
        {
            break;
        }

        if(l>=lr)
        {
            count+=r-l+1;
            break;
        }
        else
        {   
            if(r>=lr)
            {
                count+=r-lr+1;
                r=lr-1;
            }
        }
    
        // DEBUG(count);
        // cout<<endl;
    }


    // for(i64 i=0;i<interval.size();++i)
    // {
    //     i64 gr=interval[i].S;
    //     i64 lr=interval[i].F;

    //     // DEBUG(i);
    //     // cout<<lr<<" "<<gr<<endl;
    //     // DEBUG(l);
    //     // DEBUG(r);

    //     if(r>gr)
    //     {
    //         if(l>gr)
    //         {
    //             break;
    //         }
    //         else if(l>=lr)
    //         {
    //             count+=gr-l+1;
    //             break;
    //         }
    //         else
    //         {
    //             count+=gr-lr+1;
    //             r=lr-1;
    //         }
    //     }
    //     else if(r>=lr)
    //     {
    //         if(l>r)
    //         {
    //             break;
    //         }
    //         else if(lr<=l and l<=r)
    //         {
    //             count+=r-l+1;
    //             break;
    //         }
    //         else
    //         {
    //             count+=r-lr+1;
    //             r=lr-1;
    //         }
    //     }
    
    //     // DEBUG(count);
    //     // cout<<endl;
    // }

 
    cout<<count<<endl;
 
} 