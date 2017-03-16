#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdbool.h>
#include <string>

using namespace std;

bool myfunction (int i,int j) 
{ 
	return (i<j);
} 


void show(int *cost,int no_of_player)
{
	for(int i=0;i<no_of_player;i++)
	{
		cout<<cost[i]<<" ";
	}
	cout<<endl;
}

int min_yo(int cookie[][6],int current_player)
{
	int min_cookie=99999;
	for(int i=0;i<6;i++)
	{
		if(min_cookie>cookie[current_player][i] && cookie[current_player][i]>0)
		{
			min_cookie = cookie[current_player][i];
		}
	}

	return min_cookie;
}

int check_zeros(int cookie[][6],int current_player)
{
	int counter=0;
	for(int i=0;i<6;i++)
	{
		if(cookie[current_player][i] == 0)
		{
			counter++;
		}
	}

	return counter;
}

void process(int cookie[][6],int *cost,int current_player,int bonus)
{
	int min_cookie = min_yo(cookie,current_player);

	cost[current_player] += min_cookie*bonus;

	// cout<<"cost show: "<<endl;
	// show(cost,2);

	for(int i=0;i<6;i++)
	{
		cookie[current_player][i] -= min_cookie;
	}

	int counter = check_zeros(cookie,current_player);

	// cout<<"counter for player "<<current_player<<" is "<<counter<<endl;

	if(counter==1)
	{
		process(cookie,cost,current_player,2);
	}
	else
	{
		if(counter==2)
		{
			process(cookie,cost,current_player,1);
		}
	}
}

int check_max(int *cost,int no_of_players)
{
	int max=-1,temp=0;
	for(int i=0;i<no_of_players;i++)
	{
		if(max<cost[i])
		{
			max=cost[i];
			temp=i+1;
		}
	}

	int counter=0;
	for(int i=0;i<no_of_players;i++)
	{
		if(max==cost[i])
		{
			counter++;
		}
	}

	if(counter>=2)
	{
		return 0;
	}
	else
	{
		return temp;
	}
}


int main()
{
	int test;
	cin>>test;

	// cout<<"bro";

	while(test--)
	{
		int no_of_players=0,temp=0;
		cin>>no_of_players;

		int cost[no_of_players+1]={0},no_of_cookies[no_of_players]={0},test=0;

		int **cookie = (int **)malloc((no_of_players+1)*sizeof(int *));
		for(int i=0;i<no_of_players+1;i++)
		{
			*(cookie+i) = (int *)calloc(6,sizeof(int));
		}

		for(int i=0;i<no_of_players;i++)
		{
			cin>>test;
			no_of_cookies[i] = test;
			cost[i]+=test;

			// cout<<"no of cookies["<<i<<"] are "<<test<<endl;

			for(int j=0;j<no_of_cookies[i];j++)
			{
				// cout<<"bro";
				// cout<<"no_of_cookies["<<i<<"] is "<<no_of_cookies[i]<<endl;
				// cout<<"now i = "<<i<<" and j = "<<j<<endl;
				cin>>temp;
				*(*(cookie+i)+temp-1)+=1;
			}
			// cout<<endl;
		}

		// cout<<"bro"<<endl;

		for(int i=0;i<no_of_players;i++)
		{
			sort((*(cookie+i)+0),(*(cookie+i)+6),myfunction);
			// cout<<"for case "<<test<<" and player "<<i<<endl;
			// for(int j=0;j<6;j++)
			// {
				// cout<<*(*(cookie+i)+j)<<" ";
			// }
			int min1=*(*(cookie+i)+0);
			int min2=*(*(cookie+i)+1);
			int min3=*(*(cookie+i)+2);
			cost[i]+=4*min1 + 2*(min2-min1) + (min3-min2);
			// cout<<endl;
		}	

		int special= check_max(cost,no_of_players);

		// cout<<"cost show: "<<endl;
		// show(cost,4);

		if(special==0)
		{
			cout<<"tie"<<endl;
		}
		else
		{
			if(special==1)
			{
				cout<<"chef"<<endl;
			}
			else
			{
				cout<<special<<endl;
			}
		}
	}

}