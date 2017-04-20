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
	int n=0;
	scanf("%d",&n);

	string s[n];

	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}

	// cout<<"hello"<<endl;

	int q=0;
	scanf("%d",&q);
	string que[q];

	for(int i=0;i<q;i++)
	{
		// string a;
		// cout<<"i = "<<i<<endl;
		cin>>que[i];
	}
	// cout<<"hello"<<endl;

	for(int i=0;i<q;i++)
	{
		int cnt=0;
		for(int j=0;j<n;j++)
		{
			// cout<<"hello"<<endl;
			int cnt2=0;
			// bool flag=1;
			if(s[j].size()==que[i].size())
			{
				for(int k=0;k<s[j].size();k++)
				{
					if(s[j][k]==que[i][k])
					{
						cnt2++;
						continue;
					}
					else
					{
						// flag=0;
						break;
					}
				}
			}
			if(cnt2==que[i].size())
			{
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}


}