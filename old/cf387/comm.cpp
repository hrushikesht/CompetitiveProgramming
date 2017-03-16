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

string s;
unordered_map<string,int> M;
vector<int> G[1000010];
vector<int> node;
vector<int> child;

int main()
{
	std::ios::sync_with_stdio(false);

	cin>>s;

	int index=1;
	int flag=1;

	DEBUG(s.size());

	for(int i=0;i<s.size();i++)
	{
		if(i==(s.size()-2))
			break;

		string x ("");
		while(s[i]!=',' && flag==1)
		{
			x+=s[i];
			i++;
		}
		if(s[i]==',' && flag==1)
		{
			// cout<<x<<endl;
			M[x]=index;
			index++;
			flag==0;
			// DEBUG(x);
			node.pb(M[x]);
			node.at(node.size()-1);
		}

		// DEBUG(i);

		string n ("");
		while(s[i]!=',' && flag==0 && i<=s.size())
		{
			n+=s[i];
			DEBUG(n);
			DEBUG(i);
			i++;
		}

		DEBUG(i);

		if((s[i]==','|| s[i]=='\n') && flag==0 )
		{
			// cout<<k<<endl;
			// cout<<n<<endl;
			int k = stoi(n);
			child.pb(k);
			cout<<k<<endl;
		}

	}

	child.pb(0);

	DEBUG(node.at(0));

	auto it2=child.begin();

	for(auto it=node.begin();it<node.end();++it)
	{
		cout<<*it<<" ";
	}


}