#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdbool.h>
#include <string>
#include <vector>
#include <iterator>
#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int n;
		scanf("%d",&n);

		if(n==1)
		{
			cout<<"1"<<endl;
			continue;
		}

		int square[n][n];
		int x,y;

		for(int i=1;i<=n;i++)
		{
			x=0;
			y=(n/2+i-1)%n;
			for(int j=0;j<n;j++)
			{
				square[x][y]=i;
				x=(x+1)%n;
				y=(y+1)%n;
			}
		}

		// cout<<square[0][0];
		for(int i=0;i<n;i++)
		{
			cout<<square[i][0];
			for(int j=1;j<n;j++)
			{
				cout<<" "<<square[i][j];
			}
			cout<<endl;
		}
	}
}