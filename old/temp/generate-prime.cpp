#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdbool.h>
#include <string>

using namespace std;

int main()
{
	int t=0;
	cout<<"Enter the number of test cases: ";
	cin>>t;
	while(t--)
	{
		unsigned long long int m=0,n=0,index=0;
		unsigned long long int *pointer;

		cout<<"Enter m and n: ";

		cin>>m;
		cin>>n;

		cout<<"yo";}

/*		unsigned long long int  arr[n-1];

		for(index=0;index<n;index++)
		{
			arr[n]=index+2;
		}

		bool flag=1;
		pointer=arr;

		index=0;

		while(flag)
		{
			flag=0;
			while(*(pointer+index)==-1)
			{
				pointer=pointer+1;
				index++;
			}

			unsigned long long int copy_index=0;

			while(copy_index<=(n-index+1))
			{
				if((*(pointer+copy_index)%*(pointer)) == 0)
				{
					flag=1;
					*(pointer+copy_index)=-1;
				}
				copy_index++;
			}
		}

		for(int index=m;index<n;index++)
		{
			if(arr[index]!=-1)
			{
				cout<<arr[index]<<endl;
			}
		}
	}
*/	
	cout<<endl;
}