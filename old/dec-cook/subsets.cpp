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

	int t; cin>>t;

	while(t--)
	{

		// DEBUG(t);

		int a; cin>>a;
		int b; cin>>b;
		int c; cin>>c;
		int d; cin>>d;

		int total = a+b+c+d;
		int n=total;

		if(total==0)
		{
			cout<<"Yes"<<endl;
			continue;;
		}

		if(a==0 || b==0 || c==0 || d==0)
		{
			cout<<"Yes"<<endl;
			continue;
		}

		if((a+b)==0 || (b+c)==0 || (c+d)==0 || (a+c)==0 || (a+d)==0 || (b+d)==0 )
		{
			cout<<"Yes"<<endl;
			continue;
		}

		if((n-a)==0 || (n-b)==0 || (n-c)==0 || (n-d)==0)
		{
			cout<<"Yes"<<endl;
			continue;
		}

		cout<<"No"<<endl;


	}
}