#include <bits/stdc++.h>
#include <unordered_map>

#define pb push_back
#define F first
#define S second
#define i64 long long int

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

vector<i64> prime;

void sieve(i64 N)
{
	// DEBUG(N);
	vector<bool> check (N,false);
	// DEBUG(N);

	FOR(i,2,N-1)
	{
		// DEBUG(i);
		if(check.at(i)==true)
			continue;
		prime.pb(i);
		for(int j=i;j<N;j+=i)
		{
			// DEBUG(j);
			check.at(j)=true;
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	sieve(1000);

	// DEBUG(prime.at(0));

	int t; cin>>t;

	while(t--)
	{
		i64 n; cin>>n;

		unordered_map<int,int> M;

		for(auto it=prime.begin();it<prime.end();++it)
		{
			if(n==1)
			{
				break;
			}

			while(1)
			{
				if((n%(*it))==0)
				{
					n/=(*it);
					M[*it]++;
				}
				else
				{
					break;
				}
			}
		}

		vector<i64> divisors;
		divisors.pb(1);

		// vector<i64>::iterator start,end;

		for(auto it=prime.begin();it<prime.end();++it)
		{
			if(M[*it]==0)
			{
				continue;
			}

			int start = 0;
			int end = divisors.size();

			int temp = *it;
			for(int i=0;i<M[*it];++i)
			{
				// DEBUG(*it);
				// DEBUG(temp);

				for(int i = start ; i<end ; ++i)
				{
					// DEBUG(*it_2);
					divisors.pb((divisors.at(i))*temp);
				}
				temp = (temp*(*it));
			}
		}

		i64 sum=0;

		
		for(auto it=divisors.begin();it<divisors.end();++it)
		{
			sum+=*it;
			// cout<<*it<<" ";
		}
		// cout<<endl;
		
		cout<<sum<<endl;
	}
}