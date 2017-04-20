#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdbool.h>
#include <string>
#include <vector>
#include <iterator>
#include <stack>
#include <bits/stdc++.h>
// #define ll long long int;
#define pb push_back

using namespace std;

int main()
{
	vector<long long int> hfs(100,0);

	hfs.at(0)=1;
	hfs.at(1)=1;

	vector<long long int>::iterator it;
	int index=2;

	for(it=hfs.begin()+2;it<hfs.end();it++,index++)
	{
		*it = hfs.at(hfs.at(index-1)) + hfs.at(index - (hfs.at(index-1)) );
		cout<<" i = "<<index<<" is  "<<*it<<endl;
	}
}