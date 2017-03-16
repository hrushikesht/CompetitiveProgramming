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

int auction[200010][2];
vector<int> G[200010];

int main()
{
	std::ios::sync_with_stdio(false);

	int n; cin>>n;

	REP(i,n)
	{
		cin>>auction[i][0]>>auction[i][1];
		G[auction[i][0]].pb(i);
	}

	int q; cin>>q;

	REP(i,q)
	{
		int k; cin>>k;
		DEBUG(k);
		bool excluded[n+1]={false};

		REP(i,k)
		{
			int temp; cin>>temp;
			// DEBUG(temp);
			excluded[temp]=true;
		}

		int winner=0;
		int win_amount=0;

		FORD(i,n-1,0)
		{
			if(excluded[auction[i][0]])
			{
				continue;
			}

			DEBUG(i);

			winner=auction[i][0];
		}

		if(!winner)
		{
			cout<<winner<<" "<<0<<endl;
		}

		int flag=1;

		DEBUG(winner);

		for(auto it=G[winner].end()-1;it>=G[winner].begin(),flag==1;it--)
		{
			for(int i=*(it-1);i<=(*it);++i)
			{
				DEBUG(i);
				if(!excluded[auction[i][0]])
				{
					cout<<winner<<" "<<auction[i][1]<<endl;
					flag=0;
					break;
				}
			}
		}
	}	

}