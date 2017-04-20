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

ll checkTwo()
{
    FOR(i,1,4)
    {
        FOR(j,1,4)
        {
            if(mat[i][j]==1)
            {
                if(j!=4)
                {
                    if(mat[i][j+1]==1)
                    {
                        return 2;
                    }
                }
                else
                {
                    if(i!=4)
                    {
                        if(mat[i+1][j+1]==1)
                        {
                            return 2;
                        }
                    }
                    else
                    {
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}

ll checkThree()
{
    FOR(i,1,4)
    {
        FOR(j,1,4)
        {
            if(mat[i][j]==1)
            {
                if(j<=2)
                {
                    if(mat[i][j+1]==1 and mat[i][j+2]==1)
                    {
                        return 3;
                    }
                }
                else if(i<=2)
                {
                    if(mat[i+1][j]==1 and mat[i+2][j]==1)
                    {
                        return 3;
                    }
                }
                else
                {
                    return 0;
                }
            }
        }
    }
    return 0;
}

ll checkFour()
{
    FOR(i,1,4)
    {
        if(mat[i][1]==1 and mat[i][2]==1 and mat[i][3]==1 and mat[i][4]==1)
        {
            return 4;
        }
    }

    FOR(i,1,4)
    {
        if(mat[1][i]==1 and mat[2][i]==1 and mat[3][i]==1 and mat[4][i]==1)
        {
            return 4;
        }
    }

    FOR(i,1,3)
    {
        FOR(j,1,3)
        {
            if(mat[i][j]==1)
            {
                if(mat[i][j+1]==1 and mat[i+1][j]==1 and mat[i+1][j+1]==1)
                {
                    return 1;
                }
            }
            else return 0;
        }
    }
    return 0;
}

ll checkSix()
{
    FOR(i,1,3)
    {
        FOR(j,1,3)
        {
            if(mat[i][j]==1)
            {
                if(mat[i][j+1]==1)
                {
                    if(j<=2 and mat[i][j+1]==1)
                    {
                        if(mat[i+1][j]==1 and mat[i+1][j+1]==1 and mat[i+1][j+2]==1)
                        {
                            return 4;
                        }
                    }
                    else if(i<=1)
                    {
                        if(mat[i+1][j]==1 and mat[i+1][j+1] and mat[i+2][j]==1 and mat[i+2][j+1]==1)
                        {
                            return 4;
                        }
                    }
                    else return 0;
                }
            }
        }
    }
    return 0;
}

ll checkEight()
{
    
}

ll findGrundy()
{
    ll sum=0;

    FOR(i,1,4) FOR(j,1,4) sum+=mat[i][j];

    if(!(sum%5) or !(sum%13) or !(sum%7))
    {
        return 0;
    }
    else
    {
        if(sum==2)
        {
            return checkTwo();
        }
        else if(sum==3)
        {
            return checkThree();
        }
        else if(sum==4)
        {
            return checkFour();
        }
        else if(sum==6)
        {
            return checkSix();
        }
        else if(sum==8)
        {
            return checkEight();
        }
    }


}

int main()
{
    std::ios::sync_with_stdio(false);

    ll t; cin>>t;

    while(t--)
    {
        ll n,m; cin>>n>>m;

        string s[5];

        FOR(k,1,n)
        {
            FOR(i,1,4)
            {
                cin>>s[i];

                REP(j,n)
                {
                    mat[i][j]=s[j]-48;
                }
            }

            ll sg=findGrundy();

            grundy[k]=sg;
        }
    }
}