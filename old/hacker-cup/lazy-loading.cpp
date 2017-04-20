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

	int t; cin>>t;
	int cas=t;

	while(t--)
	{
		int n; cin>>n;

		vector<int> items;
		items.pb(-1);

		REP(i,n)
		{
			int temp; cin>>temp;
			items.pb(temp);
		}

		sort(items.begin(),items.end());

		auto start=items.end()-1;
		auto end=items.begin()+1;

		int count=0;

		while(1)
		{
			if(start<end)
			{
				break;
			}

			if(*start>49)
			{
				count++;
				start--;
			}
			else
			{	
				int or_sum=*start;
				int sum=*start;
				bool flag=true;

				while(sum<50)
				{
					if(start==end)
					{
						flag=false;
						break;
					}
					sum+=(or_sum);
					end++;
				}

				start--;

				if(flag) count++;
				else break;
			}
		}

		cout<<"Case #"<<cas-t<<": "<<count<<endl;
	}
}