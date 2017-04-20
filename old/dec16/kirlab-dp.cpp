#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
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
using namespace std;
/////////////////////////////////////////////////////////////////////

vector<int> prime;
int least_prime[10000000];

void sieve(int N)
{
	bool check[N]={false};

	FOR(i,2,N)
	{
		if(check[i]==true)
			continue;
		prime.pb(i);
		for(int j=i;j<=N;j+=i)
		{
			if(check[j]==true)
				continue;
			least_prime[j]=i;
			check[j]=true;
		}
	}
}

int* factorize(int x)
{
	DEBUG(x);
	int* fact=(int*)malloc(15*sizeof(int));

	DEBUG(x);
	int curr_index=0;
	fact[curr_index]=-1;
	bool check_least_prime[10000000]={false};

	DEBUG(x);

	while(x!=1)
	{
		DEBUG(x);
		if(check_least_prime[least_prime[x]]==false)
		{
			check_least_prime[least_prime[x]]=true;
			fact[curr_index++]=least_prime[x];
			fact[curr_index]=-1;
		}
		x/=least_prime[x];
	}
}

int main()
{
	std::ios::sync_with_stdio(false);

	least_prime[0]=0;
	least_prime[1]=1;
	sieve(1000000);

	int t;cin>>t;

	while(t--)
	{
		int n;cin>>n;
		int arr[n];REP(i,n)cin>>arr[i];

		// REP(i,n)cout<<arr[i]<<" ";

		int len[n];

		REP(i,n)
		{
			// int fact[15];
			// int *fact=(int *)malloc(15*sizeof(int));
			DEBUG(i);
			int x=arr[i];	
			DEBUG(x);
			int *fact=factorize(x);
			cout<<arr[i]<<" : ";
			REP(i,n)
			{
				if(fact[i]==-1)
					break;
				cout<<arr[i]<<" ";
			}
			// cout<<endl;
		}

	}
}