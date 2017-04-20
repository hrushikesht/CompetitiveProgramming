#include <bits/stdc++.h>
#include <unordered_map>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define i64 long long int

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(i64 i=0;i<(n);i++)
#define FOR(i,a,b) for(i64 i=(a);i<=(b);i++)
#define FORD(i,a,b) for(i64 i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = 1<<29;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void setBit(int & n, int b) { n |= two(b); }
inline void unsetBit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
inline bool sortDown(int x,int y){return x>y;}
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
using namespace std;
/////////////////////////////////////////////////////////////////////

vector<int> adj[100010];
int col[100010];
set<int> store;
int curr_col;
bool glo_flag;
int found_node=-1;
int last_node;
bool last_flag=false;


void dfs(int node,bool *visited)
{
    visited[node]=true;

    // DEBUG(node);
    // DEBUG(col[node]);

    if(col[node]==curr_col)
    {
        for(auto it=adj[node].begin();it!=adj[node].end();++it)
        {
            if(!visited[*it])
            {
                last_node=node;
                last_flag=true;
                dfs(*it,visited);
            }
        }
    }
    else
    {
        found_node=node;
        glo_flag=false;
    }

}

int main()
{
    std::ios::sync_with_stdio(false);

    int n; cin>>n;

    FOR(i,1,n-1)
    {
        int a,b; cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    FOR(i,1,n) cin>>col[i];


    bool visited2[100010]={false};
    glo_flag=true;
    curr_col=col[1];
    dfs(1,visited2);

    int final_last_node=last_node;

    if(found_node!=-1)
    {
        // DEBUG(found_node);
        int i=found_node;
        // bool flag=true;
        bool visited[100010]={false};
        visited[i]=true;

        glo_flag=true;

        // DEBUG(i);
        for(auto it=adj[i].begin();it<adj[i].end();++it)
        {   
            curr_col=col[*it];
            // DEBUG(curr_col);
            dfs(*it,visited);
            
            if(!glo_flag) break;
        }

        if(glo_flag)
        {
            cout<<"YES"<<endl;
            cout<<i<<endl;
            return 0;
        }
        else if(last_flag)
        {
            // DEBUG(final_last_node);
            int i=last_node;
            // bool flag=true;
            bool visited[100010]={false};
            visited[i]=true;

            glo_flag=true;

            // DEBUG(i);
            for(auto it=adj[i].begin();it<adj[i].end();++it)
            {   
                curr_col=col[*it];
                // DEBUG(curr_col);
                dfs(*it,visited);
                
                if(!glo_flag) break;
            }
            if(glo_flag)
            {
                cout<<"YES"<<endl;
                cout<<i<<endl;
                return 0;
            }
            else
            {
                // cout<<"hi"<<endl;
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    else
    {
        cout<<"YES"<<endl;
        cout<<1<<endl;
        return 0;
    }

    


}