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

	unordered_map<int,int> M;
	vector<int> arr;

	REP(i,n)
	{
		cin>>temp;
		arr.pb(temp);
		M[temp]++;
	}

	unordered_map<int,int>::iterator it;

	cout<<"here commes map: "<<endl;
	for(it=M.begin();it!=M.end();it++)
	{
		cout<<(*it).first<<" -> "<<(*it).second<<endl;
	}

	int ans=0;

	REP(i,n)
	{
		int a=x^arr.at(i);
		DEBUG(a);
		DEBUG(arr.at(i));
		if(a==arr.at(i))
		{
			ans+=M[arr[i]]-1;
			DEBUG(M[arr[i]]);
			DEBUG(ans);
		}
		else
		{
			ans+=M[a];
			DEBUG(M[a]);
			DEBUG(ans);
		}
	}

	cout<<ans/2<<endl;


}