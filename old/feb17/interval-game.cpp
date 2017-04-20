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

inline i64 parent(i64 x){return floor((x-1)/2);};
inline i64 left(i64 x) {return 2*x+1;};
inline i64 right(i64 x){return 2*x+2;};

inline bool sortDown(i64 x,i64 y){return x>y;}
inline bool sortPairSecond( std::pair< i64,i64 > p1, std::pair< i64,i64 > p2){ return p1.S>p2.S;}

#define MOD 1000000007
using namespace std;
/////////////////////////////////////////////////////////////////////

i64 arr[10001000];
i64 brr[10001000];
i64 seg[10001000];

void build(i64 l,i64 r,i64 index)
{
    if(l==r)
    {
        seg[index]=arr[l];
    }
    else
    {
        i64 mid=l + (r-l)/2;

        build(l,mid,left(index));
        build(mid+1,r,right(index));

        seg[index]=seg[left(index)]+seg[right(index)];
    }
}

i64 query(i64 x,i64 y,i64 node,i64 l,i64 r)
{
    if(x>r or y<l) return 0;
    if(x<=l and y>=r) return seg[node];

    i64 mid=l+(r-l)/2;

    i64 q1=query(x,y,left(node),l,mid);
    i64 q2=query(x,y,right(node),mid+1,r);

    return q1+q2;
}

int main()
{
    std::ios::sync_with_stdio(false);

    i64 t; cin>>t;

    while(t--)
    {
        i64 n,m; cin>>n>>m;
        
        FOR(i,0,n-1) cin>>arr[i];
        FOR(i,1,n) cin>>brr[i];

        build(0,n-1,0);

        i64 score=0;

        i64 right_bound=n,left_bound=-1;

        bool flag=true;

        // DEBUG(query(0,n-1,0,0,n-1));

        FOR(i,1,m)
        {
            // DEBUG(i);
            i64 max_sum=-1;
            i64 boundary_sum=-1;
            i64 selected_index=left_bound+1;

            i64 loop=0;

            // DEBUG(right_bound-brr[i]);
        
            for(i64 j=left_bound+1;j<=right_bound-brr[i];j++)
            {
                i64 temp_sum=query(j,j+brr[i]-1,0,0,n-1);
                i64 temp_boundary=arr[j]+arr[j+brr[i]-1];

                if(temp_sum>max_sum)
                {
                    max_sum=temp_sum;
                    boundary_sum=temp_boundary;
                    selected_index=j;
                }
                else if(temp_sum == max_sum)
                {
                    if(boundary_sum<temp_boundary)
                    {
                        selected_index=j;
                        boundary_sum=temp_boundary;
                    }
                }
                // loop++;
            }

            // DEBUG(loop);
            // DEBUG(left_bound);
            // DEBUG(right_bound);
            // DEBUG(score);
            // DEBUG(flag);
            // DEBUG(max_sum);

            if(flag) score+=max_sum;
            else score-=max_sum;
            flag=!flag;
            left_bound=selected_index;
            right_bound=selected_index+brr[i]-1;
            // cout<<endl;
        }

        cout<<score<<endl;
    }
}