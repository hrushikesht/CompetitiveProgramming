#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdbool.h>
#include <string>

using namespace std;

int main()
{
	int n=0;

	scanf("%d",&n);
	
	long long int grid[n][n],temp=0;
	int x=-1,y=-1;

	for(int x_index=0;x_index<n;x_index++)
	{
		for(int y_index=0;y_index<n;y_index++)
		{
			cin>>temp;
			grid[x_index][y_index]=temp;
			if(temp==0)
			{
				x=x_index;
				y=y_index;
			}
		}
	}

	
	if(n==1)
	{
		cout<<1<<endl;
		return 0;
	}
	

//	cout<<"x_index "<<x<<endl;
//	cout<<"y_index "<<y<<endl;

	long long int sum_at_zero=0,sum_adaj_zero=0;

	for(int index=0;index<n;index++)
	{
		sum_at_zero+=grid[index][y];
		sum_adaj_zero+=grid[index][(y+1)%n];
	}

//	cout<<"yo";

	long long int diff=sum_adaj_zero-sum_at_zero;

//	cout<<"sum adaj = "<<sum_adaj_zero<<endl;
//	cout<<"sum zero = "<<sum_at_zero<<endl;

	if(diff<1)
	{
		cout<<"-1\n";
//		cout<<"yo";
		return 0;
	}

	grid[x][y]=diff;

	long long int sum_of_one_row=sum_adaj_zero;
	long long int sum_x[n]={0};
	long long int sum_y[n]={0};
	long long int diag[2]={0};

	for(int x_index=0;x_index<n;x_index++)
	{
		for(int y_index=0;y_index<n;y_index++)
		{
			sum_x[x_index]+=grid[x_index][y_index];
			sum_y[y_index]+=grid[x_index][y_index];

			if(x_index==y_index)
			{
				diag[0]+=grid[x_index][y_index];
			}

			if((x_index+y_index)==(n-1))
			{
				diag[1]+=grid[x_index][y_index];
			}
		}
	}

	if(diag[0]!=sum_of_one_row || diag[1]!=sum_of_one_row)
	{
		cout<<"-1"<<endl;
		return 0;
	}

	for(int index=0;index<n;index++)
	{
		if(sum_x[index]!=sum_of_one_row || sum_y[index]!=sum_of_one_row)
		{
			cout<<"-1"<<endl;
			return 0;
		}
	}

	cout<<diff<<endl;


}