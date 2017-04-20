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

vector<int> dep[100000];
vector<int> install;
set<int> final;

void dfs(int node,bool *is_checked)
{
	is_checked[node]=true;
	final.insert(node);

	for(auto it=dep[node].begin();it<dep[node].end();++it)
	{
		if(!is_checked[*it])
			dfs(*it,is_checked);
	}
}


int main()
{
	std::ios::sync_with_stdio(false);

	int q; cin>>q;

	REP(i,q)
	{
		bool is_done[100000]={false};
		bool is_checked[100000]={false};
		vector<int> ans;
		

		int n,m; cin>>n>>m;
	
		FOR(j,1,n)
		{
			int d; cin>>d;

			FOR(k,1,d)
			{
				int temp; cin>>temp;
				dep[j].pb(temp);
			}
		}
		FOR(j,1,m)
		{
			int temp; cin>>temp;
			install.pb(temp);
		}

		sort(install.begin(),install.end());

		for(auto it=install.begin();it<install.end();++it)
		{
			dfs(*it,is_checked);
		}

		set<int>::iterator it=final.begin();

		while(1)
		{
			if(ans.size()==final.size())
			{
				break;
			}

			// DEBUG(*it);

			if(is_done[*it])
			{
				// DEBUG(*it);
				++it;
				continue;
			}

			if(dep[*it].size()==0)
			{
				is_done[*it]=true;
				ans.pb(*it);
				it=final.begin();
			}
			else
			{
				bool flag=true;
				for(auto it2=dep[*it].begin();it2!=dep[*it].end();++it2)
				{
					if(!is_done[*it2])
					{
						flag=false;
						break;
					}
				}

				if(flag)
				{
					is_done[*it]=true;
					ans.pb(*it);
					it=final.begin();
				}
				else
				{
					++it;
				}
			}
		}

		cout<<ans.size()<<endl;
		for(auto it=ans.begin();it<ans.end();++it)
		{
			cout<<*it<<" ";
		}
		cout<<endl;


	}




}