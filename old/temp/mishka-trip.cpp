#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdbool.h>
#include <string>

using namespace std;
int main()
{
	cout<<"-1 mod 3 = "<<((-1)%3)<<endl;
	long int no_of_cities=0,no_of_capitals=0;

	scanf("%ld %ld",&no_of_cities,&no_of_capitals);

	long int beauty[no_of_cities],capital_index[no_of_capitals],consecutive_sum=0,temp=0,capital_sum=0;

	cout<<"yo";
	for(int index=0;index<no_of_cities;index++)
	{
		scanf("%ld",&(beauty[index]));
	}

	cout<<"yo";
	for(int index=0;index<no_of_capitals;index++)
	{
		scanf("%ld",&(capital_index[index]));
	}

	for(int index=0;index<no_of_cities;index++)
	{
		consecutive_sum+=beauty[index]*beauty[(index+1)%no_of_cities];
	}

	for(int index=0;index<no_of_capitals;index++)
	{
		temp=capital_index[index]-1;

		for(int yo_index=0;yo_index<no_of_cities;yo_index++)
		{
			if(temp=0 && yo_index==no_of_cities-1)
			{
				continue;
			}

			if(yo_index==(temp-1)%no_of_cities || yo_index==(temp+1)%no_of_cities || yo_index==temp)
			{
				continue;
			}

			cout<<"temp and yo_index="<<temp<<" "<<yo_index<<endl;

			capital_sum+=beauty[temp]*beauty[yo_index];


		}
	}

	cout<<"consecutive_sum = "<<consecutive_sum<<endl;	
	cout<<"capital_sum = "<<capital_sum<<endl;

}