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

	int x1; cin>>x1;
	int y1; cin>>y1;
	
	int x2; cin>>x2;
	int y2; cin>>y2;
	
	int x3; cin>>x3;
	int y3; cin>>y3;

	int a=x1+x2-x3;
	int b=y1+y2-y3;

	int c= x2+x3-x1;
	int d= y2+y3-y1;

	int e = x1+x3-x2;
	int f = y1+y3-y2;

	cout<<3<<endl;
	cout<<a<<" "<<b<<endl;
	cout<<c<<" "<<d<<endl;
	cout<<e<<" "<<f<<endl;

}