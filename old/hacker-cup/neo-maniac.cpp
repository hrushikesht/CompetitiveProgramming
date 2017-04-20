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
#define INF 999
/////////////////////////////////////////////////////////////////////

i64 dist[110][110];
i64 d[5010];
i64 s[5010];

i64 findCost(int load,int index,i64 n)
{
	DEBUG(load);

	if(index==n+1 and load==0) return 0;

	if(index==n and load==1)
	{
		// DEBUG(load);
		// DEBUG(index);
		// DEBUG(dist[s[index]][d[index]]);
		return 0;
	}

	if(load==0)
	{
		i64 temp=dist[d[index-1]][s[index]] + findCost(load+1,index,n);
		// DEBUG(load);
		// DEBUG(index);	
		return temp;
	}
	else if(load==1)
	{
		i64 l1= dist[s[index]][d[index]]+findCost(load-1,index+1,n);
		i64 l2= dist[s[index]][s[index+1]] + findCost(load+1,index+1,n);
		// DEBUG(l1);
		// DEBUG(l2);
		i64 minito=min(l1,l2);
		// DEBUG(load);
		// DEBUG(index);
		// DEBUG(minito)
		return min(l1,l2);
	}
	else
	{
		i64 temp= dist[s[index]][d[index-1]] + findCost(load-1,index,n);
		// DEBUG(load);
		// DEBUG(index);
		return temp;
 	}
}

int main()
{
	std::ios::sync_with_stdio(false);

	i64 t; cin>>t;
	i64 test=t;
	
	while(t--)
	{
		i64 n,m,k; cin>>n>>m>>k;

		REP(i,110)
		{
			REP(j,110)
			{
				if(i==j)
				{
					dist[i][i]=0;
				}
				else dist[i][j]=INF;
			}
		}

		REP(i,m)
		{
			i64 a,b,g; cin>>a>>b>>g;
			if(dist[a][b] > g)
			{
				dist[a][b]=g;
				dist[b][a]=g;
			}
		}

		//Floyd-Warshall Algo

		FOR(l,1,n)
		{
			FOR(i,1,n)
			{
				FOR(j,1,n)
				{
					// DEBUG(i);
					// DEBUG(j);
					// DEBUG(k);
					// DEBUG(dist[i][j]);
					// DEBUG(dist[i][k]);
					// DEBUG(dist[k][j]);

					if( dist[i][j]>dist[i][l] + dist[l][j])
					{
						// cout<<"yo";
						dist[i][j]=dist[i][l] + dist[l][j];
					}
				}
			}
		}

		
		FOR(i,1,n)
		{
			FOR(j,1,n)
			{
				if(dist[i][j]==999)
				{
					cout<<0<<"  ";
					continue;
				}
				cout<<dist[i][j]<<"  ";
			}
			cout<<endl;
		}
		

		FOR(i,1,k)
		{
			cin>>s[i]>>d[i];
		}

		i64 load=1;
		i64 cost=dist[1][s[1]];

		i64 index=1;

		DEBUG(cost);
		cost+=findCost(load,index,k);

		cout<<cost<<endl;

	}
}