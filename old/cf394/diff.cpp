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

int a[100010];
int b[100010];
int c[100010];

int main()
{
	std::ios::sync_with_stdio(false);

	int n,l,r; cin>>n>>l>>r;

	FOR(i,1,n)
	{
		cin>>a[i];
	}

	FOR(i,1,n)
	{
		int temp; cin>>temp;
		c[temp]=i;
	}	


	b[c[1]]=l;



	FOR(i,2,n)
	{
		int idx=c[i];

		// DEBUG(b[c[i-1]]+a[c[i]]-a[c[i-1]]);

		if(b[c[i-1]]+a[c[i]]-a[c[i-1]]+1 <= r)
		{
			if(b[c[i-1]]+a[c[i]]-a[c[i-1]]+1 > l)
			{
				b[c[i]]= b[c[i-1]]+a[c[i]]-a[c[i-1]]+1;
			}
			else
			{
				b[c[i]]=l;
			}
			// DEBUG(b[c[i]]);
		}
		else
		{
			cout<<-1<<endl;
			return 0;
		}

	}

	FOR(i,1,n)
	{
		cout<<b[i]<<" ";
	}
	cout<<endl;
	return 0;
}