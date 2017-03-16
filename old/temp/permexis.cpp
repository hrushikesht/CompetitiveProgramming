
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdbool.h>
#include <string>
#include <vector>
#define pb push_back

using namespace std;

bool myFunction(int x,int y){return x<y;}

int main()
{
	int t=0;
	scanf("%d",&t);

	while(t--)
	{
		int N;
		scanf("%d",&N);

		vector<int> arr;

		for(int i=0;i<N;i++)
		{
			int temp;
			scanf("%d",&temp);
			arr.pb(temp);
		}

		sort(arr.begin(),arr.end(),myFunction);
		
		bool flag=0;
		for(int i=0;i<N-1;i++)
		{
			if(abs(arr.at(i)-arr.at(i+1))<=1)
			{
				// cout<<"arr[i] = "<<arr.at(i)<<" arr[i+1] = "<<arr.at(i+1)<<endl;
				continue;
			}
			else
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}