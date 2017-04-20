#include <bits/stdc++.h>
#include <unordered_map>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define i64 long long int

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(i64 i=0;i<(n);i++)
#define FOR(i,a,b) for(i64 i=(a);i<=(b);i++)
#define FORD(i,a,b) for(i64 i=(a);i>=(b);i--)
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
	
	i64 n,m,k,x,y; cin>>n>>m>>k>>x>>y;

	i64 count[3]={0};
	i64 sergei_count=0;

	int flag_sergei=0;

	i64 block[3]={0};

	if(x==1)
	{
		flag_sergei=0;
	}
	else if(x==n)
	{
		flag_sergei=2;
	}
	else
	{
		flag_sergei=1;
	}


	int current=0;

	while(k>=0)
	{	
		if(current==0)
		{
			if(k-m>=0)
			{
				count[0]++;
				if(flag_sergei==0)
				{
					sergei_count++;
				}
			}
			else
			{
				if(flag_sergei==0)
				{
					if(y<=k)
					{
						sergei_count++;
					}
				}
			}
			k=k-m;
		}
		else if(current==2)
		{
			if(k-m>=0)
			{
				count[2]++;
				if(flag_sergei==2)
				{
					sergei_count++;
				}
			}
			else
			{
				if(flag_sergei==2)
				{
					if(y<=k)
					{
						sergei_count++;
					}
				}
				count[2]++;
			}
			k=k-m;
		}
		else
		{
			if(k-(n-2)*m>=0)
			{
				count[1]++;
				if(flag_sergei==1)
				{
					sergei_count++;
				}
			}
			else
			{
				if(flag_sergei==1)
				{
					int temp=k/m;
					int temp2=k-m*temp;

					if(x<=temp and y<=temp2)
					{
						sergei_count++;
					}
				}
			}
			k=k-(n-2)*m;
		}

		if(current==0)
		{
			current=1;
		}
		if(current==1)
		{
			current=2;
		}
		if(current==2)
		{
			current==1;
		}
	}

	i64 maxito=0,minito=1e18;

	FOR(i,0,2)
	{
		maxito=max(maxito,count[i]);
		minito=min(minito,count[i]);
	}

	cout<<maxito<<" "<<minito<<" "<<sergei_count<<endl;


}