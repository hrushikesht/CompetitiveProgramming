#include <bits/stdc++.h>

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

vector<int> arr;
bool done[100010]={false};
vector<int> G[100010];

int main()
{
	std::ios::sync_with_stdio(false);

	int t; cin>>t;

	while(t--)
	{
		int n; cin>>n;
		int k; cin>>k;

		int ored=0;

		FOR(i,1,n)
		{
			int temp;
			cin>>temp;
			arr.pb(temp);
		}

		i64 ans=0;


		sort(arr.begin(),arr.end(),sortDown);

		
		FOR(i,0,n-1)
		{
			int temp=arr.at(i);

			if(temp >= k)
			{
				// DEBUG(i);
				ans+= (n-i);
				continue;
			}

			int start=i+1;
			int end=n-1;

			while((start-end)>1)
			{
				int mid=(start+end)/2;
				int temp2=(temp | arr[mid]);

				if(temp2>=k)
				{
					start=mid;
				}
				else end=mid;

			}
		}
		

		cout<<ans<<endl;



	}
}