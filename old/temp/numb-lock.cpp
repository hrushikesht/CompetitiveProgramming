#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdbool.h>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <list>

using namespace std;

void typeOne(int L,int R,int *lock)
{
	for(int i=L;i<=R;i++)
	{
		lock[i]=(lock[i]+1)%10;
	}
}

void typeTwo(int L,int R,int *lock)
{
	int sum=0;

	for(int i=L;i<=R;i++)
	{
		sum+=lock[i];
	}
	cout<<sum<<endl;
}

int main()
{
	int n,q;

	cin>>n>>q;

	int op[q][3];

	for(int i=0;i<q;++i)
	{
		cin>>op[i][0]>>op[i][1]>>op[i][2];
	}

	int lock[n]={0};

	for(int i=0;i<q;i++)
	{
		if(op[i][0]==1)
		{
			typeOne(op[i][1]-1,op[i][2]-1,lock);
		}
		else
		{
			typeTwo(op[i][1]-1,op[i][2]-1,lock);
		}
	}
}