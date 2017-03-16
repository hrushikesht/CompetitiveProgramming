#include <bits/stdc++.h>
#include <unordered_map>
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
	int n,x,temp;
	cin>>n>>x;

	 // count[n]=0;
	unordered_map<int,int> count;
	vector<int> arr;
	ll int ans=0;

	REP(i,n)
	{
		cin>>temp;
		arr.pb(temp);
		count[temp]++;
	}

	REP(i,n)
	{
		int a=x^arr.at(i);

		if(a==arr.at(i))
		{
			ans+=count[arr.at(i)]-1;
		}
		else
		{
			ans+=count[a];
		}
	}

	cout<<ans/2<<endl;


}