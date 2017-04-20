// #include <iostream>
#include <bits/stdc++.h>


using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;

int main()
{
	int n,x,i;
	cin>>n>>x;
	int a[n];
	int num[100010] = {0};
	long long int ans = 0;
	int temp;
	// cout<<n<<endl;
	for(i=0;i<n;i++)
	{
		cout<<n<<endl;
		cin>>temp;
		cout<<"hello"<<endl;
		a[i]=temp;
		// DEBUG(i);
		DEBUG(temp);
		num[temp]++;
		DEBUG(i);

	}

	// cout<<"hello"<<endl;

	for(i=0;i<n;i++)
	{
		int p = (x^a[i]);
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