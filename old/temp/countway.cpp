#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdbool.h>
#include <string>
#define pb push_back

using namespace std;

int main()
{
	int n,k,ans=0;
	scanf("%d %d",&n,&k);

	vector<int> balls(k,0);
	for(int i=0;i<n;i++)
	{
		int temp;
		scanf("%d",&temp);
		balls.at(temp-1)+=1;
		ans*=(i+1)%13313;
	}

	for(int i=0;i<k;i++)
	{
		div
	}


}