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

int x[2010];
int y[2010];
vector<int> dist;
vector< pair<int,int> > ribbon;

int main()
{
	std::ios::sync_with_stdio(false);

	int t; cin>>t;

	while(t--)
	{
		int n,m; cin>>n;

		i64 price=0;

		FOR(i,1,n)
		{
			// DEBUG(i);
			cin>>x[i]>>y[i];
		}

		FOR(i,1,n-1)
		{
			dist.pb(sqrt((x[i]-x[i+1])*(x[i]-x[i+1]) + (y[i]-y[i+1])*(y[i]-y[i+1])));
		}
		dist.pb(sqrt((x[1]-x[n])*(x[1]-x[n]) + (y[1]-y[n])*(y[1]-y[n])));

		cin>>m;

		FOR(i,1,m)
		{
			int r,p; cin>>r>>p;
			// DEBUG(r);
			// DEBUG(p);
			ribbon.pb(mp(r,p));
		}
		sort(ribbon.begin(),ribbon.end());
		sort(dist.begin(),dist.end(),sortDown);

		

		int index=ribbon.size()-1;
		int curr_index=index;

		for(auto it=dist.begin();it!=dist.end();++it)
		{
			DEBUG(*it);
			index=ribbon.size()-1;
			int curr_price=ribbon.at(index).second;
			index-=1;
			
			// DEBUG(curr_price);

			// DEBUG(ribbon.at(index).F);

			// DEBUG(*it);
			// DEBUG(ribbon.at(index).first);
			while(index>=0 and ribbon.at(index).first>=*it)
			{
				// DEBUG(curr_price);
				// DEBUG(ribbon.at(index).second)
				if(curr_price>ribbon.at(index).second)
				{
					curr_price=ribbon.at(index).second;
					// DEBUG(curr_price);
				}
				index--;
			}
			// DEBUG(curr_price);
			price+=curr_price;
		}

		cout<<price<<endl;
	}
}