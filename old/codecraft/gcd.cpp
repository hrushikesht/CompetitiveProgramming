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

int gcd(int x,int y)
{
	if(x<y)
	{
		int temp=x;
		x=y;
		y=temp;
	}

	if(x%y == 0) return y;

	return gcd(y,x%y);
}

int arr[100010];


int main()
{
	std::ios::sync_with_stdio(false);

	int n; cin>>n;

	FOR(i,1,n) cin>>arr[i];

	int count[n+5];

	count[1]=1;

	// cout<<gcd(6,4)<<endl;

	FOR(i,2,n)
	{
		int cnt=1;
		FOR(j,1,i-1)
		{
			// DEBUG(i);
			// DEBUG(j);
			// DEBUG(arr[i]);
			// DEBUG(arr[j]);
				if(gcd(arr[j],arr[i])!=1)
				{
					// DEBUG(arr[j]);
					// DEBUG(arr[i]);
					// DEBUG(count[j]);
					// DEBUG(cnt);
					// arr[j]=-1;
					cnt++;
					// DEBUG(cnt);

				}
		}
		count[i]=cnt;
	}



	int maxito=count[n];

	FOR(i,1,n) cout<<count[i]<<endl;

	FORD(i,n,1)
	{
		// DEBUG(count[i]);
		if(maxito<count[i])
		{
			maxito=count[i];
		}
	}

	cout<<maxito<<endl;

}