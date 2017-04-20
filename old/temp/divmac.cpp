#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdbool.h>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<int,int> cache {{1,1},{2,2},{3,3},{4,2}};

bool myFunction(int i,int j)
{
	return (i<j);
}

vector<int> prime;
// prime.reserve(1000);
// prime.push_back(2);

int max_cal(int x,int y)
{
	if(x>y)
	{
		return x;
	}

	return y;
}

void sieve(int x)
{
	bool flag=1;
	vector<int> test;

	for(int i=0;i<=1000;i++)
	{
		test.push_back(i);
	}

	
	for(int i=2;i<=1000;i++)
	{
		if(test[i]==-1)
		{
			continue;
		}

		prime.push_back(i);

		for(int j=i;j<=1002;j+=i)
		{
			test[j]=-1;
		}
	}
	
}


int leastPrimeDivisor(int x)
{

	
	
	// sort(prime.begin(),prime.end(),myFunction);
	int elem=0;
	// cout<<"x = "<<x<<endl;
	int size = prime.size();
	// bool flag=1;

	auto found = cache.find(x);
	if(found!=end(cache))
	{
		// cout << "Found in cache: " << x << " -> " << found->second << '\n';

		return found->second;
	}
	

	// return x;
	

	for(int i=0;i<=x;i++)
	{
		elem = prime[i];

		if(elem>x)
		{	
			return 1;
		}

		else
		{
			if((x%elem)==0)
			{
				cache[x] = elem;
				return elem;
			}
		}
		
	}
	
}

void typeZero(int *arr,int l,int r)
{
	for(int i=l;i<=r;i++)
	{	
		// cout<<"arr[i] is "<<arr[i]<<endl;
		int least = leastPrimeDivisor(arr[i]);
		// cout<<"for l ="<<l<<" and r = "<<r<<"lpd is "<<least<< " a[ " << i << " ] = "<<arr[i]<<endl;
		arr[i] = arr[i]/least;
		// cout<<"changed a[i] is "<<arr[i]<<endl;
		// arr[i] = 1;
	}
}


//get operation
int typeOne(int *arr,int l,int r)
{
	int result=1;
	for(int i=l;i<=r;i++)
	{
		// cout<<"result is "<<result<<" lpd is "<<leastPrimeDivisor(arr[i])<<" for a["<<i<<"] = "<<arr[i]<<endl;
		result = max_cal(result,leastPrimeDivisor(arr[i]));
		// cout<<"now result is "<<result<<endl;
	}

	return result;
}

int main()
{
	// prime.reserve(1000);
	// prime.push_back(2);
	sieve(1000);

	// for(int i=0;i<prime.size();i++)
	// {
		// cout<<prime[i]<<" ";
	// }

	int test;
	scanf("%d",&test);

	while(test--)
	{
		int length=0,operations=0,ans=0;
		cin>>length;
		cin>>operations;

		int elem[length],op[operations][3];

		for(int i=0;i<length;i++)
		{
			scanf("%d",&(elem[i]));
		}

		for(int i=0;i<operations;i++)
		{
			for(int j=0;j<3;j++)
			{
				scanf("%d",&(op[i][j]));
			}
		}

		for(int i=0;i<operations;i++)
		{
			if(op[i][0] == 1)
			{
				// cout<<"processint for op 1"<<endl;
				ans = typeOne(elem,op[i][1]-1,op[i][2]-1);
				printf("%d ",ans);
				// cout<<endl;
			}
			else
			{
				// cout<<"processing for op 0"<<endl;
				typeZero(elem,op[i][1]-1,op[i][2]-1);
				// cout<<endl;
			}
		}

		// cout<<endl<<"print array: ";
		// for(int i=0;i<length;i++)
		// {
			// cout<<elem[i]<<" ";
		// }
		// cout<<elem;

		// cout<<" printing primes: ";
		// for(int i=0;i<prime.size();i++)
		// {
			// cout<<prime[i]<<" ";
		// }

		cout<<endl;
	}

	// for(auto i=cache.cbegin();i!=cache.cend();++i)
	// {
		// cout<<i->first <<"  "<<i->second<<endl;
	// }

}