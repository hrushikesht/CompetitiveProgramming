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

ll mat[10][10];
ll grundy[100010];

#define R 10
#define C 10

ll maxHist(ll row[])
{
    stack<ll> result;
 
    ll top_val;
 
    ll max_area = 0;
    ll area = 0;
 
    ll i = 0;
    while (i < C)
    {
        if (result.empty() || row[result.top()] <= row[i])
        result.push(i++);
 
        else
        {
            top_val = row[result.top()];
            result.pop();
            area = top_val * i;
 
            if (!result.empty())
                area = top_val * (i - result.top() - 1 );
            max_area = max(area, max_area);
        }
    }
     while (!result.empty())
    {
        top_val = row[result.top()];
        result.pop();
        area = top_val * i;
        if (!result.empty())
            area = top_val * (i - result.top() - 1 );
 
        max_area = max(area, max_area);
    }
    return max_area;
}

ll maxRectangle(ll A[][C])
{
    ll result = maxHist(A[0]);
    for (ll i = 1; i < R; i++)
    {
        for (ll j = 0; j < C; j++)
            if (A[i][j]) A[i][j] += A[i - 1][j];
        
        result = max(result, maxHist(A[i]));
    }

    return result;
}

ll findGrundy()
{
    ll sum=0;

    FOR(i,0,3) FOR(j,0,3) sum+=mat[i][j];

    if(sum==1 or sum==16) return sum;

    DEBUG(sum);

    if(!(sum%5) or !(sum%13) or !(sum%7))
    {
        cout<<"hi"<<endl;
        return 0;
    }
    else
    {
        ll res=maxRectangle(mat);
        DEBUG(res);

        if(res==sum)
        {
            if(res==2) return 2;
            if(res==3) return 3;
            if(res==4)
            {
                FOR(i,0,3)
                {
                    if(mat[i][0]==1 and mat[i][1]==1 and mat[i][2]==1 and mat[i][3]==1)
                    {
                        return 4;
                    }
                }

                FOR(i,1,3)
                {
                    if(mat[0][i]==1 and mat[1][i]==1 and mat[2][i]==1 and mat[3][i]==1)
                    {
                        return 4;
                    }
                }
            }

            if(res==6) return 4;
            if(res==8) return 3;
            if(res==9) return 1;
            if(res==12) return 2;
        }
        else return 0;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);

    ll t; cin>>t;

    while(t--)
    {
        ll n,m; cin>>n>>m;

        string s;

        FOR(k,1,n)
        {

            FOR(i,0,3)
            {
                cin>>s;
                REP(j,4)
                {
                    mat[i][j]=s[j]-48;

                    // cout<<mat[i][j+1]<<" ";
                }
                // cout<<endl;
            }


            DEBUG(k);
            ll sg=findGrundy();
            DEBUG(sg);

            grundy[k]=sg;
            cout<<endl;
        }
    }
}