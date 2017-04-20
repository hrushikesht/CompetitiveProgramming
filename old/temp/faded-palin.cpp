#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdbool.h>
#include <string>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string palin;

		cin>>palin;

		int len=palin.size();
		int middle=0;

		if(len%2==0)
		{
			middle = (len/2)-1;
		}
		else
		{
			middle = len/2;
		}

		for(int i=0;i<=middle;i++)
		{
			char *front = &(palin[i]);
			char *back = &(palin[len-i-1]);

			if(*(front)=='.' || *(back)=='.')
			{
				if(*(front)==*(back))
				{
					*front='a';
					*back='a';
					if(i==middle)
					{
						cout<<palin<<endl;
					}
				}

				else
				{
					if(*(front)=='.')
					{
						*(front)=*(back);
						if(i==middle)
						{
							cout<<palin<<endl;
						}
					}
					else
					{
						*(back)=*(front);
						if(i==middle)
						{		
							cout<<palin<<endl;
						}
					}
				}
			}
			else
			{
				if(*(front)==*(back))
				{
					if(i==middle)
					{
						cout<<palin<<endl;
					}
					continue;
				}
				else
				{
					cout<<"-1"<<endl;
					break;
				}
			}
		}

	}
}