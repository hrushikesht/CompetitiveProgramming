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

int voting[200010]={1};

int main()
{
	std::ios::sync_with_stdio(false);

	int n; cin>>n;
	string s; cin>>s;

	unordered_map<int,int> M;

	int party[n];

	REP(i,n)
	{
		voting[i]=1;
		if(s[i]=='R')
		{
			party[i]=1;
			M[1]++;
		}
		else
		{
			party[i]=0;
			M[0]++;
		}
	}

	int i=0;


	while(1)
	{
		// DEBUG(i);

		int index=i+1;

		if(!voting[i]) 
		{
			i=(i+1)%n;
			continue;
		}
		while(1)
		{
			// DEBUG(index);
			// DEBUG(party[i]);
			// DEBUG(party[index]);
			// DEBUG(voting[index]);
			// DEBUG(M[1]);
			// DEBUG(M[0]);
			if((party[i]!=party[index]))
			{
				if(voting[index])
				{
					// cout<<"yo"<<endl;
					voting[index]=0;
					M[party[index]]--;

					if(M[0]==0)
					{
						cout<<"R"<<endl;
						return 0;
					}
					else if(M[1]==0)
					{
						cout<<"D"<<endl;
						return 0;
					}

					break;
				}
			}
			index=(index+1)%n;
		}

		i=(i+1)%n;
	}
}