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

vector<int> prime;

void sieve(int x)
{
	bool flag=1;
	vector<int> test;

	for(int i=0;i<=x;i++)
	{
		test.push_back(i);
	}

	
	for(int i=2;i<=x;i++)
	{
		if(test[i]==-1)
		{
			continue;
		}

		prime.push_back(i);

		for(int j=i;j<=x+2;j+=i)
		{
			test[j]=-1;
		}
	}
	
}

void print_vec(vector<int> vec)
{
	vector<int>::iterator it;
	for(it=vec.begin();it<vec.end();++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}

// void print_arr()

void fillPointerFlags(int var,bool *flag)
{
	vector<int>::iterator it=prime.begin();
	int index=0;

	while(1)
	{
		if(index>=78498 || var==1)
		{
			break;
		}

		if(var%*it==0)
		{
			var/=*it;
			*(flag+index)=0;
			continue;
		}
		it++;
		index++;
	}
}

int main()
{
	int t;
	scanf("%d",&t);

	sieve(1000000);
	// print_vec(prime);
	// cout<<"prime size = "<<prime.size();

	
	while(t--)
	{
		int n;
		scanf("%d",&n);

		vector<int> arr;
		REP(i,n)
		{
			int temp;
			scanf("%d",&temp);
			arr.pb(temp);
		}

		vector<int>::iterator it;

		bool **pointer_flags;
		pointer_flags=(bool **)malloc(sizeof(bool *)*n);

		REP(i,n)
		{
			*(pointer_flags+i)=(bool *)malloc(sizeof(bool)*78498);
		}

		int i;

		for(it=arr.begin(),i=0;it<arr.end();++it,++i)
		{
			fillPointerFlags(*it,*(pointer_flags+i));
		}

		for(int i=0;i<n;i++)
		{
			cout<<"now starts for index ="<<i<<endl;
			for(int j=0;j<10;j++)
			{
				cout<<*(*(pointer_flags+i)+j)<<" ";
			}
			cout<<endl;
		}
	}

}