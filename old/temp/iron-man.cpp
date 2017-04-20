#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdbool.h>
#include <string>
#include <vector>
#include <iterator>
#include <bits/stdc++.h>

using namespace std;


int main()
{
	int t=0;
	scanf("%d",&t);

	while(t--)
	{
		int n,o,cnt=0;
		scanf("%d %d",&n,&o);
		// cout<<"hello"<<endl;
		// cout<<"n="<<n<<endl;

		if((n%2)!=0)
		{
			for(int i=1;i<=n;i++)
			{
				// if(i>n)
					// break;
				for(int j=1;j<=n;j++)
				{
					// if(i==j)
						// continue;
					// cout<<"i and j = "<<i<<" "<<j<<endl;
					if((i+j)%o==0)
					{
						cnt++;
					}
				}
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				// if(i>n)
					// break;
				for(int j=i+1;j<=n;j++)
				{
					// if(i==j)
						// continue;
					// cout<<"i and j = "<<i<<" "<<j<<endl;
					if((i+j)%o==0)
					{
						cnt++;
					}
				}
			}
		}
		cout<<cnt<<endl;
	}
}