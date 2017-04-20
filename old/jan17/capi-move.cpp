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


/*
void dfs(int node,bool *visited)
{
	visited[node]=true;

	for(auto it=G[node].begin();it<G[a].end();++it)
	{
		if(vi)
	}
}
*/

int main()
{
	std::ios::sync_with_stdio(false);

	int t; cin>>t;

	while(t--)
	{
		vector<int> G[50010];
		vector< pair<int,int> > popu;

		int n; cin>>n;

		FOR(i,1,n)
		{
			int temp; cin>>temp;
			popu.pb(mp(temp,i));
		}

		FOR(i,1,n-1)
		{
			int a,b; cin>>a>>b;

			G[a].pb(b);
			G[b].pb(a);
		}

		/*
		bool visited[50010]=false;

		FOR(i,1,n)
		{
			if(!visited[i])
			{
				dfs(i,visited);
			}
		}
		*/

		sort(popu.begin(),popu.end());

		FOR(i,1,n)
		{
			int index=popu.size();
			for(auto it=popu.end() -1;it>=popu.begin();--it)
			{
				if(find(G[i].begin(),G[i].end(),it->S) == G[i].end() and (it->S != i))
				{
					cout<<it->S<<" ";
					break;
				}
				--index;
			}

			if(index==0)
			{
				cout<<0<<" ";
			}
		}

		/*
		cout<<endl;
		for(auto it=popu.begin();it<popu.end();++it)
		{
			cout<<it->F<<" "<<it->S<<endl;
		}
		*/

		cout<<endl;

		// popu.clear();
	}
}