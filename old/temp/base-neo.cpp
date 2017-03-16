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



bool checkBin(ll int x,ll int N)
{
	int temp=N;

	// gives correct
	
	/*
	if(x>(N/2))
	{
		// DEBUG(x);
		return 1;
	}
	*/
	
	
	
	while(temp>=x)
	{
		temp/=x;
	}

	if(temp==1)
	{
		// DEBUG(x);
		return 1;
	}
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		ll int n;
		cin>>n;

		if(n==0)
		{
			cout<<0<<endl;
			continue;
		}

		if(n==1)
		{
			cout<<"INFINITY"<<endl;
			continue;
		}

		if(n==2)
		{
			cout<<1<<endl;
			continue;
		}

		if(n==3)
		{
			cout<<2<<endl;
			continue;
		}

		ll int count=1;
		for(ll int i=3;i<=n/2;i++)
		{
			count+=(ll int)checkBin(i,n);
		}
		// gives incorrect
		count+=n-(n/2);
		// count++;
		// cout<<count<<endl;
		cout<<count<<endl;
	}
}