#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdbool.h>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

bool myFunction(int i,int j){ return i>j;}

int main()
{
	int t=0;
	scanf("%d",&t);

	while(t--)
	{
		int n,m,D;
		scanf("%d %d %d",&n,&m,&D);

		vector<int> heros;

		for(int i=0;i<n;i++)
		{
			int temp=0;
			scanf("%d",&temp);
			heros.push_back(temp);
		}

		sort(heros.begin(),heros.end(),myFunction);

		int index=0;
		int counter=0;


		for(int i=0;i<m;i++)
		{
			int temp=heros.at(index);
			if((temp-D)<=0)
			{
				printf("NO\n");
				break;
			}
			else
			{
				heros[index]=heros[index]-D;
				
				if(heros.at(index)<=D)
				{
					index++;
				}

			}
			counter++;
		}

		if(counter==m)
		{
			printf("YES\n");
		}
	}
}