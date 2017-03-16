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

int x=0,y=0;



int main()
{
	std::ios::sync_with_stdio(false);

	int n; cin>>n;
	string s; cin>>s;

	unordered_map<char,char> M;

	M['L']='R';
	M['R']='L';
	M['U']='D';
	M['D']='U';

	int count=0;

	vector<char> direc;

	REP(i,s.size())
	{
		// auto it=direc.find_if(s[i]);

		if(find(direc.begin(),direc.end(),s[i]) != direc.end())
		{
			continue;
		}
		else
		{
			if(find(direc.begin(),direc.end(),M[s[i]]) != direc.end())
			{
				direc.clear();
				count++;
				direc.pb(s[i]);
			}
			else	if(direc.size()<2)
				{
					direc.pb(s[i]);
				}
				else
				{
					direc.clear();
					count++;
					direc.pb(s[i]);
				}
		}
	}

	cout<<count+1<<endl;
}