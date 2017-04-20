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
	cout<<1<<endl;
	cout<<flush;

	cout<<3<<" "<<1<<" "<<1<<" "<<2<<endl;
	cout<<flush;

	cout<<3<<" "<<3<<" "<<3<<" "<<4<<endl;
	cout<<flush;

	int ans;cin>>ans;

	switch(ans)
	{
		case 2:
			cout<<2<<endl;
			cout<<flush;
			cout<<1<<endl;
			cout<<flush;
			break;
		case 1:
			cout<<2<<endl;
			cout<<flush;
			cout<<2<<endl;
			cout<<flush;
			break;
		case -1:
			cout<<2<<endl;
			cout<<flush;
			cout<<3<<endl;
			cout<<flush;
			break;	
		case -2:
			cout<<2<<endl;
			cout<<flush;
			cout<<1<<endl;
			cout<<flush;
			break;
		case 0:
			cout<<2<<endl;
			cout<<flush;
			cout<<1<<endl;
			cout<<flush;
			break;
	}
}