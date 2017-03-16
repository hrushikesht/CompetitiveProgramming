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

stack<int> vert;
list<int> G[100010];
vector< pair<int,int> > edges;
vector<int> euler_cycle;
map< pair<int,int>, int > M;

int main()
{
	std::ios::sync_with_stdio(false);

	int n,e; cin>>n>>e;

	FOR(i,1,e)
	{
		int a,b; cin>>a>>b;

		G[a].pb(b);
		G[b].pb(a);

		edges.pb(mp(a,b));
		M[mp(a,b)]=i;
	}
	
	if(n==1 and e==0)
	{
		cout<<"YES"<<endl;
		return 0;
	}

	if(n>e)
	{
		cout<<"NO"<<endl;
		return 0;
	}

	FOR(i,1,n)
	{
		if(G[i].size()==0 or G[i].size()&1==1)
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}

	int curr=1;

	do
	{
		// DEBUG(curr);
		// DEBUG(G[curr].front());
		// DEBUG(vert.size());
		if(G[curr].size()==0)
		{
			// DEBUG(curr);
			euler_cycle.pb(curr);

			if(euler_cycle.size()>1)
			{
				/*
				auto it1= find(edges.begin(),edges.end(),mp(*(euler_cycle.end()-2),curr));

				if(it1==edges.end())
				{
					// DEBUG(curr);
					auto it2= find(edges.begin(),edges.end(),mp(curr, *(euler_cycle.end()-2)));
					
					it2->F=*(euler_cycle.end()-2);
					it2->S=curr;
				}
				*/
				int a=*(euler_cycle.end()-2);
				int b=curr;

				int yo = M.count(mp(a,b));
				if(yo==0)
				{
					int index=M[mp(b,a)];
					edges.at(index-1)=mp(a,b);
				}
			}

			curr = vert.top();
			vert.pop();
		}
		else
		{
			vert.push(curr);
			int next = G[curr].front();
			G[curr].remove(next);
			G[next].remove(curr);

			curr=next;
		}

	}
	while(!vert.empty() or G[curr].size()!=0);

	/*
	auto it2=find(edges.begin(),edges.end(),mp(*(euler_cycle.end()-2),*(euler_cycle.end()-1)));

	if(it2==edges.end())
	{
		auto it2= find(edges.begin(),edges.end(),mp(*(euler_cycle.end()-1), *(euler_cycle.end()-2)));
					
		it2->F=*(euler_cycle.end()-2);
		it2->S=*(euler_cycle.end()-1);
	}

	it2=find(edges.begin(),edges.end(),mp(*(euler_cycle.end()-1),*(euler_cycle.begin())));

	if(it2==edges.end())
	{
		auto it2= find(edges.begin(),edges.end(),mp(*(euler_cycle.begin()),*(euler_cycle.end()-1)));
					
		it2->S=*(euler_cycle.begin());
		it2->F=*(euler_cycle.end()-1);
	}
	*/

	int a=*(euler_cycle.end()-2);
	int b=*(euler_cycle.end()-1);

	int yo = M.count(mp(a,b));
	if(yo==0)
	{
		int index=M[mp(b,a)];
		edges.at(index-1)=mp(a,b);
	}

	a=*(euler_cycle.end()-1);
	b=*(euler_cycle.begin());

	yo = M.count(mp(a,b));
	if(yo==0)
	{
		int index=M[mp(b,a)];
		edges.at(index-1)=mp(a,b);
	}


	/*
	FOR(i,1,n)
	{	
		cout<<i<<" : ";
		for(list<int>::iterator it=G[i].begin();it != G[i].end();++it)
		{
			cout<<*it<<" ";
		}
		cout<<endl;
	}
	*/

	cout<<"YES"<<endl;
	for(auto it=edges.begin();it<edges.end();++it)
	{
		cout<<it->F<<" "<<it->S<<endl;
	}
	return 0;
}