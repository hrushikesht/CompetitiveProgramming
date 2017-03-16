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

vector<int> a;
vector<int> b;

int main()
{
	std::ios::sync_with_stdio(false);

	int n,l; cin>>n>>l;

	int suma=0,sumb=0;

	FOR(i,1,n)
	{
		int temp; cin>>temp;
		// cin>>a[i];?
		a.pb(temp);
		// suma+=a[i];
	}

	FOR(i,1,n)
	{
		int temp; cin>>temp;
		b.pb(temp);
		// cin>>b[i];
		// sumb+=b[i];
	}

	int keya = a.at(n-1);
	int keyb = b.at(n-1);


	for(int i=a.size()-1;i>=1;i--)
	{
		// DEBUG(i);
		// DEBUG(i);
		a.at(i)=a.at(i)-a.at(i-1);
		b.at(i)=b.at(i)-b.at(i-1);
		// DEBUG(a.at(i));
		// DEBUG(b.at(i));
	}

	// DEBUG(a[n-1]);
	// DEBUG(a[0]);

	a.at(0)=l-keya+a.at(0);
	b.at(0)=l-keyb+b.at(0);

	keya=a.at(0);
	keyb=b.at(0);

	// int idx=1;

	// while(idx<a.size() and a[idx]<keya)
	// {
	// 	a[idx-1]=a[idx];
	// 	idx++;
	// }
	// a.at(idx-1)=keya;


	// idx=1;
	// while(idx<b.size() and b[idx]<keyb)
	// {
	// 	b[idx-1]=b[idx];
	// 	idx++;
	// }
	// b.at(idx-1)=keyb;



	// DEBUG(a[0]);
	// DEBUG(b[0]);

	// sort(a.begin(),a.end());
	// sort(b.begin(),b.end());

	FOR(i,0,n-1)
	{
		FOR(j,0,n-1)
		{
			if(a[i]==b[j])
			{
				// DEBUG(i);
				// DEBUG(j);

				bool flag=true;
				for(int k=i,l=j;k<i+n,l<j+n;k++,l++)
				{
					if(a[k%n]!=b[l%n])
					{
						flag=false;
						break;
					}
				}
				if(flag)
				{
					cout<<"YES"<<endl;
					return 0;
				}
			}
		}
	}

	cout<<"NO"<<endl;
	return 0;

}