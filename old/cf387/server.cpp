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


int main()
{
	std::ios::sync_with_stdio(false);

	int n; cin>>n;
	int q; cin>>q;

	int occu[n+1]={0};
	int task[q+1][3];

	FOR(i,1,q)
	{
		int t; cin>>t;
		int k; cin>>k;
		int d; cin>>d;
		
		int index=0;
		int cost=0;

		FOR(j,1,n)
		{
			if(index>=k)
			{
				break;
			}

			if(occu[j]<t)
			{
				index++;
			}
		}

		if(index>=k)
		{
			FOR(j,1,n)
			{
				if(k==0)
				{
					break;
				}
				if(occu[j]<t)
				{
					occu[j]=t+d-1;
					cost+=j;
					k--;
				}
			}
			cout<<cost<<endl;
		}
		else cout<<"-1"<<endl;
	}
}