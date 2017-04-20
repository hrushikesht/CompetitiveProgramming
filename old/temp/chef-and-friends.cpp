#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdbool.h>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int test=0;
	cin>>test;

	while(test--)
	{
		int nodes=0,edges=0;
		cin>>nodes;
		cin>>edges;

		// cout<<nodes;

		int pairs[edges][2]={0};

		for(int i=0;i<edges;i++)
		{
			cin>>pairs[i][0]>>pairs[i][0];
		}

		int flag_break=1;
		int counter=0;

		for(int i=0;i<nodes;i++)
		{
			if(flag_break==0)
			{
				break;
			}

			int flag[nodes] = {0};
			flag[i]=0;

			for(int j=0;j<edges;j++)
			{
				if(pairs[j][0]==i)
				{
					flag[pairs[j][1]] =1;
				}
				else
					{
						if(pairs[j][1]==i)
						{
							flag[pairs[j][0]]=1;
						}
					}
			}

			int special=0;

			cout<<"show flag: ";

			for(int j=0;j<nodes;j++)
			{
				cout<<" "<<flag[j]<<" ";
			}

			for(int j=0;j<nodes;j++)
			{
				// cout<<"flag["<<j<<"] is "<<flag[j]<<endl;
				if(flag[j]==0)
				{
					special = j+1;
					break;
				}
			}

			for(int j=0;j<edges;j++)
			{
				if(flag[edges]==0)
				{
					if(pairs[j][0]==special || pairs[j][1]==special)
					{
						continue;
					}

					else
					{
						cout<<"NO"<<endl;
						flag_break=0;
						break;
					}
				}
			}
			counter++;

		}

		if(counter==nodes)
		{
			cout<<"YES"<<endl;
		}

	}
}