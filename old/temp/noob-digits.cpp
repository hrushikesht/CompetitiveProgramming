#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdbool.h>
#include <string>

using namespace std;



int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		string boolean;
		// boolean = (char *)malloc(51*sizeof(char));
		
		cin>>boolean;
		// cout<<sizeof(boolean);

		// scanf(" %[^\n]s",boolean);

		int ones=0,zeros=0,i=0;
		char temp;
		temp=boolean[0];

		// cout<<"boolean is "<<boolean<<endl;

		while(temp!='\0')
		{	
			// cout<<"i = "<<i<<endl;
			// cout<<"boolean[i] = "<<boolean[i]<<endl;

			int test_int=temp;

			if(test_int==48)
			{
				zeros+=1;
			}
			else
			{
				ones+=1;
			}
			
			// if(ones>1 && zeros>1)
			// {
				// cout<<"ones = "<<ones<<" zeros = "<<zeros<<endl;
				// cout<<"No"<<endl;
				// break;
			// }

			i++;
			temp=boolean[i];
			// cout<<"temp is "<<temp<<endl;
		}

		if(ones==1 || zeros==1)
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}
	}

}