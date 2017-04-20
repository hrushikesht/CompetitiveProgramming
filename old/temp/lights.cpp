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
	int t;cin>>t;

	while(t--)
	{
		int n;cin>>n;
		int m;cin>>m;
		int k;cin>>k;

		vector<int> row_sum;

		string wall[n];

		REP(i,n)	
		{
			int temp=0;
			cin>>wall[i];
			
			REP(j,m)
			{
				if(wall[i][j]=='*')
				{
					temp++;
				}
			}
			row_sum.pb(temp);
		}

		REP(i,k)
		{
			sort(row_sum.begin(),row_sum.end());
			row_sum.at(0)=m- row_sum.at(0);
		}

		i64 sum=0;
		REP(i,n)
		{
			sum+=row_sum.at(i);
		}
		cout<<sum<<endl;
	}
}