#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdbool.h>
#include <string>

using namespace std;

int main()
{
	int rows=0;

	scanf("%d",&rows);

	char arrangement[rows][5];

	for(int index=0;index<rows;index++)
	{
		scanf(" %[^\n]s",&(arrangement[index][0]));
	}

	int curr=-1,curr_row=-1;

//	cout<<arrangement[0][3]<<endl;

	for(int index=0;index<rows;index++)
	{
		
		if(arrangement[index][0]=='O' && arrangement[index][1]=='O')
		{
			curr_row=index;
			curr=0;
			cout<<"Yes\n";
			break;
		}

		else
		{
			if(arrangement[index][3]=='O' && arrangement[index][4]=='O')
			{
				curr_row=index;
				curr=3;
				cout<<"Yes\n";
				break;
			}
		}
	}

	if(curr==-1 && curr_row==-1)
	{
		cout<<"No\n";
		return 0;
	}


	arrangement[curr_row][curr]='+';
	arrangement[curr_row][curr+1]='+';

	for(int index=0;index<rows;index++)
	{
		for(int yo_index=0;yo_index<5;yo_index++)
		{
			printf("%c",arrangement[index][yo_index]);	
		}

		printf("\n");
		
	}

}