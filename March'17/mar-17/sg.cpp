#include <bits/stdc++.h>
#include <unordered_map>
#include <utility>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define ll long long int

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)

#define all(v) (v).begin(),(v).end()

inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const ll INF = 1<<29;
inline ll two(ll n) { return 1 << n; }
inline ll test(ll n, ll b) { return (n>>b)&1; }
inline void setBit(ll & n, ll b) { n |= two(b); }
inline void unsetBit(ll & n, ll b) { n &= ~two(b); }
inline ll last_bit(ll n) { return n & (-n); }
inline ll ones(ll n) { ll res = 0; while(n && ++res) n-=n&(-n); return res; }

inline int parent(int x){return floor((x-1)/2);};
inline int left(int x) {return 2*x+1;};
inline int right(int x){return 2*x+2;};

inline bool sortDown(ll x,ll y){return x>y;}
inline bool sortPairSecond( std::pair< ll,ll > p1, std::pair< ll,ll > p2){ return p1.S>p2.S;}
inline bool sortDownByLen( std::pair< ll,ll > p1, std::pair< ll,ll > p2 ){ return p1.S-p1.F > p2.S-p2.F;}


#define MOD 1000000007
using namespace std;
/////////////////////////////////////////////////////////////////////



ll M[100010];
ll grundy[100010];
ll seg[1000000];

ll binToDeci(string s[])
{
    ll idx=1;
    ll ans=0;

    FORD(i,3,0)
    {
        FORD(j,3,0)
        {
            if(s[i][j]=='1')
            {
                ans+=idx;
            }
            idx*=2;
        }
    }
    return ans;
}

ll findGrundy(string s[])
{
    // cout<<"Entered Find Grundy: "<<endl;
    char *con;

    ll num=binToDeci(s);

    if(M[num]!=LLONG_MAX) return M[num];

    // DEBUG(num);

    set<ll> mex;

    if(num==0)
    {
        // cout<<"Base case"<<endl;
        M[num]=0;
        return 0;
    }

    //1x1
    // cout<<"1x1"<<endl;
    REP(i,4)
    {
        REP(j,4)
        { 
           if(s[i][j]=='1') 
            {
                s[i][j]='0';
                // DEBUG(i);
                // DEBUG(j);
                mex.insert(findGrundy(s));
                s[i][j]='1';
            }
        }
    }


    //1x2
    // cout<<"1x2"<<endl;
    REP(i,4)
    {
        REP(j,3)
        {
            if(s[i][j]=='1' and s[i][j+1]=='1')
            {
                // DEBUG(i);
                // DEBUG(j);
                s[i][j]='0';
                s[i][j+1]='0';
                mex.insert(findGrundy(s));
                s[i][j]='1';
                s[i][j+1]='1';
            }
        }
    }

    //2x1
    // cout<<"2x1"<<endl;
    REP(i,3)
    {
        REP(j,4)
        {
            if(s[i][j]=='1' and s[i+1][j]=='1')
            {
                s[i][j]='0';
                s[i+1][j]='0';
                mex.insert(findGrundy(s));
                s[i][j]='1';
                s[i+1][j]='1';
            }
        }
    }

    //2x2
    // cout<<"2x2"<<endl;
    REP(i,3)
    {
        REP(j,3)
        {
            if(s[i][j]=='1' and s[i][j+1]=='1' and s[i+1][j]=='1' and s[i+1][j+1]=='1')
            {
                s[i][j]='0';
                s[i][j+1]='0';
                s[i+1][j]='0';
                s[i+1][j+1]='0';
                mex.insert(findGrundy(s));
                s[i][j]='1';
                s[i][j+1]='1';
                s[i+1][j]='1';
                s[i+1][j+1]='1';
            }
        }
    }

    //1x4
    // cout<<"1x4"<<endl;
    REP(i,4)
    {
        ll j=0;
        
        if(s[i][j]=='1' and s[i][j+1]=='1' and s[i][j+2]=='1' 
            and s[i][j+3]=='1')
        {
            // cout<<"hi"<<endl;
            s[i][j]='0';
            s[i][j+1]='0';
            s[i][j+2]='0';
            s[i][j+3]='0';
            mex.insert(findGrundy(s));
            s[i][j]='1';
            s[i][j+1]='1';
            s[i][j+2]='1';
            s[i][j+3]='1';
        }
        
    }

    //1x3
    // cout<<"1x3"<<endl;
    REP(i,4)
    {
        REP(j,2)
        {
            if(s[i][j]=='1' and s[i][j+1]=='1' and s[i][j+2]=='1' )
            {
                s[i][j]='0';
                s[i][j+1]='0';
                s[i][j+2]='0';
                mex.insert(findGrundy(s));
                s[i][j]='1';
                s[i][j+1]='1';
                s[i][j+2]='1';
            }
        }
    }

    //3x1
    REP(i,2)
    {
        REP(j,4)
        {
            if(s[i+1][j]=='1' and s[i+2][j]=='1' and s[i][j]=='1')
            {
                s[i+1][j]='0';
                s[i+2][j]='0';
                s[i][j]='0';
                mex.insert(findGrundy(s));
                s[i+1][j]='1';
                s[i+2][j]='1';
                s[i][j]='1';
            }
        }
    }

    //4x1
    REP(i,1)
    {
        REP(j,4)
        {
            if(s[i+1][j]=='1' and s[i+2][j]=='1' and s[i][j]=='1' and s[i+3][j]=='1')
            {
                s[i+1][j]='0';
                s[i+2][j]='0';
                s[i][j]='0';
                s[i+3][j]='0';
                mex.insert(findGrundy(s));
                s[i+1][j]='1';
                s[i+2][j]='1';
                s[i][j]='1';
                s[i+3][j]='1';
            }
        }
    }

    //2x3
    // cout<<"2x3"<<endl;
    REP(i,3)
    {
        REP(j,2)
        {
            if(s[i][j]=='1' and s[i][j+1]=='1' and s[i][j+2]=='1'
                and s[i+1][j]=='1' and s[i+1][j+1]=='1' and s[i+1][j+2]=='1')
            {
                s[i][j]='0';
                s[i][j+1]='0';
                s[i][j+2]='0';
                s[i+1][j]='0';
                s[i+1][j+1]='0';
                s[i+1][j+2]='0';
                mex.insert(findGrundy(s));
                s[i][j]='1';
                s[i][j+1]='1';
                s[i][j+2]='1';
                s[i+1][j]='1';
                s[i+1][j+1]='1';
                s[i+1][j+2]='1';
            }
        }
    }

    //3x2
    // cout<<"3x2"<<endl;
    REP(i,2)
    {
        REP(j,3)
        {
            if(s[i][j]=='1' and s[i][j+1]=='1' and s[i+1][j]=='1' and s[i+1][j+1]=='1' and s[i+2][j]=='1' and s[i+2][j+1]=='1')
            {
                s[i][j]='0';
                s[i][j+1]='0';
                s[i+1][j]='0';
                s[i+1][j+1]='0';
                s[i+2][j]='0';
                s[i+2][j+1]='0';
                mex.insert(findGrundy(s));
                s[i][j]='1';
                s[i][j+1]='1';
                s[i+1][j]='1';
                s[i+1][j+1]='1';
                s[i+2][j]='1';
                s[i+2][j+1]='1';
            }
        }
    }

    //2x4
    // cout<<"2x4"<<endl;
    REP(i,3)
    {
        REP(j,1)
        {
            if(s[i][j]=='1' and s[i][j+1]=='1' and s[i][j+2]=='1' and s[i][j+3]=='1'
                and s[i+1][j]=='1' and s[i+1][j+1]=='1' and s[i+1][j+2]=='1' and s[i+1][j+3]=='1')
            {
                s[i][j]='0';
                s[i][j+1]='0';
                s[i][j+2]='0';
                s[i][j+3]='0';
                s[i+1][j]='0';
                s[i+1][j+1]='0';
                s[i+1][j+2]='0';
                s[i+1][j+3]='0';
                mex.insert(findGrundy(s));
                s[i][j]='1';
                s[i][j+1]='1';
                s[i][j+2]='1';
                s[i][j+3]='1';
                s[i+1][j]='1';
                s[i+1][j+1]='1';
                s[i+1][j+2]='1';
                s[i+1][j+3]='1';
            }
        }
    }

    //4x2
    // cout<<"4x2"<<endl;
    REP(i,1)
    {
        REP(j,3)
        {
            if(s[i][j]=='1' and s[i][j+1]=='1' and s[i+1][j]=='1' and s[i+1][j+1]=='1' and s[i+2][j]=='1' and s[i+2][j+1]=='1' and s[i+3][j]=='1' and s[i+3][j+1]=='1')
            {
                s[i][j]='0';
                s[i][j+1]='0';
                s[i+1][j]='0';
                s[i+1][j+1]='0';
                s[i+2][j]='0';
                s[i+2][j+1]='0';
                s[i+3][j]='0';
                s[i+3][j+1]='0';
                mex.insert(findGrundy(s));
                s[i][j]='1';
                s[i][j+1]='1';
                s[i+1][j]='1';
                s[i+1][j+1]='1';
                s[i+2][j]='1';
                s[i+2][j+1]='1';
                s[i+3][j]='1';
                s[i+3][j+1]='1';
            }
        }
    }

    //3x3
    // cout<<"3x3"<<endl;
    REP(i,2)
    {
        REP(j,2)
        {
            if(s[i][j]=='1' and s[i][j+1]=='1' and s[i][j+2]=='1'
                and s[i+1][j]=='1' and s[i+1][j+1]=='1' and s[i+1][j+2]=='1'
                and s[i+2][j]=='1' and s[i+2][j+1]=='1' and s[i+2][j+2]=='1')
            {
                s[i][j]='0';
                s[i][j+1]='0';
                s[i][j+2]='0';
                s[i+1][j]='0';
                s[i+1][j+1]='0';
                s[i+1][j+2]='0';
                s[i+2][j]='0';
                s[i+2][j+1]='0';
                s[i+2][j+2]='0';
                mex.insert(findGrundy(s));
                s[i][j]='1';
                s[i][j+1]='1';
                s[i][j+2]='1';
                s[i+1][j]='1';
                s[i+1][j+1]='1';
                s[i+1][j+2]='1';
                s[i+2][j]='1';
                s[i+2][j+1]='1';
                s[i+2][j+2]='1';
            }
        }
    }

    //3x4
    // cout<<"3x4"<<endl;
    REP(i,2)
    {
        REP(j,1)
        {
            if(s[i][j]=='1' and s[i][j+1]=='1' and s[i][j+2]=='1' and s[i][j+3]=='1'
                and s[i+1][j]=='1' and s[i+1][j+1]=='1' and s[i+1][j+2]=='1' and s[i+1][j+3]=='1'
                and s[i+2][j]=='1' and s[i+2][j+1]=='1' and s[i+2][j+2]=='1' and s[i+2][j+3]=='1')
            {
                s[i][j]='0';
                s[i][j+1]='0';
                s[i][j+2]='0';
                s[i][j+3]='0';
                s[i+1][j]='0';
                s[i+1][j+1]='0';
                s[i+1][j+2]='0';
                s[i+1][j+3]='0';
                s[i+2][j]='0';
                s[i+2][j+1]='0';
                s[i+2][j+2]='0';
                s[i+2][j+3]='0';
                mex.insert(findGrundy(s));
                s[i][j]='1';
                s[i][j+1]='1';
                s[i][j+2]='1';
                s[i][j+3]='1';
                s[i+1][j]='1';
                s[i+1][j+1]='1';
                s[i+1][j+2]='1';
                s[i+1][j+3]='1';
                s[i+2][j]='1';
                s[i+2][j+1]='1';
                s[i+2][j+2]='1';
                s[i+2][j+3]='1';
            }
        }
    }

    //4x3
    // cout<<"4x3"<<endl;
    REP(i,1)
    {
        REP(j,2)
        {
            if(s[i][j]=='1' and s[i][j+1]=='1' and s[i][j+2]=='1'
                and s[i+1][j]=='1' and s[i+1][j+1]=='1' and s[i+1][j+2]=='1'
                and s[i+2][j]=='1' and s[i+2][j+1]=='1' and s[i+2][j+2]=='1'
                and s[i+3][j]=='1' and s[i+3][j+1]=='1' and s[i+3][j+2]=='1')
            {
                s[i][j]='0';
                s[i][j+1]='0';
                s[i][j+2]='0';
                s[i+1][j]='0';
                s[i+1][j+1]='0';
                s[i+1][j+2]='0';
                s[i+2][j]='0';
                s[i+2][j+1]='0';
                s[i+2][j+2]='0';
                s[i+3][j]='0';
                s[i+3][j+1]='0';
                s[i+3][j+2]='0';
                mex.insert(findGrundy(s));
                s[i][j]='1';
                s[i][j+1]='1';
                s[i][j+2]='1';
                s[i+1][j]='1';
                s[i+1][j+1]='1';
                s[i+1][j+2]='1';
                s[i+2][j]='1';
                s[i+2][j+1]='1';
                s[i+2][j+2]='1';
                s[i+3][j]='1';
                s[i+3][j+1]='1';
                s[i+3][j+2]='1';
            }
        }
    }

    //4x4
    // cout<<"4x4"<<endl;
    ll i=0,j=0;
    if(s[i][j]=='1' and s[i][j+1]=='1' and s[i][j+2]=='1' and s[i][j+3]=='1'
        and s[i+1][j]=='1' and s[i+1][j+1]=='1' and s[i+1][j+2]=='1' and s[i+1][j+3]=='1'
        and s[i+2][j]=='1' and s[i+2][j+1]=='1' and s[i+2][j+2]=='1' and s[i+2][j+3]=='1'
        and s[i+3][j]=='1' and s[i+3][j+1]=='1' and s[i+3][j+2]=='1' and s[i+3][j+3]=='1')
    {
        s[i][j]='0';
        s[i][j+1]='0';
        s[i][j+2]='0';
        s[i][j+3]='0';
        s[i+1][j]='0';
        s[i+1][j+1]='0';
        s[i+1][j+2]='0';
        s[i+1][j+3]='0';
        s[i+2][j]='0';
        s[i+2][j+1]='0';
        s[i+2][j+2]='0';
        s[i+2][j+3]='0';
        s[i+3][j]='0';
        s[i+3][j+1]='0';
        s[i+3][j+2]='0';
        s[i+3][j+3]='0';
        mex.insert(findGrundy(s));
        s[i][j]='1';
        s[i][j+1]='1';
        s[i][j+2]='1';
        s[i][j+3]='1';
        s[i+1][j]='1';
        s[i+1][j+1]='1';
        s[i+1][j+2]='1';
        s[i+1][j+3]='1';
        s[i+2][j]='1';
        s[i+2][j+1]='1';
        s[i+2][j+2]='1';
        s[i+2][j+3]='1';
        s[i+3][j]='1';
        s[i+3][j+1]='1';
        s[i+3][j+2]='1';
        s[i+3][j+3]='1';
    }

    // DEBUG(num);
    // cout<<"checking"<<endl;
    set<ll>::iterator it=mex.begin();
    set<ll>::iterator pre;

    if(*it==0)
    {
        // DEBUG(*it);
        pre=it;
        ++it;

        if(it!=mex.end())
        {
            for(;it!=mex.end();++it)
            {
                // DEBUG(*it);
                if(*pre+1 != *it)
                {
                    M[num]=*pre+1;
                    return *pre+1;
                }
                pre=it;
            }
        }

        // cout<<"*it==0 ;done"<<endl;

        // DEBUG(*pre+1);
        M[num]=*pre+1;
        return *pre+1;
    }
    else
    {
        // cout<<"*it!=0"<<endl;
        M[num]=0;
        // cout<<"ans: "<<0<<endl;
        return 0;
    }

}


void build(ll l,ll r,ll index)
{
    if(l==r)
    {
        seg[index]=grundy[l];
    }
    else
    {
        ll mid=(l+r)/2;
        build(l,mid,left(index));
        build(mid+1,r,right(index));
        seg[index]=seg[left(index)]^seg[right(index)];
    }
}

void update(ll i,ll x,ll node,ll l,ll r)
{
    seg[node]^=x;

    if(r-1>=l)
    {
        int mid=(l+r)/2;

        if(i<=mid)
        {
            update(i,x,left(node),l,mid);
        }
        else
        {
            update(i,x,right(node),mid+1,r);
        }
    }
}

ll query(ll x,ll y,ll node,ll l,ll r)
{
    if(x>r or y<l) return 0;
    if(x<=l and y>=r) return seg[node];

    ll mid=(l+r)/2;

    ll q1=query(x,y,left(node),l,mid);
    ll q2=query(x,y,right(node),mid+1,r);

    return q1^q2;
}

int main()
{
    std::ios::sync_with_stdio(false);

    FOR(i,0,100009)
    {
        M[i]=LLONG_MAX;
    }

    ll t; cin>>t;

    // DEBUG(t);

    while(t--)
    {
        string s[4];

        FOR(j,0,3)
        {
            cin>>s[j];
        }

        cout<<findGrundy(s)<<endl;
    }
}
