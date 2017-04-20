#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdbool.h>
#include <string>
#include <vector>
#include <iterator>
#include <bits/stdc++.h>
#define pb push_back
#define MIN 999999999

// struct alpha
// {
	// vector<int> arr;
// };

// bool myFunction(int x,int y){return x<y;}

using namespace std;

int main()
{
	int t=0;
	scanf("%d",&t);

	while(t--)
	{
		string s1,s2;
		cin>>s1>>s2;

		long long int size1=s1.size();
		long long int size2=s2.size();
		// bool flag1=(size1%2==0);
		// bool flag2=(size2%2==0);
		long long int half1=(size1-1+0.0)/2.0;
		long long int half2=(size2-1+0.0)/2.0;

		// struct alpha *alphabet_s1=(struct alpha *)malloc(26*sizeof(alpha));
		// struct alpha *alphabet_s2=(struct alpha *)malloc(26*sizeof(alpha));

		long long int min_yo_1[26][3],min_yo_2[26][3];
		for(int i=0;i<26;i++)
		{
			min_yo_1[i][0]=min_yo_1[i][1]=min_yo_1[i][2]=min_yo_2[i][0]=min_yo_2[i][1]=min_yo_2[i][2]=INT_MAX;
		}

		for(int i=0;i<size1;i++)
		{
			long long int temp=s1[i]-65;
			// cout<<"temp = "<<temp<<endl;
			min_yo_1[temp][1]=1;
			if(abs(half1-i)<min_yo_1[temp][0])
			{
				min_yo_1[temp][0]=abs(half1-i);
				min_yo_1[temp][2]=i;
			}
		}

		for(int i=0;i<size2;i++)
		{
			long long int temp=s2[i]-65;
			min_yo_2[temp][1]=1;
			if(abs(half2-i)<min_yo_2[temp][0])
			{
				min_yo_2[temp][0]=abs(half2-i);
				min_yo_2[temp][2]=i;
			}
		}


		long long int final_min_sum=INT_MAX;
		for(int i=0;i<26;i++)
		{
			// cout<<"t = "<<t<<"  i= "<<i;
			// cout<<" min1 "<<min_yo_1[i][1];
			// cout<<" min2 "<<min_yo_2[i][1]<<endl;
			if(min_yo_1[i][1]==1 && min_yo_2[i][1]==1)
			{
				int i1=min_yo_1[i][2];
				int i2=min_yo_2[i][2];

				int l1=i1;
				int l2=i2;
				int r1=s1.length()-i1-1;
				int r2=s2.length()-i2-1;

				long long int sum_final=abs(l1-r2)+abs(l1-l2)+abs(r2-r1)+abs(l2-r1);
				// cout<<"sum_final = "<<sum_final<<endl;
				if(sum_final<final_min_sum)
				{
					// cout<<"bro"<<endl;
					final_min_sum=sum_final;
				}
			}
		}
		cout<<final_min_sum<<endl;

	}
	// cout<<"bro "<<std::string::max_size()<<endl;
}