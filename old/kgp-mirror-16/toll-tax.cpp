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

int coal[100010],policy[100010],toll[100010],profit[10010];

int main()
{
	std::ios::sync_with_stdio(false);

	int t; cin>>t;

	while(t--)
	{
		int n; cin>>n;

		// DEBUG(n);

		REP(i,n)
		{
			cin>>coal[i];
		}

		REP(i,n-1)
		{
			cin>>toll[i];
		}

		REP(i,n-1)
		{
			cin>>policy[i];
		}

		profit[0] = coal[0];
		int maxito = profit[0];

		REP(i,n-1)
		{
			profit[i+1] = profit[i] + coal[i+1];

			// DEBUG(profit[i+1]);

			if(policy[i]==1)
			{
				profit[i+1] -= toll[i];
			}
			else profit[i+1] -= 2*toll[i];
		
			if(maxito<profit[i+1])
			{
				maxito = profit[i+1];
			}
		}

		/*
		cout<<"Profit is :";
		REP(i,n)
		{
			cout<<profit[i]<<" ";
		}
		cout<<endl;
		*/

		cout<<maxito<<endl;
	}
}