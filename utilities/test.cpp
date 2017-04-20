#include <bits/stdc++.h>

#define ll long long int

const int mod = 1000000000;

using namespace std;

ll fib[4000010];

int main(){
	
	fib[1]=3;
	fib[2]=5;

	ll index=3;

	ll sum=0;
	ll factor=0;

	while(fib[index-1]<=4000000){
		fib[index]=fib[index-1]+fib[index-2];
		
		if(!(index%3))
		{
			sum+=fib[index];
			if(sum>=mod){
				factor++;
				sum-=mod;
			}
		}
		index++;
	}	

	cout<<index<<endl;

	cout<<"sum: "<<sum<<endl;
	cout<<"factor: "<<factor<<endl;

}