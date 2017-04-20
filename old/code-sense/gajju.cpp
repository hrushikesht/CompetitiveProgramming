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


void dfs(vector<i64> adj[],int node,int length,bool *visited,i64 *len)
{
	visited[node]=true;
	len[node]=length;
	// DEBUG(node);

	for(auto it=adj[node].begin();it!=adj[node].end();++it)
	{
		if(!visited[*it])
		{
			// DEBUG(*it);	
			dfs(adj,*it,length+1,visited,len);
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);

	i64 t; cin>>t;

	while(t--)
	{
		i64 n,m; cin>>n>>m;
		
		i64 len[n+10];
		i64 rest[n+10];
		vector<i64> adj[n+10];

		FOR(i,1,n-1)
		{
			i64 a,b; cin>>a>>b;

			adj[a].pb(b);
			adj[b].pb(a);
		}

		FOR(i,1,m)
		{
			cin>>rest[i];
		}

		len[1]=0;

		bool visited[1000010]={false};
		dfs(adj,1,0,visited,len);

		double sum=0;

		FOR(i,1,m)
		{
			sum+=len[rest[i]];
		
		}

		sum = (2.0*sum)/m;

		std::cout<<std::setprecision(6)<<std::fixed;
		cout<<sum<<endl;
	}
}