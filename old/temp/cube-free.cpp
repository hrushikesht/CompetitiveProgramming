#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdbool.h>
#include <string>
#include <vector>
#include <iterator>

#define pb push_back

using namespace std;

// bool myFunction(int x,int y){ return x>y }

int main()
{
	int t=0;
	scanf("%d",&t); 
	vector<long int> input,copy_input;
 
	while(t--)
	{
		long int temp=0;
		scanf("%ld",&temp);
		input.pb(temp);
		copy_input.pb(temp);
	}

	long int prime[25]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
	// sort(input.begin(),input.end(),myFunction);

	for(int i=0;i<25;i++)
	{
		prime[i]=prime[i]*prime[i]*prime[i];
	}

	long int pinnacle=*max_element(input.begin(),input.end());

	vector<int> functionWeWant;

	functionWeWant.reserve(1000000);
	functionWeWant[0]=0;
	functionWeWant[1]=1;

	long int index=2;

	for(int i=2;i<pinnacle;i++)
	{
		for(int j=0;j<25;j++)
		{
			if(i<j)
			{
				functionWeWant.at(i)=index;
				index++;
				break;
			}
			else
			{
				if(i%j==0)
				{
					functionWeWant.at(i)=-1;
					break;
				}
				else
				{
					functionWeWant.at(i)=index;
					index++;
					break;
				}
			}
		}
	}

	vector<long int>::iterator it;

	for(it=input.begin()+1;it<input.end();it++)
	{
		cout<<functionWeWant.at(*it)<<endl;
	}
}