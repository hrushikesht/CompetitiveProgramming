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

string s[1010];

int main()
{
	std::ios::sync_with_stdio(false);

	int t; cin>>t;

	while(t--)
	{
		int n,m; cin>>n>>m;

		FOR(i,1,m+2)
		{
			s[1] += 'A';
			s[n+2] += 'B';
		}

		// DEBUG(n);	

		FOR(i,2,n+1)
		{
			// string x;
			cin>>s[i];
			s[i] = 'A' + s[i] + 'A';
			// s[i] = x;
		}

		char a='A',w='W',b='B';

		bool flag=true;

		FOR(i,2,n+1)
		{
			if(!flag) break;

			FOR(j,1,m)
			{
				// DEBUG(s[i][j]);

				char left=s[i][j-1];
				char right=s[i][j+1];
				char up=s[i-1][j];
				char down=s[i+1][j];

				if(i==n+1 and s[i][j]=='W')
				{
					cout<<"no"<<endl;
					flag=false;
					break;
				}

				if(s[i][j]==a)
				{
					if(left==w || right==w || up==w || up==b)
					{
						DEBUG(i);
						DEBUG(j);
						DEBUG(s[i][j]);
						cout<<"no"<<endl;
						flag=false;
						break;
					}
				}
				else if(s[i][j]==w)
				{
					if(left==a || right==a || down==a || up==b )
					{
						DEBUG(i);
						DEBUG(j);
						DEBUG(s[i][j]);
						cout<<"no"<<endl;
						flag=false;
						break;
					}
				}
				else
				{
					if(down==a || down==w)
					{
						DEBUG(i);
						DEBUG(j);
						DEBUG(s[i][j]);
						cout<<"no"<<endl;
						flag=false;
						break;
					}
				}
			}
		}

		if(flag)
		{
			cout<<"yes"<<endl;
		}

	}
}