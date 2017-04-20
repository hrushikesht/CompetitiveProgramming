#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdbool.h>
#include <string>

using namespace std;

long long int maxTime(long long int x,long long int y)
{
	if(x>y)
	{
		return x;
	}
	return y;
}

long long int minTime(long long int x,long long int y)
{
	if(x<y)
	{
		return x;
	}
	return y;
}

long long int yo(long long int l2,long long int k,long long int r1)
{
	if(k<l2)
	{
		return 0;
	}
	if(l2<=k)
	{

		if(k<=r1)
		{
			return 1;
		}
	}

	return 0;
}

int main()
{
	long long int l1,r1,l2,r2,k;

	cin>>l1>>r1>>l2>>r2>>k;

	int ans=-maxTime(l1,l2)+minTime(r1,r2)-yo(l2,k,r1)+1;

	if(ans<0)
	{
		ans=0;
	}

	//cout<<"Here is the answer: ";
	cout<<ans<<endl;
}