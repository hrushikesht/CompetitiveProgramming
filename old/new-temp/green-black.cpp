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

	int n; cin>>n;
	int k; cin>>k;
	int a; cin>>a; //green
	int b; cin>>b; //black

	vector<int> tea;
	char d[2]={'G','B'};

	int greater = a;
	int lesser = b;
	int flag=1;

	if(b>a)
	{
		flag=0;
		greater=b;
		lesser=a;
	}

	int flag2=1;
	int curr_streak_g=0;
	int curr_streak_l=0;

	int flag_x=1;


	while(1)
	{
		if(lesser<=0 && greater<=0)
		{
			break;
		}

		if(greater>lesser && flag_x==1)
		{
			curr_streak_l=0;
			tea.pb(0);
			greater--;
			curr_streak_g++;
			cout<<"yo1"<<endl;

			if(curr_streak_g>=k)
			{
				if(lesser<=0 && greater!=0)
				{
					DEBUG(tea.size());
					for(auto it=tea.begin();it<tea.end();++it)
					{
						cout<<d[*it];
					}
					cout<<"NO"<<endl;
					return 0;
				}

				DEBUG(curr_streak_g);

				curr_streak_g=0;
				flag_x=0;
			}
		}
		else if(lesser>greater && flag_x==0)
		{
			curr_streak_g=0;
			tea.pb(1);
			lesser--;
			curr_streak_l++;
			cout<<"yo2"<<endl;

			if(curr_streak_l>=k)
			{
				if(greater<=0 && lesser!=0)
				{
					DEBUG(tea.size());
					for(auto it=tea.begin();it<tea.end();++it)
					{
						cout<<d[*it];
					}
					cout<<"NO"<<endl;
					return 0;
				}

				DEBUG(curr_streak_l);

				curr_streak_l=0;
				flag_x=1;
			}
		}
	}

	if(flag==0)
	{
		d[0]='B';
		d[1]='G';
	}

	for(auto it=tea.begin();it<tea.end();++it)
	{
		cout<<d[*it];
	}
	cout<<endl;



}