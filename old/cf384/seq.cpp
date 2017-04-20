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

int main()
{
	int n;cin>>n;
	i64 k;cin>>k;

	vector<int> seq;
	vector<int>::iterator it;
	seq.pb(1);
	// cout<<seq.at(0)<<endl;

	if((k&1)==1)
	{
		cout<<1<<endl;
		return 0;
	}

	i64 index=0,len=0;

	FOR(i,2,n)
	{
		if(seq.size()>k)break;

		int size=seq.size();
		seq.pb(i);
		
		// DEBUG(i);

		len=2*len+1;

		int j=0;

		for(j=0;j<len;j++)
		{
			seq.pb(seq.at(j));
		}
	}

	/*
	for(auto it=seq.begin();it<seq.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
	*/

	cout<<seq.at(k-1)<<endl;

}