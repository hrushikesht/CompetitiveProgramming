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
#define F first
#define S second
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void setBit(int & n, int b) { n |= two(b); }
inline void unsetBit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
inline bool sortDown(int x,int y){return x>y;}
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
// inline bool sortDown(int x,int y){return x>y;}
////////////////////////////////////////////////

int gcd(int x,int y)
{
	if(y>x)
	{
		int temp;
		temp=y;
		y=x;
		x=temp;
	}

	if(x%y==0)
	{
		return y;
	}
	else
	{
		return gcd(y,x%y);
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	vector<int>::iterator it;
	int t;cin>>t;

	while(t--)
	{
		int n;cin>>n;

		vector<int> arr;

		REP(i,n)
		{
			int temp;cin>>temp;
			arr.pb(temp);
		}

		int len[n]={0};

		REP(i,n)
		{
			len[i]=1;;
		}
		// cout<<endl;

		REP(i,n)
		{
			FOR(j,0,i-1)
			{
				// DEBUG(i);
				// DEBUG(len[i]);
				if(i==j)
					continue;
				if(gcd(arr.at(i),arr.at(j))>1)
					if(len[j]+1 > len[i])
						len[i]=len[j]+1;
			}
		}

		int maxito=len[0];

		REP(i,n)
		{
			// cout<<len[i]<<" ";
			if(maxito<len[i])
			{
				maxito=len[i];
			}
		}
		// cout<<endl;
		cout<<maxito<<endl;
	}
}