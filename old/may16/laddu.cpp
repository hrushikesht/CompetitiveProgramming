#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second 
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


int main()
{
	std::ios::sync_with_stdio(false);

	int t;cin>>t;

	while(t--)
	{
		int act;cin>>act;
		string origin;cin>>origin;

		long long int laddu=0;

		string activity[act];

		REP(i,act)
		{
			cin>>activity[i];

			if(activity[i]=="CONTEST_WON")
			{
				int rank;
				cin>>rank;
				if(rank>20)
				{
					laddu+=300;
					continue;
				}
				laddu+=320-rank;
				continue;
			}

			if(activity[i]=="TOP_CONTRIBUTOR")
			{
				laddu+=300;
				continue;
			}

			if(activity[i]=="BUG_FOUND")
			{
				int severe;cin>>severe;
				laddu+=severe;
				continue;
			}

			if(activity[i]=="CONTEST_HOSTED")
			{
				laddu+=50;
				continue;
			}
		}
		if(origin=="INDIAN")
		{
			cout<<(int)laddu/200<<endl;
			continue;
		}
		else{
			cout<<(int)laddu/400<<endl;
		}

	}
}