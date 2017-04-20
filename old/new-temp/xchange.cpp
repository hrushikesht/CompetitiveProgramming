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

bool is_even[200010]={true};
int arr[200010];

int main()
{
	std::ios::sync_with_stdio(false);

	unordered_map<int,int> M;

	int n; cin>>n;
	int m; cin>>m;

	int even=2;
	int odd=1;

	int index_even=1;
	int index_odd=1;

	REP(i,n)
	{
		cin>>arr[i+1];

		if((arr[i+1]&1))
		{
			is_even[i+1]=false;
			M[1]++;
		}
		else M[0]++;
	}

	// DEBUG(M[0]);
	// DEBUG(M[1]);

	if(M[0] > M[1])
	{
		while(M[0] > M[1])
		{
			

			FOR(i,index_even,n)
			{
				if(is_even[i])
				{
					if(odd>m)
					{
						cout<<"-1"<<endl;
						return 0;
					}

					arr[i]=odd;
					odd+=2;
					index_even=i;
					M[0]--;
					M[1]++;
					break;
				}
			}
		}
	}
	else
	{
		while(M[1]>M[0])
		{

			FOR(i,index_odd,n)
			{
				if(!is_even[i])
				{
					if(even>m)
					{
						cout<<"-1"<<endl;
						return 0;
					}

					arr[i]=even;
					even+=2;
					index_odd=i;
					M[1]--;
					M[0]++;
					break;
				}
			}
		}
	}

	FOR(i,1,n)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;


}