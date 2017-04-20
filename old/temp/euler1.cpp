#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdbool.h>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <list>

using namespace std;

long long int findMax(long long int *cases,int test)
{
	long long int ma=0;
	for(int i=0;i<test;i++)
	{
		if(ma<cases[i])
		{
			ma=cases[i];
		}
	}
	return ma;
}

vector<long long int> memorize;

int main()
{
	int test;
	cin>>test;

	long long int cases[test];

	int j=0;
	while(j<test)
	{
		cin>>cases[test];
		j++;
	}

	int ma=findMax(cases,test);
	long int sum=0;

	for(long long int i=0;i<ma;i++)
	{
		if(i%3==0 || i%5==0)
		{
			sum+=i;
		}
		memorize.push_back(sum);
	}

	for(int i=0;i<test;i++)
	{
		cout<<memorize[i]<<endl;
	}
}