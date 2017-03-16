#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdbool.h>
#include <string>

using namespace std;

int main()
{
	int no_of_games=0;
	scanf("%d",&no_of_games);

	int games[no_of_games][2],mishka=0,chris=0,count_mishka=0,count_chris=0;

	for(int index=0;index<no_of_games;index++)
	{
		scanf("%d %d",&mishka,&chris);

		if(mishka>chris)
		{
			count_mishka+=1;
		}
		else
		{
			if(mishka<chris)
			{	
				count_chris+=1;
			}
		}
	}	

	if(count_mishka>count_chris)
	{
		cout<<"Mishka\n";
		return 0;
	}
	else
	{
		if(count_chris>count_mishka)
		{
			cout<<"Chris\n";
			return 0;
		}

		else
		{
			cout<<"Friendship is magic!^^\n";
			return 0;
		}
	}


}
