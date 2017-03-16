#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdbool.h>
#include <string>
#include <vector>
#include <iterator>
// #define MINITO 999999999999999999999999999999999

using namespace std;

bool myFunction(int i,int j){ return i<j; }

int main()
{
	int t=0;

	scanf("%d",&t);

	while(t--)
	{
		long int n;
		vector<long long int> horses;

		scanf("%ld",&n);
		// cout<<"this is n: "<< n;

		for(int i=0;i<n;i++)
		{
			long long int temp;
			scanf("%lld",&temp);
			horses.push_back(temp);
		}

		sort(horses.begin(),horses.end(),myFunction);

		vector<long long int>::iterator it;

		for(it=horses.begin();it<(horses.end()-1);it++)
		{
			*it = *(it+1)-*it;
		}

		// long long int i=0;
		long long int minito=horses.at(0);

		for(it=horses.begin();it<(horses.end()-1);it++)
		{
			if(minito>*it)
			{
				minito=*it;
			}
		}

		printf("%lld\n",minito);


	}
}