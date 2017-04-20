#include <bits/stdc++.h>
#include <unordered_map>

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

unordered_map<int,int> M;

i64 find_ans(i64 x)
{
	if(x==0) return 0;

	if(M[x]!=0)
	{
		return M[x];
	}

	i64 temp = max(x,(find_ans(x/2)+find_ans(x/3)+find_ans(x/4)));
	M[x]=temp;

	return temp;
}

int main()
{
	std::ios::sync_with_stdio(false);

	i64 n;

	M[1]=1;
	M[0]=0;

	while(scanf("%lld", &n) != EOF)
	{
		i64 ans=find_ans(n);
		cout<<ans<<endl;
	}
}