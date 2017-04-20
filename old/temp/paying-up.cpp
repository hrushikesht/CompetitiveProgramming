#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdbool.h>
#include <string>
#include <vector>
#include <iterator>
#include <bits/stdc++.h>
#define pb push_back

using namespace std;

bool myFunc(int x,int y){return x<y;}

int flag_arr[40001][21]={0};

int main()
{
	int t=0;
	scanf("%d",&t);

	while(t--)
	{

		for(int i=0;i<40001;i++)
		{
			for(int j=0;j<21;j++)
			{
				flag_arr[i][j]=0;
			}
		}

		int n,m,sum=0;
		scanf("%d %d",&n,&m);
		

		vector<int> notes;
		// vector<int> notes_cnt(21,0);
		vector<int>::iterator it;

		// int notes[n];
		int notes_cnt[n]={0};
		
		for(int i=0;i<n;i++)
		{
			int temp;
			scanf("%d",&(temp));
			// sum+=temp;
			notes.pb(temp);
			// notes_cnt.at(i)+=1;
			notes_cnt[i]+=1;
		}
		// cout<<"hello"<<endl;

		sort(notes.begin(),notes.end(),myFunc);

		vector<int> memonize(m+1,20001);
		// struct flags *fl = (struct flags *)malloc((n+1)*sizeof(struct flags));
 		memonize.at(0)=0;

		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(notes.at(j-1)<=i && (memonize.at(i-notes.at(j-1))+1)<memonize.at(i))
				{
					if(flag_arr[i-notes.at(j-1)][j]<notes_cnt[j])
					{
						memonize.at(i)=memonize.at(i-notes.at(j-1))+1;
						// cout<<"i = "<<i<<" j= "<<j<<endl;
						flag_arr[i][j]+=1;
					}
				}
			}
		}

		if(memonize.at(m)!=20001)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
		// cout<<"hello"<<endl;
	}
}