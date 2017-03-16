#include <bits/stdc++.h>
// #include <unordered_map>

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

int stones[110][110];

int main()
{
	std::ios::sync_with_stdio(false);

	int t; cin>>t;

	while(t--)
	{
		int h; cin>>h;
		int w; cin>>w;

		REP(i,h)
		{
			REP(j,w)
			{
				cin>>stones[i+1][j+1];
			}
		}

		int ans[110][110];

		REP(i,w)
		{
			ans[1][i+1]=stones[1][i+1];
		}

		FOR(i,2,h)
		{
			FOR(j,1,w)
			{
				if(j==1)
				{
					ans[i][j]=stones[i][j] + max(ans[i-1][1],ans[i-1][2]);
					continue;
				}
				if(j==w)
				{
					ans[i][j]=stones[i][j] + max(ans[i-1][w],ans[i-1][w-1]);
					continue;
				}

				ans[i][j]=stones[i][j] +  max(ans[i-1][j-1],max(ans[i-1][j],ans[i-1][j+1]));
			}
		}

		/*

		REP(i,h)
		{
			REP(j,w)
			{
				cout<<ans[i+1][j+1]<<" ";
			}
			cout<<endl;
		}
		*/

		int maxi=ans[h][1];

		FOR(i,2,w)
		{
			if(maxi<ans[h][i])
			{
				maxi=ans[h][i];
			}
		}

		cout<<maxi<<endl;
	}
}