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

vector<int> G[1010];
vector< int > scc[1010];
// unordered_map< pair< int,int >,int > M;
bool visited[1010]={false};
bool is_scc_gov[1010]={false};
bool is_gov[1010]={false};
int conn[1010]={0};
int M[1010][1010];

void dfs(int node,int index)
{
	// conn[index]+=1;
	if(is_gov[node]==true)
	{
		// cout<<"bro"<<endl;
		is_scc_gov[index]=true;
	}

	scc[index].pb(node);
	visited[node]=true;

	for(auto it=G[node].begin();it<G[node].end();++it)
	{
		if(M[node][*it]==0 && M[*it][node]==0)
		{
			conn[index]+=1;
			M[node][*it]++;
			M[*it][node]++;
		}
		if(visited[*it]==false)
		{
			dfs(*it,index);
		}
	}
}


int main()
{
	std::ios::sync_with_stdio(false);

	int n; cin>>n;
	int m; cin>>m;
	int k; cin>>k;

	REP(i,k)
	{
		int temp; cin>>temp;
		is_gov[temp]=true;
	}

	REP(i,m)
	{
		int a; cin>>a;
		int b; cin>>b;
		G[a].pb(b);
		G[b].pb(a);
		M[a][b]=0;
		M[b][a]=0;
	}

	int index=0;

	FOR(i,1,n)
	{
		if(visited[i]==false)
		{
			dfs(i,index);
			index++;
		}
	}

	/*
	FOR(i,0,index-1)
	{
		cout<<"scc for i = "<<i<<" : "<<endl;
		cout<<" is gov ? -> "<<is_scc_gov[i]<<endl;
		for(auto it=scc[i].begin();it<scc[i].end();++it)
		{
			cout<<(*it)<<" ";
		}
		cout<<endl;
	}
	*/
	

	/*
	FOR(i,0,index-1)
	{
		DEBUG(i);
		DEBUG(conn[i]);
	}
	*/

	i64 maxito = 0;
	i64 remain=n;
	i64 ans=0,total_non_gov=0,total_non_gov_conn=0;


	FOR(i,0,index-1)
	{

		if(is_scc_gov[i])
		{
			ans+=((((scc[i].size())*(scc[i].size()-1))/2) - conn[i] );
			remain-=scc[i].size();
	
			// DEBUG(maxito);
			// DEBUG(scc[i].size());

			if(maxito < scc[i].size())
			{
				// cout<<"bro"<<endl;
				maxito=scc[i].size();
			}
		}
		else
		{
			total_non_gov+=scc[i].size();
			total_non_gov_conn += conn[i];
		}
	}

	// DEBUG(total_non_gov_conn);
	// DEBUG(total_non_gov);
	// DEBUG(ans);

	ans += ((total_non_gov*(total_non_gov-1))/2) - total_non_gov_conn;

	// DEBUG(ans);

	// DEBUG(remain);
	// DEBUG(maxito);

	cout<<((remain*maxito) + ans)<<endl;

}