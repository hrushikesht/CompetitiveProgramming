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
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
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
/////////////////////////////////////////////////////////////////////

int main()
{
	int n,x,temp,count=0;
	cin>>n>>x;

	vector<int> arr,arr_created;
	vector<bool> bits;

	int x_sup=x;
	while(x_sup!=0)
	{
		int c=x_sup&1;
		x_sup=x_sup>>1;
		bits.pb(c);
	}

	REP(i,n)
	{
		// int temp
		cin>>temp;
		arr.pb(temp);
	}

	REP(i,n)
	{
		vector<bool>::iterator it;
		int index=0;
		for(it=bits.begin();it<bits.end();it++,index++)
		{
			if(*it==1)
			{
				arr.at(i)^=1<<index;
			}
		}

		FOR(j,i+1,n)
		{
			if(arr.at(i)==arr.at(j))
			{
				// DEBUG(i);
				// DEBUG(j);
				count++;
			}
		}
	}

	cout<<count<<endl;


}