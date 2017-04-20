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
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void setBit(int & n, int b) { n |= two(b); }
inline void unsetBit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
inline bool sortDown(int x,int y){return x>y;}
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
/////////////////////////////////////////////////////////////////////

void printState(int r1,int c1,int r2,int c2)
{
	cout<<r1<<" "<<c1<<" "<<r2<<" "<<c2<<endl;
}

void colFourEqual(int col,int row_st)
{
	cout<<row_st<<" "<<col<<" "<<row_st+1<<" "<<col<<endl;
	cout<<row_st+2<<" "<<col<<" "<<row_st+3<<" "<<col<<endl;
	cout<<row_st+1<<" "<<col<<" "<<row_st+2<<" "<<col<<endl;
	cout<<row_st<<" "<<col<<" "<<row_st+1<<" "<<col<<endl;
	cout<<row_st+1<<" "<<col<<" "<<row_st+2<<" "<<col<<endl;
	cout<<row_st<<" "<<col<<" "<<row_st+1<<" "<<col<<endl;
	cout<<row_st+2<<" "<<col<<" "<<row_st+3<<" "<<col<<endl;
}

void rowFourEqual(int col,int row_st)
{
	cout<<col<<" "<<row_st<<" "<<col<<" "<<row_st+1<<endl;
	cout<<col<<" "<<row_st+2<<" "<<col<<" "<<row_st+3<<endl;
	cout<<col<<" "<<row_st+1<<" "<<col<<" "<<row_st+2<<endl;
	cout<<col<<" "<<row_st<<" "<<col<<" "<<row_st+1<<endl;
	cout<<col<<" "<<row_st+1<<" "<<col<<" "<<row_st+2<<endl;
	cout<<col<<" "<<row_st<<" "<<col<<" "<<row_st+1<<endl;
	cout<<col<<" "<<row_st+2<<" "<<col<<" "<<row_st+3<<endl;
}

void rowFiveEqual(int row,int col_st)
{
	cout<<row<<" "<<col_st+3<<" "<<row<<" "<<col_st+4<<endl;
	cout<<row<<" "<<col_st+2<<" "<<row<<" "<<col_st+3<<endl;
	cout<<row<<" "<<col_st+1<<" "<<row<<" "<<col_st+2<<endl;
	cout<<row<<" "<<col_st+0<<" "<<row<<" "<<col_st+1<<endl;
	cout<<row<<" "<<col_st+1<<" "<<row<<" "<<col_st+2<<endl;
	// cout<<row<<" "<<col_st+0<<" "<<row<<" "<<col_st+1<<endl;
	// cout<<row<<" "<<col_st+1<<" "<<row<<" "<<col_st+2<<endl;
	cout<<row<<" "<<col_st+0<<" "<<row<<" "<<col_st+1<<endl;
	cout<<row<<" "<<col_st+2<<" "<<row<<" "<<col_st+3<<endl;
}

void colFiveEqual(int col,int row_st)
{
	printState(row_st+3,col,row_st+4,col);
	printState(row_st+2,col,row_st+3,col);
	printState(row_st+1,col,row_st+2,col);
	printState(row_st+0,col,row_st+1,col);
	printState(row_st+1,col,row_st+2,col);
	// printState(row_st+0,col,row_st+1,col);
	// printState(row_st+1,col,row_st+2,col);
	printState(row_st+0,col,row_st+1,col);
	printState(row_st+2,col,row_st+3,col);
}

void makeFourxFourEqual(int row,int col)
{

	for(int k=row;k<=row+2;k+=2)
	{
		for(int l=col;l<=col+2;l+=2)
		{
			cout<<k<<" "<<l<<" "<<k<<" "<<l+1<<endl;
			cout<<k+1<<" "<<l<<" "<<k+1<<" "<<l+1<<endl;
			cout<<k<<" "<<l<<" "<<k+1<<" "<<l<<endl;
			cout<<k<<" "<<l+1<<" "<<k+1<<" "<<l+1<<endl;
		}
	}

	for(int k=row;k<=row+3;k++)
	{
		cout<<k<<" "<<col+1<<" "<<k<<" "<<col+3-1<<endl;
		cout<<k<<" "<<col+0<<" "<<k<<" "<<col+2-1<<endl;
		cout<<k<<" "<<col+1<<" "<<k<<" "<<col+3-1<<endl;
		cout<<k<<" "<<col+2<<" "<<k<<" "<<col+4-1<<endl;
		cout<<k<<" "<<col+0<<" "<<k<<" "<<col+2-1<<endl;
	}
	for(int l=col;l<=col+3;l++)
	{
		// cout<< <<" "<<j<<" "<< <<" "<<j<<endl;
		cout<<row+2-1<<" "<<l<<" "<<row+3-1<<" "<<l<<endl;
		cout<<row+1-1<<" "<<l<<" "<<row+2-1<<" "<<l<<endl;
		cout<<row+2-1<<" "<<l<<" "<<row+3-1<<" "<<l<<endl;
		cout<<row+3-1<<" "<<l<<" "<<row+4-1<<" "<<l<<endl;
		cout<<row+1-1<<" "<<l<<" "<<row+2-1<<" "<<l<<endl;
	}		
}

int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin>>n;

	if(n==2)
	{
		cout<<4<<endl;
		// cout<< <<" "<< <<" "<< <<" "<< <<endl;
		cout<<1<<" "<<1<<" "<<1<<" "<<2<<endl;
		cout<<2<<" "<<1<<" "<<2<<" "<<2<<endl;
		cout<<1<<" "<<1<<" "<<2<<" "<<1<<endl;
		cout<<1<<" "<<2<<" "<<2<<" "<<2<<endl;
	}
	if(n==4)
	{
		cout<<56<<endl;
		// cout<<1<<" "<<1<<" "<<1<<" "<<2<endl;
		// cout<< <<" "<< <<" "<< <<" "<< <<endl;
		for(int i=1;i<=3;i+=2)
		{
			for(int j=1;j<=3;j+=2)
			{
				cout<<i<<" "<<j<<" "<<i<<" "<<j+1<<endl;
				cout<<i+1<<" "<<j<<" "<<i+1<<" "<<j+1<<endl;
				cout<<i<<" "<<j<<" "<<i+1<<" "<<j<<endl;
				cout<<i<<" "<<j+1<<" "<<i+1<<" "<<j+1<<endl;
			}
		}

		for(int i=1;i<=4;i++)
		{
			cout<<i<<" "<<2<<" "<<i<<" "<<3<<endl;
			cout<<i<<" "<<1<<" "<<i<<" "<<2<<endl;
			cout<<i<<" "<<2<<" "<<i<<" "<<3<<endl;
			cout<<i<<" "<<3<<" "<<i<<" "<<4<<endl;
			cout<<i<<" "<<1<<" "<<i<<" "<<2<<endl;
		}

		for(int j=1;j<=4;j++)
		{
			// cout<< <<" "<<j<<" "<< <<" "<<j<<endl;
			cout<<2<<" "<<j<<" "<<3<<" "<<j<<endl;
			cout<<1<<" "<<j<<" "<<2<<" "<<j<<endl;
			cout<<2<<" "<<j<<" "<<3<<" "<<j<<endl;
			cout<<3<<" "<<j<<" "<<4<<" "<<j<<endl;
			cout<<1<<" "<<j<<" "<<2<<" "<<j<<endl;
		}

	}

	if(n==5)
	{
		cout<<140<<endl;

		for(int i=1;i<=3;i+=2) //16
		{
			for(int j=1;j<=3;j+=2) // 8
			{
				cout<<i<<" "<<j<<" "<<i<<" "<<j+1<<endl;
				cout<<i+1<<" "<<j<<" "<<i+1<<" "<<j+1<<endl;
				cout<<i<<" "<<j<<" "<<i+1<<" "<<j<<endl;
				cout<<i<<" "<<j+1<<" "<<i+1<<" "<<j+1<<endl;
			}
		}

		for(int i=1;i<=4;i++)// 20
		{
			cout<<i<<" "<<2<<" "<<i<<" "<<3<<endl;
			cout<<i<<" "<<1<<" "<<i<<" "<<2<<endl;
			cout<<i<<" "<<2<<" "<<i<<" "<<3<<endl;
			cout<<i<<" "<<3<<" "<<i<<" "<<4<<endl;
			cout<<i<<" "<<1<<" "<<i<<" "<<2<<endl;
		}

		for(int j=1;j<=4;j++) //20
		{
			// cout<< <<" "<<j<<" "<< <<" "<<j<<endl;
			cout<<2<<" "<<j<<" "<<3<<" "<<j<<endl;
			cout<<1<<" "<<j<<" "<<2<<" "<<j<<endl;
			cout<<2<<" "<<j<<" "<<3<<" "<<j<<endl;
			cout<<3<<" "<<j<<" "<<4<<" "<<j<<endl;
			cout<<1<<" "<<j<<" "<<2<<" "<<j<<endl;
		}

		// 56 steps done

		colFourEqual(5,1); // 7
		rowFourEqual(5,1); // 7

		FOR(i,1,5) // 9x5=45
		{
			rowFiveEqual(i,1); //9
		}
		FOR(i,1,5) // 9x5=45
		{
			colFiveEqual(i,1); //9 
		}

		// 45+45+7+7+56 = 160
	}

	if(n==8)
	{
		// cout<<"hello"<<endl;

		// int init_x=0;
		// int init_y=0;

		cout<<416<<endl;

		for(int i=1;i<=5;i+=4)
			for(int j=1;j<=5;j+=4)
				makeFourxFourEqual(i,j);

		for(int i=1;i<=8;i++)
		{
			printState(i,4,i,5);
			
			printState(i,3,i,4);
			printState(i,2,i,3);
			printState(i,1,i,2);
			printState(i,2,i,3);
			printState(i,1,i,2);
			printState(i,3,i,4);

			printState(i,5,i,6);
			printState(i,6,i,7);
			printState(i,7,i,8);
			printState(i,6,i,7);
			printState(i,5,i,6);
			printState(i,7,i,8);
			
		}

		for(int j=1;j<=8;j++)
		{
			printState(4,j,5,j);
			
			printState(3,j,4,j);
			printState(2,j,3,j);
			printState(1,j,2,j);
			// printState(2,j,3,j);
			// printState(1,j,2,j);

			cout<<416<<endl;
			printState(3,j,4,j);

			printState(5,j,6,j);
			printState(6,j,7,j);
			printState(7,j,8,j);
			printState(6,j,7,j);
			printState(5,j,6,j);
			printState(7,j,8,j);

		}
	}
}