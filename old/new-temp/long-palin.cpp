#include <bits/stdc++.h>
#include <unordered_map>

#define pb push_back
#define F first
#define S second
#define i64 long long int

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
using namespace std;
/////////////////////////////////////////////////////////////////////

int main()
{
	std::ios::sync_with_stdio(false);

	int t; cin>>t;

	string aa ("aa");
	string ab ("ab");
	string ba ("ba");
	string bb ("bb");

	while(t--)
	{
		int n; cin>>n;

		unordered_map< string,int > M;

		REP(i,n)
		{
			string s;
			cin>>s;
			M[s]++;
		}

		string ans ("");

		if(M[aa]>=2)
		{
			REP(i,M[aa]/2)
			{
				ans+=aa;
			}
		}

		if(M[ab]<=M[ba])
		{
			REP(i,M[ab])
			{
				ans+=ab;
			}
		}

		else
		{
			if(M[ab]>M[ba])
			{
				REP(i,M[ba])
				{
					ans+=ab;
				}
			}
		}

		if(M[bb]>=2)
		{
			REP(i,M[bb]/2)
			{
				ans+=bb;
			}
		}

		if((M[aa]&1) == 1)
		{
			ans+=aa;
		}
		else if((M[bb]&1) == 1)
		{
			ans+=bb;
		}

		if(M[bb]>=2)
		{
			REP(i,M[bb]/2)
			{
				ans+=bb;
			}
		}

		if(M[ab]<=M[ba])
		{
			REP(i,M[ab])
			{
				ans+=ba;
			}
		}

		else
		{		
			if(M[ab]>M[ba])
			{
				REP(i,M[ba])
				{
					ans+=ba;
				}
			}
		}
	
		if(M[aa]>=2)
		{
			REP(i,M[aa]/2)
			{
				ans+=aa;
			}
		}

		for(int i=0;i<ans.size();i++)
		{
			cout<<ans[i];
		}
		cout<<endl;
	}
}