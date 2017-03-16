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

bool myFunc(int x,int y){return x<y;}

ll int lcm(ll int x,ll int y)
{

	ll int X=x;
	ll int Y=y;

	while(1)
	{
		if((y%x)==0)
		{
			return (X*Y)/x;
		}

		ll int temp=y;
		y = x;
		x=temp%x;
	}
}

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int n;
		scanf("%d",&n);

		vector<ll int> response;
		for(int i=0;i<n;i++)
		{
			int temp;
			scanf("%d",&temp);
			response.pb(temp);
		}

		sort(response.begin(),response.end(),myFunc);

		ll int min_lcm = lcm(response.at(0),response.at(1));

		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				ll int lcm_now = lcm(response.at(i),response.at(j));
				if(min_lcm>lcm_now)
				{
					min_lcm = lcm_now;
				}
			}
		}

		cout<<min_lcm<<endl;
	}
}


