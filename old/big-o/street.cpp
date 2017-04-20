#include <bits/stdc++.h>
#include <unordered_map>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define i64 long long int

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
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

vector< int > adj[110];
int id[110][110]={-1};

int dfs(int to_find, int node,int iden,bool *visited)
{
	if(to_find==node)
	{
		return 1;
	}

	visited[node]=true;

	if(!visited[node])
		for(auto it=adj[node].begin();it!=adj[node],++it)
		{
			if(iden == id[node][*it])
			{
				dfs(to_find,*it,iden,visited);
			}
		}
}

int main()
{
	std::ios::sync_with_stdio(false);

	int n,m; cin>>n>>m;

	FOR(i,1,m)
	{
		int a,b,c; cin>>a>>b>>c;

		adj[a].pb(b);
		id[a][b]=c;
	}

	int q; cin>>q;

	FOR(i,1,q)
	{
		int a,b; cin>>a>>b;
		count=0;1
		for(auto adj[a].begin();it!=adj[a].end();it++)
		{
			bool visited[110]={false};
			int count+=dfs(b,*it,id[a][*it],visited);
		}
	}
}