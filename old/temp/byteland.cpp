#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdbool.h>
#include <string>

using namespace std;

unsigned long long int returnSum(unsigned long long int coin)
{
	
	unsigned long long int coin1=coin/2,coin2=coin/3,coin3=coin/4;
	unsigned long long int sum=coin1+coin2+coin3;

	if(sum > coin)
	{
		sum+=returnSum(coin1)-coin1;

		sum+=returnSum(coin2)-coin2;

		sum+=returnSum(coin3)-coin3;

		return sum;
	}

	else
	{
		return coin;
	}
	
}

int main()
{
	int test=0;

//	cout<<"Enter the no fo test cases: ";
	cin>>test;

	while(test--)
	{
		unsigned long long int coin=0,ans=0;
		cin>>coin;

		ans=returnSum(coin);
		cout<<ans;


	}


}