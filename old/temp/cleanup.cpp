#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdbool.h>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
	int t=0;
	scanf("%d",&t);

	while(t--)
	{
		int n,m;

		scanf("%d %d",&n,&m);

		vector<int> chef,assitant;
		vector<int> jobs_done(n,0);

		for(int i=0;i<m;i++)
		{
			int temp;
			scanf("%d",&temp);
			jobs_done.at(temp-1)=1;
		}

		bool flag=1;

		for(int i=0;i<n;i++)
		{
			if(jobs_done.at(i)==0)
			{
				if(flag==1)
				{
					chef.push_back(i+1);
					flag=0;
				}
				else
				{
					assitant.push_back(i+1);
					flag=1;
				}
			}
		}

		vector<int>::iterator it;

		for(it=chef.begin();it<chef.end();it++)
		{
			printf("%d ",*it);
		}
		printf("\n");

		for(it=assitant.begin();it<assitant.end();it++)
		{
			printf("%d ",*it);
		}
		printf("\n");


	}
}