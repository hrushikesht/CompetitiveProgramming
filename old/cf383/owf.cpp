#include <bits/stdc++.h>

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

int crush[110];
bool visited[110]={false};

int dfs(int node,int prime_node,int len)
{
	visited[node]=true;
	int new_node = crush[node];

	if(new_node == prime_node)
	{
		return (len+1);
	}
	else if(visited[new_node])
	{
		return -1;
	}
	else
	{
		dfs(new_node,prime_node,len+1);
	}

	// dfs(new_node,len);
}

int gcd(int a,int b)
{

	if(b>a)
	{
		int temp=a;
		a=b;
		b=temp;
	}

	if(!(a%b))
	{
		return b;
	}

	// DEBUG(a);
	// DEBUG(b);

	return gcd(b,(a%b));
}

int lcm(int a,int b)
{
	return ((a*b)/gcd(a,b));
}

int main()
{
	std::ios::sync_with_stdio(false);

	int n; cin>>n;

	REP(i,n)
	{
		int temp; cin>>temp;
		crush[i+1] = temp;
	}

	int lcm_do=1;

	FOR(i,1,n)
	{
		if(!visited[i])
		{
			int len = dfs(i,i,0);
			
			if((len&1)==0)
			{
				// DEBUG(len);
				// DEBUG(i);
				len/=2;
			}

			if(len==-1)
			{
				cout<<"-1"<<endl;
				return 0;
			}

			// cout<<"bro"<<endl;
			lcm_do = lcm(lcm_do,len);
			// DEBUG(lcm_do);
		}
		// DEBUG(i);

	}

	cout<<lcm_do<<endl;
}