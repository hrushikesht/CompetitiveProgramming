#include <bits/stdc++.h>
#define pb push_back
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

int maxito(int x,int y)
{
	if(x>y)
		return x;
	return y;
}

int maximo(int *len,int x,int y)
{
	int max=len[x];

	FOR(i,x+1,y)
	{
		if(len[i]>max)
		{
			max=len[i];
		}
	}
	return max;
}

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int n;cin>>n;
		int m;cin>>m;

		int a[n];

		REP(i,n)
		{
			cin>>a[i];
		}

		int res[n][n];
		int greatest[n][n];

		REP(i,m)
		{
			// cout<<"bro"<<endl;
			int len[n];
			int l,r,ans=0;
			cin>>l>>r;

			// DEBUG(l);
			// DEBUG(r);

			for(int j=l-1;j<=r-1;j++)
			{
				len[j]=1;
				for(int k=l-1;k<j;k++)
				{
					if(a[j]>a[k])
					{
						len[j]=maxito(len[j],len[k]+1);
					}
					// DEBUG(j);
					// DEBUG(len[j]);
				}
			}
			// cout<<"hello"<<endl;
			/*
			REP(i,n)
			{
				DEBUG(i);
				DEBUG(len[i]);
			}
			*/
			
			cout<<maximo(len,l-1,r-1)<<endl;
		}

	}
}