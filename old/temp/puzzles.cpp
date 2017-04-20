#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#define pb push_back
using namespace std; 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = 1<<29;
typedef long long ll;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
inline bool dec_sort(int x,int y){return x>y;}
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
/////////////////////////////////////////////////////////////////////

int main()
{
	
	int n,m;
	scanf("%d %d",&n,&m);

	vector<int> sizes;

	REP(i,m)
	{
		// scanf("%d",&(size[i]));
		int temp;
		scanf("%d",&temp);
		sizes.pb(temp);
	}

	sort(sizes.begin(),sizes.end());
	int minito=sizes.at(m-1)-sizes.at(0);

	/*
	REP(i,m)
	{
		DEBUG(i);
		DEBUG(sizes.at(i));
	}
	*/
	

	REP(i,m-n)
	{
		int temp=sizes.at(i+n-1)-sizes.at(i);
		// DEBUG(i);
		// DEBUG(i+n-1);
		if(temp<minito)
		{
			// DEBUG(i);
			minito=temp;
		}
	}

	cout<<minito;

    return 0;
}