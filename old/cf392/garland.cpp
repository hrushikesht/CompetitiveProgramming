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
	string s; cin>>s;

	map<char,int> M;
	map<char,int> map;

	int r=0,b=0,y=0,g=0;

	char a[5]={'R','B','Y','G','!'};
	
	FOR(i,0,3)
	{
		map[a[i]]=i;
	}

	// set<char> s[4];

	int sizo=s.size();
	int div=sizo/4;

	vector<char> yo[4];

	// DEBUG(div);

	REP(i,4*div)
	{
		// DEBUG(i);
		// DEBUG(s[i]);
		if(s[i]!='!') yo[i%4].pb(s[i]);
		M[s[i]]++;
		// set[i%4].insert(s[i]);
	}

	int count[4]={0};

	FOR(i,0,3)
	{
		count[i]=div-M[a[i]];
		// DEBUG(count[i]);
	}

	// DEBUG(4*div);
	// DEBUG(s.size());
	FOR(i,4*div,s.size()-1)
	{
		if(s[i]=='!')
		{
			// DEBUG(i);
			// DEBUG(s[i]);
			// cout<<count[map[yo[i%4].at(0)]];
			count[map[yo[i%4].at(0)]]=count[map[yo[i%4].at(0)]]+1;
		}
	}

	// cout<<"hi";
	cout<<count[0]<<" "<<count[1]<<" "<<count[2]<<" "<<count[3]<<endl;
}