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

bool myFunc(int x,int y){return x>y;}


int main()
{
	int t=0;
	scanf("%d",&t);

	while(t--)
	{
		int n;
		scanf("%d",&n);

		vector<int> warrior,horse;

		for(int i=0;i<n;i++)
		{
			int temp;
			cin>>temp;
			warrior.pb(temp);
		}

		for(int i=0;i<n;i++)
		{
			int temp;
			cin>>temp;
			horse.pb(temp);
		}

		sort(warrior.begin()+1,warrior.end(),myFunc);
		sort(horse.begin(),horse.end(),myFunc);

		bool flag=0;
		int brave_str=warrior.at(0)*horse.at(0);

		for(int i=1;i<n;i++)
		{
			// cout<<"warrior.at(i)*warrior.at(n-i) rrior.at(i)*warrior.at(n-i)<<endl;
			if(brave_str<=warrior.at(i)*horse.at(n-i))
			{
				flag=1;
				break;
			}
		}

		if(flag==0)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
}