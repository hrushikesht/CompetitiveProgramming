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
#define MOD 1000000007

using namespace std;

vector<ll int> arr;

// vector<ll int> fib;
ll int fib[1000000001] ={-1};

vector<ll int>::iterator it;

ll int findFib(ll int x)
{
	
	if(fib.at(x)!=-1)
	{
		return fib.at(x);
	}
	

	// cout<<"Hi 1"<<endl;

	ll int temp;

	/*
	try
	{
		temp = fib.at(x);
		return temp;
	}
	catch(const char *msg)
	{
		temp = findFib(x-1);
		cout<<"caught"<<endl;
	}
	*/

	ll int a,b;
	a = fib.at(x-1);
	b = fib.at(x-2);
	fib.pb((a+b)%MOD);

	return (a+b);
}

void print()
{
	for(it=arr.begin();it<arr.end();it++)
	{
		cout<<" "<<*it;
	}
	cout<<endl;
}

void increment(ll int l,ll int r,ll int x)
{
	cout<<" l = r = x = "<<l<<" "<<r<<" "<<x<<endl;
	for(it=arr.begin()+l;it<arr.begin()+r+1;it++)
	{
		cout<<"*it = "<<*it<<endl;
		*it+=x;
	}

	print();
}

ll int sumFib(ll int l,ll int r)
{
	ll int sum=0;

	for(it=arr.begin()+l;it<arr.begin()+r+1;it++)
	{
		cout<<"*now at sumFib *it = "<<*it<<endl;
		sum+=findFib(*it);
	}
}

// cout<<"hello"<<endl;

int main()
{

	cout<<"hello3"<<endl;

	fib.pb(0);
	fib.pb(1);
	fib.pb(2);

	int n,q;
	scanf("%d %d",&n,&q);

	// vector<ll int> arr;
	cout<<"hello2"<<endl;
	for(int i=0;i<n;i++)
	{
		ll int temp;
		cin>>temp;
		arr.pb(temp);
	}
	// cout<<"ar size= "<<arr.size()<<endl;
	cout<<"hello1"<<endl;

	for(int i=0;i<q;i++)
	{
		int temp;
		ll int l,r,x;
		cin>>temp;

		if(temp==1)
		{
			cin>>l>>r>>x;
			increment(l-1,r-1,x);
		}
		else
		{
			cin>>l>>r;
			ll int ans = sumFib(l-1,r-1);
			cout<<"ans =";
			cout<<ans<<endl;
		}
	}
}