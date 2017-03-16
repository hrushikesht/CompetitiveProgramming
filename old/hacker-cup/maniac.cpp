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
#define INF INT_MAX
/////////////////////////////////////////////////////////////////////

i64 dist[110][110];
i64 d[5010];
i64 s[5010];
map< pair<i64, pair<i64,bool> >,i64 > M;

i64 findCost(i64 load,i64 index,i64 k,bool flag)
{

	if(M.find(mp(load,mp(index,flag)))!=M.end()) return M[mp(load,mp(index,flag))]; 

	if(index==k+1 and load==0) return 0;



	if(index==k and load==1)
	{
		// DEBUG(load);
		// DEBUG(index);
		// DEBUG(dist[s[index]][d[index]]);
		if(!flag)
		{
			i64 temp=dist[s[index]][d[index]];
			M[mp(load,mp(index,flag))]=temp;
			return temp;
		}
		else
		{
			i64 temp=dist[d[index-1]][d[index]];
			M[mp(load,mp(index,flag))]=temp;
			return temp;
		}
	}

	if(load==0)
	{
		flag=false;
		i64 temp=dist[d[index-1]][s[index]] + findCost(1,index,k,flag);
		// DEBUG(load);
		// DEBUG(index);
		// DEBUG(temp);
		M[mp(load,mp(index,flag))]=temp;
		return temp;
	}
	else if(load==1)
	{
		i64 l1,l2;
		if(!flag)
		{
			l1= dist[s[index]][d[index]]+findCost(0,index+1,k,flag);
			l2= dist[s[index]][s[index+1]] + findCost(2,index+1,k,flag);
		}
		else
		{
			l1= dist[d[index-1]][d[index]] + findCost(0,index+1,k,flag);
			l2= dist[d[index-1]][s[index+1]] + findCost(2,index+1,k,flag);
		}

		// DEBUG(l1);
		// DEBUG(l2);
		i64 minito=min(l1,l2);
		// DEBUG(load);
		// DEBUG(index);
		// DEBUG(minito)
		M[mp(load,mp(index,flag))]=minito;

		return min(l1,l2);
	}
	else
	{
		flag=true;
		i64 temp= dist[s[index]][d[index-1]] + findCost(1,index,k,flag);
		// DEBUG(load);
		// DEBUG(index);
		// DEBUG(temp);
		M[mp(load,mp(index,flag))]=temp;
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

		/*
		FOR(i,1,n)
		{
			FOR(j,1,n)
			{
				if(dist[i][j]==INF)
				{
					cout<<0<<"  ";
					continue;
				}
				cout<<dist[i][j]<<"  ";
			}
			cout<<endl;
		}
		*/
		

		FOR(i,1,k)
		{
			cin>>s[i]>>d[i];
		}

		bool flag2=false;
		
		FOR(i,1,k)
		{
			if(dist[s[i]][d[i]]==INF)
			{
				flag2=true;
				cout<<"Case #"<<test-t<<": "<<-1<<endl;
				break;
			}
		}

		if(!flag2)
			FOR(i,1,k-1)
			{
				if(dist[s[i]][d[i+1]]==INF and dist[s[i]][s[i+1]]==INF 
					and dist[d[i]][s[i+1]]==INF and dist[d[i]][d[i+1]]==INF )
				{
					flag2=true;
					cout<<"Case #"<<test-t<<": "<<-1<<endl;
					break;
				}
			}


		if(!flag2)
		{	
			i64 load=1;
			i64 cost=dist[1][s[1]];

			i64 index=1;
			cost+=findCost(load,index,k,false);

			cout<<"Case #"<<test-t<<": "<<cost<<endl;
		}
		M.clear();
	}
	return 0;
}