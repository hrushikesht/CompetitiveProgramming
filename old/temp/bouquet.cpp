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

// ll matrix[3][3];

int main()
{
	int t=0;
	scanf("%d",&t);

	while(t--)
	{
		ll hor_sum[3]={0};
		ll ver_sum[3]={0};
		
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				ll temp;
				cin>>temp;
				// matrix[i][j]=temp;
				hor_sum[i]+=temp;
				ver_sum[j]+=temp;
			}
		}

		ll maxito = -1;

		for(int i=0;i<3;i++)
		{
			
			if(hor_sum[i]>maxito)
			{
				if((hor_sum[i]%2)==0)
				{
					maxito=hor_sum[i]-1;
				}
				else
				{
					maxito=hor_sum[i];
				}
			}

			if(ver_sum[i]>maxito)
			{
				if((ver_sum[i]%2)==0)
				{
					maxito = ver_sum[i]-1;
				}
				else
				{
					maxito = ver_sum[i];
				}
			}
		}

		if(maxito!=(-1))
		{
			cout<<maxito<<endl;
		}
		else
		{
			cout<<"0"<<endl;
		}


	}
}