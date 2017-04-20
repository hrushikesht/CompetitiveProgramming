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
	std::ios::sync_with_stdio(false);

	int n;cin>>n;
	i64 w;cin>>w;
	i64 l;cin>>l;

	i64 tree[n][2],total=0;;

	REP(i,n)
	{
		i64 temp;
		cin>>temp;
		tree[i][0]=temp;
		if(temp>=l)
			total+=temp;
		cin>>tree[i][1];
	}

	if(total>=l)
	{
		cout<<0<<endl;
		return 0;
	}

	// i64 iterations=0;
	i64 temp;

	i64 start=0,mid;
	i64 end=2;

	while(total<w)
	{
		total=0;
		end*=2;

		for(int i=0;i<n;i++)
		{
			temp=tree[i][0]+(end*tree[i][1]);
			if(temp>=l)
				total+=temp;
		}

	}

	while(end-start > 1)
	{
		// cout<<start<<endl;
		// DEBUG(start);
		// DEBUG(end);	
		total=0;
		mid=(start+end)/2;
		for(int i=0;i<n;i++)
		{
			temp=tree[i][0]+(mid*tree[i][1]);
			if(temp>=l)
				total+=temp;
		}

		if(total<w)
		{
			start=mid;
		}
		else
		{
			end=mid;
		}

	}
	
	cout<<end<<endl;
}