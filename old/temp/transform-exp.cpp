#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdbool.h>
#include <string>
#include <vector>
#include <iterator>
#include <stack>
#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int main()
{
	int t=0;
	scanf("%d",&t);

	while(t--)
	{
		string s;
		cin>>s;

		vector<char> ans;

		stack<char> letters,operations;

		letters.push(s[0]);

			for(int i=1;i<s.size();i++)
			{
				// cout<<"hello"<<endl;
				if(s[i]=='(')
				{
					// cout<<"hello"<<endl;

					letters.push(s[i]);
				}
				else
				{
					if(s[i]==')')
					{
						// cout<<"hello"<<endl;
						bool flag=1;
						ans.pb(operations.top());
						operations.pop();
					}
					else
					{
						if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='^' )
						{
							// cout<<"hello"<<endl;
							operations.push(s[i]);
						}
						else
						{
							// cout<<"hello"<<endl;
							ans.pb(s[i]);
						}
					}
				}
			}

			vector<char>::iterator it;

			/*
			cout<<"Letters : ";
			while(!letters.empty())
			{
				cout<<letters.top();
				letters.pop();
			}

			cout<<"operations : ";
			while(!operations.empty())
			{
				cout<<operations.top();
				letters.pop();
			}
			*/

			// cout<<"ans.size "<<ans.size()<<endl;

			for(it=ans.begin();it<ans.end();it++)
			{
				cout<<*it;
			}
			cout<<endl;


	}
}