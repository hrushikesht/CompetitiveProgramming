#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second 
#define i64 long long int
#define MOD 1000000007

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


int main()
{
	std::ios::sync_with_stdio(false);

	int t;cin>>t;

	while(t--)
	{
		int n;cin>>n;
		int m;cin>>m;
		int s;cin>>s;

		i64 length[m+1][n];

		i64 pass[m];
		REP(i,m)cin>>pass[i];


		REP(i,m+1)REP(j,n)length[i][j]=0;

		length[0][s-1]=1;

		FOR(i,0,m-1)
		{
			REP(j,n)
			{
				if(length[i][j]!=0)
				{
					if(j-pass[i]>=0)
					{
						length[i+1][j-pass[i]]=(length[i+1][j-pass[i]]+length[i][j])%MOD;
					}
					if(j+pass[i]<=n-1)
					{
						length[i+1][j+pass[i]]=(length[i+1][j+pass[i]]+length[i][j])%MOD;
					}
				}
			}
		}

		REP(i,n)
		{
			cout<<(length[m][i])%MOD<<" ";
		}
		cout<<endl;
	}
}