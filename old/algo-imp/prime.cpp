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


vector<int> prime;
bool is_prime[100010]={false};
int arr[100010];

void sieve(int N)
{
	bool check[N]={false};

	FOR(i,2,N)
	{
		if(check[i]==true)
			continue;
		prime.pb(i);
		is_prime[i]=true;
		for(int j=i;j<=N;j+=i)
		{
			check[j]=true;
		}
	}
}



int main()
{

	std::ios::sync_with_stdio(false);
	sieve(100000);

	i64 n,q; cin>>n>>q;

	FOR(i,1,n)
	{
		cin>>arr[i];
	}

	FOR(i,1,q)
	{
		i64 a,x,y; cin>>a>>x>>y;
		i64 count=0;

		if(a==2)
		{
			arr[x]=y;
		}
		else
		{
			FOR(j,x,y)
			{
				if(is_prime[arr[i]])
				{
					count++;
				}
			}
			cout<<count<<endl;
		}
	}


}
