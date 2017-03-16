#include <bits/stdc++.h>
#define pb push_back
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long

int maxito(int x,int y)
{
	if(x>y)
		return x;
	return y;
}

int main()
{
	int t;cin>>t;

	while(t--)
	{
		int n;cin>>n;
		int m;cin>>m;

		int a[n];

		REP(i,n)
		{
			cin>>a[i];
		}

		int res[n][n];
		int greatest[n][n];

		REP(i,m)
		{
			cout<<"bro"<<endl;
			int len[n];
			int l,r,ans=0;
			cin>>l>>r;

			// DEBUG(l);
			// DEBUG(r);

			for(int j=l;i<=r;j++)
			{
				len[j]=1;
				for(int k=l;k<j;k++)
				{
					DEBUG(l);
					DEBUG(r);
					DEBUG(n);
					DEBUG(m);
					DEBUG(t);
					DEBUG(k);
					DEBUG(j);
					if(a[j]>a[k])
					{
						len[j]=maxito(len[j],len[k]+1);
					}
				}
			}
			// cout<<"hello"<<endl;
			cout<<len[r]<<endl;
		}
	}
}