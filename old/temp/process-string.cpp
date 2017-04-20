#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdbool.h>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
	int t=0;

	scanf("%d",&t);

	while(t--)
	{
		string s;
		cin>>s;
		int sum=0;

		for(int i=0;i<s.size();i++)
		{
			int temp=s[i];
			if(temp>=48 && temp<=57)
			{
				// cout<<"temp = "<<temp<<endl;
				sum+=temp;
				sum-=48;
			}
		}

		cout<<sum<<endl;
	}
}