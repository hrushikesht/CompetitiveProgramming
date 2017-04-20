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
	int t=0;
	scanf("%d",&t);

	while(t--)
	{
		ll n,k;
		vector<ll> song;

		cin>>n;
		for(int i=0;i<n;i++)
		{
			ll temp;
			cin>>temp;
			song.pb(temp);
		}
		cin>>k;

		vector<ll>::iterator it;
		
		ll lk=song.at(k-1);

		sort(song.begin(),song.end(),myFunc);

		int index=0;
		
		for(it=song.begin();it<song.end();it++,index++)
		{
			if(lk==*it)
			{
				// cout<<"lk = "<<lk;
				// cout<<" t= "<<t<<" "<<index+1<<endl;
				cout<<index+1<<endl;
			}
		}
	}
}