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

vector<i64> pie[310];
i64 cost[310][310];

int main()
{
	std::ios::sync_with_stdio(false);

	i64 t; cin>>t;
	i64 test=t;

	while(t--)
	{
		i64 n,m; cin>>n>>m;

		FOR(i,1,n)
		{
			cost[i][0]=0;
			FOR(j,1,m)
			{
				i64 temp; cin>>temp;
				pie[i].pb(temp);
			}
		}

		FOR(i,1,n)
		{
			sort(pie[i].begin(),pie[i].end());
			cost[i][1]=pie[i].at(0)+1;
		}

		FOR(i,1,n)
		{
			FOR(j,2,m)
			{
				cost[i][j]=cost[i][j-1]+pie[i].at(j-1)+2*j-1;
			}
		}

		i64 fin_cost=cost[1][1];

		i64 pointers[310]={0};

		pointers[1]=1;

		FOR(i,2,n)
		{
			vector< pair<int,int> > dum;
			i64 index=1;
			i64 temp=fin_cost+cost[i][pointers[i]+1]-cost[1][pointers[i]];
			FOR(j,1,i)
			{
				// DEBUG(j);
				// DEBUG(pointers[j]);
				if(pointers[j]<m) 
				{
 					if(fin_cost+cost[j][pointers[j]+1]-cost[j][pointers[j]] <= temp)
 					{
 						temp=fin_cost+cost[j][pointers[j]+1]-cost[j][pointers[j]];
 						index=j;
 					}
 				}
 			}
 			pointers[index]++;
 			fin_cost=temp;

		}

		FOR(i,1,n)
		{
			pie[i].clear();
		}

		cout<<"Case #"<<test-t<<": "<<fin_cost<<endl;
	}

}