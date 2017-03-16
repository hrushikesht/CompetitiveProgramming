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

int board_num[5][5];

bool check_hor(int x,int y)
{
	int a=board_num[x][y];
	int b=board_num[x][y+1];
	int c=board_num[x][y+2];

	int x_cnt=0;
	int o_cnt=0;

	if(a==1)
	{
		x_cnt++;
	}
	else if(a==-1)
	{
		o_cnt++;
	}
	if(b==1)
	{
		x_cnt++;
	}
	else if(b==-1)
	{
		o_cnt++;
	}
	if(c==1)
	{
		x_cnt++;
	}
	else if(c==-1)
	{
		o_cnt++;
	}

	// DEBUG(a);
	// DEBUG(b);
	// DEBUG(c);
	// DEBUG(x_cnt);
	// DEBUG(o_cnt);

	if(a==-1 || b==-1 || c==-1)
	{
		return false;
	}

	if(o_cnt!=0)
	{
		return false;
	}

	if(x_cnt == 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool check_ver(int x,int y)
{
	int a=board_num[x][y];
	int b=board_num[x+1][y];
	int c=board_num[x+2][y];

	int x_cnt=0;
	int o_cnt=0;

	if(a==1)
	{
		x_cnt++;
	}
	else if(a==-1)
	{
		o_cnt++;
	}
	if(b==1)
	{
		x_cnt++;
	}
	else if(b==-1)
	{
		o_cnt++;
	}
	if(c==1)
	{
		x_cnt++;
	}
	else if(c==-1)
	{
		o_cnt++;
	}

	if(a==-1 || b==-1 || c==-1)
	{
		return false;
	}

	if(o_cnt!=0)
	{
		return false;
	}

	if(x_cnt == 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool check_diag(int x,int y)
{
	int a=board_num[x][y];
	int b=board_num[x+1][y+1];
	int c=board_num[x+2][y+2];

	int x_cnt=0;
	int o_cnt=0;

	if(a==1)
	{
		x_cnt++;
	}
	else if(a==-1)
	{
		o_cnt++;
	}
	if(b==1)
	{
		x_cnt++;
	}
	else if(b==-1)
	{
		o_cnt++;
	}
	if(c==1)
	{
		x_cnt++;
	}
	else if(c==-1)
	{
		o_cnt++;
	}

	if(a==-1 || b==-1 || c==-1)
	{
		return false;
	}

	if(o_cnt!=0)
	{
		return false;
	}

	if(x_cnt == 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool check_diag2(int x,int y)
{
	int a=board_num[x][y];
	int b=board_num[x+1][y-1];
	int c=board_num[x+2][y-2];

	int x_cnt=0;
	int o_cnt=0;

	if(a==1)
	{
		x_cnt++;
	}
	else if(a==-1)
	{
		o_cnt++;
	}
	if(b==1)
	{
		x_cnt++;
	}
	else if(b==-1)
	{
		o_cnt++;
	}
	if(c==1)
	{
		x_cnt++;
	}
	else if(c==-1)
	{
		o_cnt++;
	}

	if(a==-1 || b==-1 || c==-1)
	{
		return false;
	}

	if(o_cnt!=0)
	{
		return false;
	}

	if(x_cnt == 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}


int main()
{
	std::ios::sync_with_stdio(false);

	string board[5];
	

	FOR(i,1,4)
	{
		cin>>board[i];
	}

	FOR(i,1,4)
	{
		FOR(j,0,3)
		{
			if(board[i][j] == 'x')
			{
				board_num[i][j+1]=1;
			}
			else if(board[i][j] == 'o')
			{
				board_num[i][j+1]=-1;
			}
			else
			{
				board_num[i][j+1]=0;
			}
		}
	}

	/*
	FOR(i,1,4)
	{
		FOR(j,1,4)
		{
			cout<<board_num[i][j]<<" ";
		}
		cout<<endl;
	}

	bool flag=check_hor(1,1);
	*/

	
	FOR(i,1,4)
	{
		FOR(j,1,2)
		{
			bool flag=check_hor(i,j);

			if(flag)
			{
				cout<<"YES"<<endl;
				return 0;
			}
		}
	}

	FOR(i,1,2)
	{
		FOR(j,1,4)
		{
			bool flag=check_ver(i,j);

			if(flag)
			{
				cout<<"YES"<<endl;
				return 0;
			}
		}
	}

	FOR(i,1,2)
	{
		FOR(j,1,2)
		{
			bool flag=check_diag(i,j);

			if(flag)
			{
				cout<<"YES"<<endl;
				return 0;
			}
		}
	}

	FOR(i,1,2)
	{
		FOR(j,3,4)
		{
			bool flag=check_diag2(i,j);

			if(flag)
			{
				cout<<"YES"<<endl;
				return 0;
			}
		}
	}

	cout<<"NO"<<endl;
	return 0;
	

}