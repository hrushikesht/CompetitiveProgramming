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

int arr[110];

int main()
{
	std::ios::sync_with_stdio(false);

	int n; cin>>n;
	int zero_count=0;
	int sum=0;
	int con_zero=0;

	bool flag=true;
	int last_index=1;

	FOR(i,1,n)
	{
		int temp; cin>>temp;
		
		if(temp==0)
		{ 
			zero_count++;
			if(last_index==(i-1))
			{
				last_index=i;
				flag=true;
			}
			else
			{
				last_index=i;
				flag=false;
			}

			if(!flag)
			{
				con_zero++;
			}
		}
		sum+=temp;

		arr[i]=temp;
	}

	// DEBUG(con_zero);

	if(sum!=0)
	{
		cout<<"YES"<<endl;
		cout<<1<<endl;
		cout<<"1 "<<n<<endl;
		return 0;
	}

	if(zero_count==n)
	{
		cout<<"NO"<<endl;
		return 0;
	}

	/*
	if(con_zero > (n/2))
	{
		cout<<"NO"<<endl;
		return 0;
	}
	*/

	if(arr[1]!=0)
	{
		cout<<"YES"<<endl;
		cout<<2<<endl;
		cout<<"1 1"<<endl;
		cout<<"2 "<<n<<endl;
		return 0;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(arr[i+1]==0)
			{
				continue;
			}
			else
			{
				cout<<"YES"<<endl;
				cout<<2<<endl;
				cout<<1<<" "<<i+1<<endl;
				cout<<i+2<<" "<<n<<endl;
				return 0;
			}
		}
	}





}