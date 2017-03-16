#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdbool.h>
#include <string>
#define N 8

using namespace std;

/*
This is an implementation of fenwick tree data structure.
*/

void update(int* BITree,int i,int val)
{
	int index=i+1;

	while(index<=N)
	{
		BITree[index]+=val;
		if(BITree[0]!=0)
		{
			cout<<"BITree[0] is "<<BITree[0]<<" at "<<i<<endl;
		}
		index+=(index&(-index));
	}
}

int getSum(int* BITree,int i)
{
	int index=i+1,sum=0;

	while(index>0)
	{
		sum+=BITree[index];
		index-=(index&(-index));
	}
	return sum;
}

int main()
{
	int arr[N],BITree[N+1]={0};

	for(int i=0;i<N;i++)
	{
		arr[i]=rand()%10;
	}

	for(int i=0;i<=N;i++)
	{
		update(BITree,i,arr[i]);
	}

	cout<<"BITree[0] = "<<BITree[0]<<endl;

	cout<<"Array is: ";
	for(int i=0;i<N;i++)
	{
		cout<<" "<<arr[i];
	}
	cout<<endl;

	cout<<"Fenwick is: ";
	for(int i=0;i<=N;i++)
	{
		cout<<" "<<BITree[i];
	}
	cout<<endl;

	cout<<"Sum is";
	for(int i=0;i<N;i++)
	{
		cout<<" "<<getSum(BITree,i);
	}
	cout<<endl;

}