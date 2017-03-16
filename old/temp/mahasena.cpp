#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdbool.h>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
	int n;
	int even=0;

	scanf("%d",&n);

	vector<int> weapons;

	for(int i=0;i<n;i++)
	{
		int temp;
		scanf("%d",&temp);
		if(temp%2==0)
		{
			even+=1;
		}
		// weapons.push_back(temp);
	}

	if(even>(n-even))
	{
		printf("READY FOR BATTLE\n");
	}
	else
	{
		printf("NOT READY\n");
	}


}