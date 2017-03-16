#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdbool.h>
#include <string>
#include <vector>
#include <iterator>
#define pb push_back

using namespace std;


bool find_here(int temp,vector<int> special)
{
	vector<int>::iterator it;
	bool flag=0;
	// cout<<"hello1"<<endl;
	for(it=special.begin();it<special.end();it++)
	{
		if(temp==*it)
		{
			return 1;
		}
	}
	return flag;
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);

	bool special[1001]={0};
	for(int i=0;i<n;i++)
	{
		int temp;
		scanf("%d",&temp);
		special[temp]=1;
	}
	// cout<<"hello";

	vector< pair<int, string> > special_list,normal_list;	
	// cout<<"hello"<<endl;

	int special_index=0,normal_index=0;
	for(int i=0;i<m;i++)
	{
		int temp;
		cin>>temp;
		if(special[temp])
		{
			int a;
			string b;
			cin>>a>>b;
			pair<int,string> yo(a,b);
			special_list.pb(yo);
			special_index+=1;
		}
		else
		{
			int a;
			string b;
			cin>>a>>b;
			pair<int,string> yo(a,b);
			normal_list.pb(yo);
			normal_index+=1;
		}
		// cout<<"hello"<<endl;
	}

	// cout<<"hello"<<endl;

	sort(special_list.begin(),special_list.end());
	sort(normal_list.begin(),normal_list.end());

	reverse(special_list.begin(),special_list.end());
	reverse(normal_list.begin(),normal_list.end());

	// vector< pair<int,string> >::iterator it;

	for(int i=0;i<special_index;i++)
	{
		cout<<special_list[i].second<<endl;
	}
	for(int i=0;i<normal_index;i++)
	{
		cout<<normal_list.at(i).second<<endl;
	}

}