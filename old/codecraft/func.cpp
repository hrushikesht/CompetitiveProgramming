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
#define MOD 10000007
/////////////////////////////////////////////////////////////////////

// int dp[100][1000010];
// bool flag[100][1000010]={false};


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

int f(int r,int n)
{
	if(n==1) return 1;
	// DEBUG(r);
	// DEBUG(n);
	
	/*
	if(r<=90)
	{
		// DEBUG(r);
		if(flag) return dp[r][n];
	}
	*/
	

	// DEBUG(r);
	// DEBUG(n);

	if(r==0)
	{
		if(n==1) return 1;

		int ans=0;
		for(int i=1;i<sqrt(n);i++)
		{
			// DEBUG(n);
			// DEBUG(i);
			if(n%i == 0 and gcd(i,n/i)==1)
			{
				// DEBUG(ans);
				ans =(ans+2)%MOD;
			}
		}
		// dp[r][n]=ans;
		// flag[r][n]=true;
		return ans;
	}

	int ans=0;

	for(int i=1;i<=sqrt(n);i++)
	{
		if(n%i == 0)
		{
			if(i==n/i)
			{
				ans+=f(r-1,i);
				continue;
			}
			ans=(ans+f(r-1,i) + f(r-1,n/i))%MOD;
			// DEBUG(ans)
		}
	}
	// DEBUG(ans);
	// dp[r][n]=ans;
	// flag[r][n]=true;
	return ans;
}

int main()
{
	std::ios::sync_with_stdio(false);

	int n; cin>>n;

	FOR(i,1,n)
	{
		int r,n; cin>>r>>n;

		cout<<f(r,n)<<endl;
	}

}