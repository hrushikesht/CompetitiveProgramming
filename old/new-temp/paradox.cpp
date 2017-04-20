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

	int status[105][2];

	int dfs(int node,bool *visited,bool *conclusion)
	{
	bool a = conclusion[node];
	bool b = (bool) status[node][1];

	bool c = !(a^b);

	if(visited[status[node][0]]==true)
	{
		if(conclusion[status[node][0]] == c)
		{
			return 1;
		}
		else return 0;
	}

	conclusion[status[node][0]]= c;
	visited[status[node][0]] = true;

	dfs(status[node][0],visited,conclusion);

	}

	int main()
	{
	std::ios::sync_with_stdio(false);

	while(1)
	{
		int n;cin>>n;

		if(n==0)
			return 0;

		REP(i,n)
		{
			int temp; cin>>temp;
			string s; cin>>s;

			status[i][0]=temp-1;

			if(s=="true") status[i][1]=1;
			else status[i][1]=0;
		}

		bool visited[105]={false};
		bool conclusion[105]={false};

		conclusion[0]=true;
		visited[0]=true;
		bool res = dfs(0,conclusion,visited);



		if(res) cout<<"NOT PARADOX"<<endl;
		else cout<<"PARADOX"<<endl;
	}
	}
