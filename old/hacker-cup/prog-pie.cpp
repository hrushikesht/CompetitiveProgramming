#include <bits/stdc++.h>
#include <unordered_map>
#include <math.h>

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

	int t; cin>>t;
	int cas = t;

	while(t--)
	{
		double p,x,y; cin>>p>>x>>y;

		double rad = (p*(double)M_PI)/(50.0) ;
		double sn = sin(rad);
		double cs = cos(rad);

		if(abs(sn) < 1e-8)
		{
			sn=0;
		}
		if(abs(cs)< 1e-8)
		{
			cs=0;
		}

		double m=50*(1+sn);
		double n=50*(1+cs);

		double dist = (x-50)*(x-50) + (y-50)*(y-50);

		if(p==0 or dist>2500)
		{
			cout<<"Case #"<<cas-t<<" white"<<endl;
			continue;
		}

		// DEBUG(cs);
		// DEBUG(sn);
		// DEBUG(m);
		// DEBUG(n);

		if(p<=50)
		{
			double a=(50-n)*x - (50-m)*y + 50*(n-m);
			double b=x-50;

			if(a >= 0 and b>=0)
			{
				cout<<"Case #"<<cas-t<<" black"<<endl;
			}
			else
			{
				cout<<"Case #"<<cas-t<<" white"<<endl;
			}
			
		}
		else
		{
			double a=(50-n)*x - (50-m)*y + 50*(n-m);
			double b=x-50;

			if(a <= 0 and b<=0)
			{
				cout<<"Case #"<<cas-t<<" white"<<endl;
			}
			else
			{
				cout<<"Case #"<<cas-t<<" black"<<endl;
			}
		}
	}
}