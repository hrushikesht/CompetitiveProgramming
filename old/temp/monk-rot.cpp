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

bool myFunc(int x,int y){return x<y;}

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		ll n,k;
		cin>>n>>k;

		ll arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}

		ll ans_arr[n];
		ll rot=k%n;
		// cout<<(-1%3)<<endl;
		for(int i=0;i<n;i++)
		{
			ll yo=i-rot;
			if(i-rot <0)
			{
				yo=n+i-rot;
			}
			// cout<<"index = "<<yo<<endl;
			ans_arr[i]=arr[yo%n];
			cout<<ans_arr[i]<<" ";
		}
		cout<<endl;

	}
}