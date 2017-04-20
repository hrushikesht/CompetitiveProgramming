#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	int n,x,i;
	cin>>n>>x;
	int a[n];
	unordered_map<int,int> num;
	long long int ans = 0;
	int temp;
	for(i=0;i<n;i++)
	{	
		cin>>temp;
		a[i]=temp;
		num[temp]++;
	}

	for(i=0;i<n;i++)
	{
		int p = x^a[i];
		if(p==a[i])
		{
			ans += num[a[i]]-1;
		}
		else
		{
			ans += num[p];
		}

	}


	cout<<ans/2<<endl;

	return 0;


}