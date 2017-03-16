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

	string s; cin>>s;
	string t; cin>>t;

	unordered_map<char,char> M;
	vector<char> is_exist;

	REP(i,s.size())
	{
		if(s[i] == t[i])
		{
			// M[s[i]]=M[t[i]];
			is_exist.pb(s[i]);
			auto it1=M.find(s[i]);

			if(it1 != M.end())
			{
				cout<<"-1"<<endl;
				return 0;
			}


			// M[t[i]]=M[s[i]]; 	
		 continue;
		}

		if(s[i]!=t[i])
		{
			if (find(is_exist.begin(),is_exist.end(),s[i]) != is_exist.end())
			{
				cout<<"-1"<<endl;
				return 0;
			}
			if (find(is_exist.begin(),is_exist.end(),t[i]) != is_exist.end())
			{
				cout<<"-1"<<endl;
				return 0;
			}


			auto it1=M.find(s[i]);
			auto it2=M.find(t[i]);

			if(it1 == M.end() && it2 == M.end())
			{
				

				M[s[i]]=t[i];
				M[t[i]]=s[i];
			}
			else if(it1==M.end())
			{
				cout<<"-1"<<endl;
				return 0;
			}
			else if(it2==M.end())
			{
				cout<<"-1"<<endl;
				return 0;
			}
			else if(M[s[i]]!=t[i] or M[t[i]]!=s[i])
			{
				cout<<"-1"<<endl;
				return 0;
			}

		
		}
	}

	cout<<M.size()/2<<endl;

	// int gg=M.size();

	int index=0;

	

	// cout<<gg/2<<endl;

	vector<char> ans;

	for(auto it=M.begin();it!=M.end();++it,++index)
	{
		if(find(ans.begin(),ans.end(),(it->F)) == ans.end())
		{
			cout<<it->F<<" "<<it->S<<endl;
			ans.pb(it->F);
			ans.pb(it->S);
		}
	}
}