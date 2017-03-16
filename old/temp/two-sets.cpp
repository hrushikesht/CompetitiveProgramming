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
	int n,a,b;
	cin>>n>>a>>b;

	// bool num[1000000000]={false};
	vector<bool> num_bool(1000000000,false);
	vector<int> num;
	// bool visited[n+1]=false;
	// vector<bool> ans_bool(n+1,false)

	REP(i,n)
	{
		int temp;
		cin>>temp;
		num_bool.at(temp)=true;
		num.pb(temp);
	}

	int maxito=a;
	int minito=b;
	int set_flag=0;
	int ans[n+1]=-1;
	if(b>a)
	{
		maxito=b;
		minito=a;
		set_flag=1;
	}

	if(num_bool.at(maxito)==true)
	{
		cout<<"NO";
		return 0;
	}

	sort(num.begin(),num.end(),sortDown);

	vector<int>::iterator it=num.begin();

	while(*it>=minito && it<num.end())
	{
		if(num_bool.at(maxito-*it)==true)
		{
			ans[*it]=ans[maxito-*it]=set_flag;
			it++;
			continue;
		}
		else
		{
			cout<<"NO";
			return 0;
		}
	}

	if(it==num.end())
	{
		REP(i,n)
		{
			cout<<ans[i+1]<<" ";
		}
		return 0;
	}

	vector<int>::iterator I=it;
	bool change_flag=1;

	while(change_flag)
	{
		change_flag=0;
		if(it==num.end())
		{
			it=I;
		}

		if(num_bool.at(maxito-*it)==true)
		{
			if(num_bool.at(minito-*it)==true)
			{
				it++;
				change_flag=1;
				continue;
			}
			else
			{

			}

		}
	}



	return 0;
}