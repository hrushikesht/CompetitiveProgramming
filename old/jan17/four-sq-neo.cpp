#include <bits/stdc++.h>
#include <unordered_map>
#include <utility>

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

int arr[100010];

int main()
{
	std::ios::sync_with_stdio(false);

	int t; cin>>t;

	while(t--)
	{
		int n,q,P; cin>>n>>q>>P;

		FOR(i,1,n) cin>>arr[i];

		map<int, pair<int,int> > M;

		vector<int> sq;
		// set<int> s;


		FOR(i,0,P-1)
		{
			sq.pb((i*i)%P);
			// s.insert((i*i)%P);
		}

		/*
		for(auto it=s.begin();it!=s.end();++it)
		{
			cout<<*it<<endl;
		}
		*/

		FOR(i,0,P-1)
		{
			FOR(j,0,P-1)
			{
				int x=(sq.at(i) + sq.at(j))%P;
				if(M.count(x)!=0) continue;
				M[x]=mp(i,j);
			}
		}

		/*
		for(auto it=M.begin();it!=M.end();++it)
		{
			cout<<it->F<<" ";
			cout<<(it->S).first<<"  "<<(it->S).second<<endl;
		}
		*/

		FOR(i,1,q)
		{
			int f,x,y; cin>>f>>x>>y;

			if(f==1)
			{
				arr[x]=y;
			}
			else
			{
				long long int prod=1;
				FOR(i,x,y)
				{
					prod=((i64)prod*(i64)arr[i])%P;
				}

				int a,b,c,d;
				bool flag=true;

				for(auto it1=M.begin();it1!=M.end();++it1)
				{
					if(flag)
					for(auto it2=M.begin();it2!=M.end();++it2)
					{
						int diff= (prod - it1->F - it2->F)%P;
						if(M.count(diff)!=0)
						{
							flag=false;
							a=it1->F;
							b=it2->F;
							c=get<0>(M[diff]);
							// cout<<typeid(c).name()<<endl;
							d=get<1>(M[diff]);
							/*
							DEBUG(a);
							DEBUG(b);
							DEBUG(c);
							DEBUG(d);
							DEBUG(diff);
							DEBUG(prod);
							DEBUG(sq.at(j));
							DEBUG(sq.at(k));
							*/
							break;
						}
					}
					else break;
				}

				if(flag) cout<<-1<<endl;
				else cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
			}
		}
	}
}