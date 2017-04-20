#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define i64 long long int

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = 1<<29;
#define ll long long
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

stack<int> for_dfs;
vector<int> G[100000];
vector<int> len;
vector<int>::iterator it;

void dfs(int node,bool *visited,int curr_length)
{
	visited[node]=true;

	int index=0,pseudo_index=0;

	for(it=G[node].begin();it<G[node].end();++it,++index)
	{
		if(visited[*it]) 
		{
			continue;
		}
		dfs(*it,visited,curr_length+1);
	}

	/*
	if(!for_dfs.empty())
	{
		int next_node = for_dfs.top();
		for_dfs.pop();

		dfs(next_node,visited,curr_length+1);
	}
	else{

	}
	*/
}


int main()
{
	int n;cin>>n;


	REP(i,n-1)
	{
		int a; cin>>a;
		int b; cin>>b;
		G[a-1].pb(b-1);
		G[b-1].pb(a-1);	
	}

	bool visited[n]={false};
	
	dfs(0,visited,0);

}