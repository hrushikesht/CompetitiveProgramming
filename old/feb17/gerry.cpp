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

int a[100000010];
int seg[100000010];

void build(int l,int r,int index)
{
    if(l==r)
    {
        seg[index]=a[l];
    }
    else
    {
        int mid=(l+r)/2;

        build(l,mid,left(index));
        build(mid+1,r,right(index));
        seg[index]=seg[left(index)]+seg[right(index)];
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
    std::ios::sync_with_stdio(false);

    int t; cin>>t;

    while(t--)
    {

        // cout<<"\n";
        // DEBUG(t);
        int o1,o2; cin>>o1>>o2; //o1 = total states, o2=total districts in each state

        int count=0;
        int pro=o1*o2;

        int half_o2=o2/2;
        int half_o1=o1/2;

        FOR(i,0,o1*o2-1) 
        {
            int temp; cin>>temp;

            count+=temp;
            a[i]=temp;
        }

        if(count<(o1/2)*(o2/2))
        {
            cout<<0<<endl;
            continue;
        }

        build(0,pro-1,0);

        // DEBUG(query(0,0,0,0,pro-1));

        i64 counter=0;

        bool flag=true;

        for(int i=0;i<o2;i+=1)
        {
            // DEBUG(i);

            counter=0;
            int loop2=0;

            if(i!=0)
            {
                int temp_sum=query(0,i-1,0,0,pro-1) + query(pro+i-o2,pro-1,0,0,pro-1);
                // DEBUG(i-1);
                // DEBUG(pro-i+o2);
                if(temp_sum>half_o2) counter++;
            }

            for(int j=i;j<pro-o2+1;j+=o2)
            {
                loop2++;
                // DEBUG(j);
                int temp_sum=query(j,j+o2-1,0,0,pro-1);
                // DEBUG(temp_sum);

                if(temp_sum>half_o2)
                {
                    counter++;
                }
            }

            // DEBUG(loop2);
            // DEBUG(counter);
            if(counter>half_o1)
            {
                cout<<1<<endl;
                flag=false;
                break;
            }
            // cout<<endl;
        }

        if(!flag)
        {
            continue;
        }
        else
        {
            cout<<0<<endl;
            continue;
        }


    }

}