#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdbool.h>
#include <string>

using namespace std;

int main()
{
	//int t;
	int error=5;

	for(int i=0;i<12*3600;i++)
	{
		float x= (i/120.0)-((i%3600)/10.0);
		// cout<<x<<endl;

		if(x-2400<error && (x-2400)>0)
		{
			int t=x/1;
			cout<<"h = "<<(x/3600)<<" min= "<<(t%3600);
		}
	}
}