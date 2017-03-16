#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdbool.h>
#include <string>
#include <vector>
#include <iterator>
#include <bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;

int main()
{
	int t=0;
	scanf("%d",&t);

	while(t--)
	{
		int n;
		scanf("%d",&n);

		string grid[n];
		for(int i=0;i<n;i++)
		{
			cin>>grid[i];
		}


		if(n==1)
		{
			if(grid[0][0]=='#')
			{
				cout<<"1"<<endl;
				break;
			}
			else
			{
				cout<<"0"<<endl;
				break;
			}
		}

		bool right[n][n],bottom[n][n];
		int counter=0;
		
		for(int i=n-1;i>=0;i--)
		{
			for(int j=n-1;j>=0;j--)
			{

				right[i][j]=bottom[i][j]=0;
			}
		}
		

		int root=n-1;

		if(root==n-1)
		{
			if(grid[n-1][n-1]=='#')
			{
				right[root][root]=bottom[root][root]=1;
			}
			else
			{
				right[root][root]=bottom[root][root]=0;
				counter++;	
			}
		}

		for(int i=n-2;i>=0;i--)
		{
			if(grid[i][root]=='#')
			{
				right[i][root]=bottom[i][root]=1;
			}
			else
			{
				// cout<<"yay"<<endl;
				bottom[i][root]=bottom[i+1][root];
				right[i][root]=0;
				if(bottom[i+1][root]==0)
				{
					counter++;
				}
			}
		}
		for(int i=n-2;i>=0;i--)
		{
			if(grid[root][i]=='#')
			{
				right[root][i]=bottom[root][i]=1;
			}
			else
			{
				right[root][i]=right[root][i+1];
				bottom[root][i]=0;
				if(right[root][i+1]==0)
				{
					counter++;
				}
			}
		}

		for(int i=n-2;i>=0;i--)
		{
			for(int j=n-2;j>=0;j--)
			{
				bool flag=0;
				bool event=0;
				if(grid[i][j]=='#')
				{
					right[i][j]=bottom[i][j]=1;
					continue;
				}

				if(right[i][j+1]==1)
				{
					right[i][j]=1;
					flag=1;
				}
				if(bottom[i+1][j]==1)
				{
					bottom[i][j]=1;
					flag=1;
				}

				if(flag==0)
				{
					right[i][j]=bottom[i][j]=0;
					counter++;
				}
			}
		}
		cout<<counter<<endl;


	}
}