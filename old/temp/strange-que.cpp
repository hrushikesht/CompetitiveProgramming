#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdbool.h>
#include <string>
#include <vector>
#include <iterator>
#include <bits/stdc++.h>
#define pb push_back
#define ll long long int


using namespace std;

int main()
{
	int n=0;
	scanf("%d",&n);

	vector<int> arr;
	for(int i=0;i<n;i++)
	{
		int temp;
		scanf("%d",&temp);
		arr.pb(temp);
	}

	bool flag[n][n]={0};
	int q;
	scanf("%d",&q);
	int que[q][4];

	// cout<<"Flag arr: "<<endl;
	
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			flag[i][j]=0;
		}
		// cout<<endl;
	}

	for(int i=0;i<q;i++)
	{
		cin>>que[i][0]>>que[i][1]>>que[i][2]>>que[i][3];
	}


	/*
	cout<<"Flag arr: "<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<" "<<flag[i][j];
		}
		cout<<endl;
	}
	*/

	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(arr.at(i)==arr.at(j))
			{
				flag[i][j]=1;
				flag[j][i]=1;
			}
		}
	}

	/*
	cout<<"Flag arr: "<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<" "<<flag[i][j];
		}
		cout<<endl;
	}
	*/
	// int cnt=0;

	for(int i=0;i<q;i++)
	{
		int cnt=0;
		for(int j=que[i][0]-1;j<=que[i][1]-1;j++)
		{
			for(int k=que[i][2]-1;k<=que[i][3]-1;k++)
			{
				if(flag[j][k]==1)
				{
					// cout<<"j and k = "<<j<<" "<<k<<endl;
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}


}