#include <bits/stdc++.h>
#define pb push_back
using namespace std; 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = 1<<29;
#define ll long long
#define F first
#define S second
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void setBit(int & n, int b) { n |= two(b); }
inline void unsetBit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
inline bool sortDown(int x,int y){return x>y;}
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
// inline bool sortDown(int x,int y){return x>y;}
/////////////////////////////////////////////////////////////////////



int main()
{
	std::ios::sync_with_stdio(false);
	
	int t;cin>>t;

	while(t--)
	{
		int n;cin>>n;
		int m;cin>>m;
		vector< pair<int,int> >::iterator it;
		vector<int>::iterator it_vec;

		vector< pair<int, int> > arr;
		vector<int> original;

		REP(i,n)
		{
			int temp;
			cin>>temp;
			pair<int,int> yo(temp,i);
			arr.pb(yo);
			original.pb(temp);
		}

		sort(arr.begin(),arr.end());

		ll int cum_sum[n+1];
		cum_sum[n]=1;

		
		int index=n-1;
		for(it=arr.end()-1;it>=arr.begin(),index>=0;it--,index--)
		{
			// cout<<()
			// DEBUG(n-(*it).S);
			// DEBUG((*it).S);			
			cum_sum[index]=(n-(*it).S) + cum_sum[index+1];
		}

		FOR(i,0,n-1)
		{
			cum_sum[i]-=1;
		}
		
		/*
		REP(i,n)
		{
			cout<<cum_sum[i]<<" ";
		}
		cout<<endl;
		*/
		
		REP(i,m)
		{
			// cout<<"hello"<<endl;
			int p;cin>>p;
			int maxito;

			FORD(i,n-1,0)
			{
				// DEBUG(i);
				if(p<=cum_sum[i])
				{
					int diff=cum_sum[i]-p;
					it=arr.begin()+i;
					int start=(*it).S;
					int end=start+diff;
					// DEBUG(start);
					// DEBUG(end);

					it_vec=original.begin()+start;

					maxito=*it_vec;
					for(int j=start;j<=end;j++,it_vec++)
					{
						// DEBUG(*it_vec);
						if(maxito<*it_vec)
						{
							// DEBUG((*it).F);
							maxito=*it_vec;
							// DEBUG(maxito);
						}
					}
					break;
				}
				// DEBUG()
				// cout<<maxito<<endl;
			}
			cout<<maxito<<endl;
		}
		

	}
}