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
		vector<int> sticks;
		vector<int> cnt(1001,0);
		int n;
		scanf("%d",&n);

		for(int i=0;i<n;i++)
		{
			int temp;
			scanf("%d",&temp);
			sticks.pb(temp);
			cnt.at(temp)+=1;
		}

		int first=-1,second=-1;

		vector<int>::iterator it;
		int index=0;

		for(it=cnt.begin();it<cnt.end();it++,index++)
		{
			int temp=*it;
			if(temp>=4)
			{
				if(index>=first)
				{
					first=second=index;
				}
				else
				{
					if(index>second)
					{
						second=index;
					}
				}
			}
			else
			{
				if(temp>=2)
				{
					if(index>=first)
					{
						second=first;
						first=index;
					}
					else
					{
						if(index>second)
						{
							second=index;
						}
					}
				}
			}
		}

		if(first==-1 || second==-1)
		{
			cout<<-1<<endl;
		}
		else
		{
			cout<<first*second<<endl;
		}

		// cout<<"hello"<<endl;	


	}
}