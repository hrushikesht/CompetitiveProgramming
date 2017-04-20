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


int main()
{
	std::ios::sync_with_stdio(false);

	int n; cin>>n;
	int k; cin>>k;

	vector<int> tang;
	int one_count=0;

	REP(i,n)
	{
		int temp;
		cin>>temp;
		tang.pb(temp);
		if(temp==1)
		{
			one_count++;
		}
	}

	sort(tang.begin(),tang.end(),sortDown);

	if(one_count + 2*(n-one_count) < k) 
	{
		cout<<"-1"<<endl;
		return 0;
	}

	if(one_count + 2*(n-one_count) == k)
	{
		if(one_count!=0)
		{
			cout<<"1"<<endl;
			return 0;
		}
		else 
		{
			cout<<(tang.at(tang.size()-1))/2<<endl;
			return 0;
		}
	}

	while(1)
	{
		if(tang.at(0)==1)
		{
			cout<<1<<endl;
			return 0;
		}

		int x,y;

		if((tang.at(0)&1))
		{
			x=(tang.at(0)/2) + 1;
			y=x-1;
		}
		else
		{	
			x=tang.at(0)/2;
			y=x;
		}

		if(tang.size() < k)
		{
			tang.pb(x);
			tang.pb(y);
			sort(tang.begin(),tang.end(),sortDown);
			continue;
		}

		if(x>tang.at(k-1))
		{
			tang.at(0) = 0;
			tang.pb(x);
			tang.pb(y);
			sort(tang.begin(),tang.end(),sortDown);
			continue;
		}
		else
		{
			cout<<tang.at(k-1)<<endl;
			return 0;
		}
	}
}