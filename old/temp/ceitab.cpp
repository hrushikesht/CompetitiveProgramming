#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdbool.h>
#include <string>

using namespace std;

int main()
{
	int a,b;

	scanf("%d %d",&a,&b);
	
	int ans=a-b;

	int rem = ans%10;

	if(rem==0)
	{
		ans=ans+1;
	}
	else
	{
		if(rem==1)
		{
			ans=ans+1;
		}
		else
		{
			ans-=1;
		}
	}

	printf("%d",ans);
}