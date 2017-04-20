#include <bits/stdc++.h>
#include <unordered_map>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define i64 long long int

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(i64 i=0;i<(n);i++)
#define FOR(i,a,b) for(i64 i=(a);i<=(b);i++)
#define FORD(i,a,b) for(i64 i=(a);i>=(b);i--)
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


map<int,int> M;

int main()
{
	std::ios::sync_with_stdio(false);

	i64 n,k; cin>>n>>k;

	if(k==1)
	{
		cout<<1<<endl;
		return 0;
	}

	if(n&1==0 and k==2)
	{
		cout<<1<<endl;
		return 0;
	}

	M[1]=1;
	int index=1;

	int count=1;

	for(int i=2;i<=floor(sqrt(n));i++)
	{
		if(n%i==0)
		{	
			index++;
			M[index]=i;
			count+=1;

			// DEBUG(i);
			// DEBUG(count);

			if(count==k)
			{
				cout<<i<<endl;
				return 0;
			}
		}
	}

	int sq=(int)sqrt(n);

	// DEBUG(sq);

	if((i64)sq*(i64)sq == n)
	{
		// DEBUG(sq);
		int total=2*(count-1)+1;

		if(k<=total)
		{
			cout<<n/M[(total-k+1)]<<endl;
			return 0;
		}
	}
	else
	{
		int total=2*count;

		if(k<=total)
		{
			// DEBUG(total-k+1);
			cout<<n/M[(total-k+1)]<<endl;
			return 0;
		}
	}

	cout<<-1<<endl;
	return 0;
}