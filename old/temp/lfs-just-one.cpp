#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdbool.h>
#include <string>
#include <stack>

using namespace std;

int main()
{
	int test=0;

//	cout<<"Enter no of test cases: ";
	scanf("%d",&test);

	while(test--)
	{
		int no_of_threads=0;

//		cout<<"Enter the number of threads: ";
		cin>>no_of_threads;

		if(no_of_threads==1)
		{
			int only_one_thread[10000],length_of_thread=0;

			scanf("%d",&length_of_thread);

			for(int index=0;index<length_of_thread;index++)
			{
				cin>>only_one_thread[index];
			}

			int one_sequence[length_of_thread+100];

			for(int index=0;index<length_of_thread;index++)
			{
				cin>>one_sequence[index];
			}

			for(int index=0;index<length_of_thread;index++)
			{
				if(one_sequence[index]!=only_one_thread[length_of_thread-index-1])
				{
					cout<<"No\n";
					return 0;
				}
			}

			cout<<"Yes\n";

		}
	}
}