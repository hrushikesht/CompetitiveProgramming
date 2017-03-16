#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std; 
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
/////////////////////////////////////////////////////////////////////

vector<int> prime;

void sieve(int N)
{
	bool check[N]={false};

	FOR(i,2,N)
	{
		if(check[i]==true)
			continue;
		prime.pb(i);
		for(int j=i;j<=N;j+=i)
		{
			check[j]=true;
		}
	}
}

int main()
{

	std::ios::sync_with_stdio(false);

	sieve(1000);

	vector<int>::iterator it;

	for(it=prime.begin();it<prime.end();it++)
	{
		cout<<*it<<" "<<endl;
	}

	

}