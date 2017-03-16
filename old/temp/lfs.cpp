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
		scanf("%d",&no_of_threads);

		int threads[no_of_threads][100],len_of_threads[no_of_threads+1],total_length_of_threads=0;

		for(int index=0;index<no_of_threads;index++)
		{
//			cout<<"Enter length: ";
			scanf("%d",&(len_of_threads[index]));
			total_length_of_threads+=len_of_threads[index];

//			cout<<"Enter elements of thread: ";
			for(int yo_index=0;yo_index<len_of_threads[index];yo_index++)
			{
				scanf("%d",&(threads[index][yo_index]));
			}
		}

		int generated_sequence[total_length_of_threads+1];

//		cout<<"Enter generated sequence: ";
		for(int index=0;index<total_length_of_threads;index++)
		{
			scanf("%d",&(generated_sequence[index]));
		}

		if(no_of_threads==1)
		{
			int count=0;
			for(int index=0;index<len_of_threads[0];index++)
			{
				count++;
				if(generated_sequence[len_of_threads[0]-index-1] != threads[0][index])
				{
					cout<<"No\n";
					break;
				}
			}

			if(count==len_of_threads[0])
			{
				cout<<"Yes\n";
			}
		}

	}
}