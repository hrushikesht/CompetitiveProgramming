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

void print(vector<ll> &chamber)
{
	vector<ll>::iterator it;
	cout<<*(chamber.begin());
	for(it=chamber.begin()+1;it<chamber.end();it++)
	{
		cout<<" "<<*it;
	}
	cout<<endl;
}

int bombard(vector<ll> &chamber,int k,int n,int MAX)
{
	if(k>=MAX)
	{
		return 0;
	}
	// cout<<" now at k= "<<k<<endl;
	// print(chamber);
	chamber.at(k)+=1;
	if(chamber.at(k)>n)
	{
		// cout<<" now at k= "<<k<<endl;
		// print(chamber);
		chamber.at(k)=0;
		bombard(chamber,k+1,n,MAX);
	}
}

int main()
{
	ll a,n,k;

	cin>>a>>n>>k;
	vector<ll> chamber(k,0);

	/*
	for(int i=0;i<(a/(n+1));i++)
	{
		int temp=bombard(chamber,1,n,k);
	}

	int rem=a-(a/(n+1))*(n+1);
	// cout<<"rem  = "<<rem<<endl;
	// cout<<" a/n+1 and n+1 ="<<a/(n+1)*(n+1)<<endl;
	for(int i=0;i<rem;i++)
	{
		// cout<<"hello";
		int temp=bombard(chamber,0,n,k);
	}
	*/

	
	// bool flag=1;
	int quo=a/(n+1);
	int rem=a%(n+1);
	int index=0;

	while(1)
	{
		if(index>=k)
		{
			break;
		}

		if(quo==0 && rem==0)
		{
			break;
			// continue;
		}

		chamber.at(index) = rem;
		// chamber.at(index+1) = quo;
		index++;

		// cout<<"1 . quo and rem = "<<quo<<" "<<rem<<endl;

		rem = quo%(n+1);
		quo = quo/(n+1);
		// cout<<"2 . quo and rem and index = "<<quo<<" "<<rem<<" "<<index<<endl;
	}
	
	

	print(chamber);
	cout<<endl;

}