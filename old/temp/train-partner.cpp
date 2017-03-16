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
#include <iterator>
// #include <bits/stdc++.h>
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
inline void setBit(int & n, int b) { n |= two(b); }
inline void unsetBit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
inline bool sortDown(int x,int y){return x>y;}
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
/////////////////////////////////////////////////////////////////////


int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int n;
		scanf("%d",&n);

		int code=(n-1)%8;

		switch(code)
		{
			case 0:
				cout<<n+3<<"LB"<<endl;
				break;
			case 1:
				cout<<n+3<<"MB"<<endl;
				break;
			case 2:
				cout<<n+3<<"UB"<<endl;
				break;
			case 3:
				cout<<n-3<<"LB"<<endl;
				break;
			case 4:
				cout<<n-3<<"MB"<<endl;
				break;
			case 5:
				cout<<n-3<<"UB"<<endl;
				break;
			case 6:
				cout<<n+1<<"SU"<<endl;
				break;
			case 7:
				cout<<n-1<<"SL"<<endl;
				break;
		}

	}
}