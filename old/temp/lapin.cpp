#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdbool.h>
#include <string>
#include <vector>
#include <iterator>
#include <bits/stdc++.h>
#define pb push_back
#define ll long long int

using namespace std;

bool myFunc(int x,int y){return x<y;}

int main()
{
	int t=0;
	scanf("%d",&t);

	while(t--)
	{
		string s;
		cin>>s;

		int size=s.size();

		vector<int> cnt1(26,0);
		vector<int> cnt2(26,0);

		if(s%2==0)
		{
			for(int i=0;i<size;i++)
			{
				int temp=s[i]='a';
				
			}
		}
		else
		{

		}
	}
}