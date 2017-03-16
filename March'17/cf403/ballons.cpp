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


vector<ll> adj[200010];
stack<ll> vert;
stack<ll> p_col;

ll total_col;

ll color[200010];

void bfs(ll node,bool *visited)
{

}

int main()
{
    std::ios::sync_with_stdio(false);

    ll n; cin>>n;

    FOR(i,1,n-1)
    {
        ll a,b; cin>>a>>b;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    ll maxito=-1;
    ll max_index=1;

    FOR(i,1,n)
    {
        ll temp=adj[i].size();
        
        if(maxito<temp)
        {
            maxito=temp;
            max_index=i;
        }
    }

    total_col=maxito+1;

    color[max_index]=1;

    ll col_i=2;

    for(auto it=adj[max_index].begin();it<adj[max_index].end();++it)
    {
        vert.push(*it);
        p_col.push(1);
        color[*it]=col_i;
        col_i++;
    }



    bool visited[200010]={false};

    visited[max_index]=true;

    while(!vert.empty())
    {
        ll node=vert.top();
        vert.pop();

        ll node_col=p_col.top();
        p_col.pop();

        ll col_index=1;

        // DEBUG(node);
        // DEBUG(node_col);

        for(auto it=adj[node].begin();it<adj[node].end();++it)
        {
            if(!visited[*it])
            {
                // DEBUG(col_index);
                // DEBUG(color[node]);

                if(col_index==node_col)
                {
                    col_index++;
                }

                if(col_index==color[node])
                {
                    col_index++;
                }

                if(col_index==node_col)
                {
                    col_index++;
                }

                vert.push(*it);
                p_col.push(color[node]);
                color[*it]=col_index;
                col_index++;
                
            }
        }

        // DEBUG(node);

        visited[node]=true;
    }

    cout<<maxito+1<<endl;

    FOR(i,1,n)
    {
        cout<<color[i]<<" ";
    }
    cout<<endl;

}