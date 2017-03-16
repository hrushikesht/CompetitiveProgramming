#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdbool.h>
#include <string>
#include <vector>
#include <iterator>
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define MOD 1000000007
#define MAX 1000001

int fact[MAX];

using namespace std;

int fast_pow(long long base, long long n)
{
    if(n==0)
       return 1;
    if(n==1)
    	return base;
    long long halfn=fast_pow(base,n/2);
    if(n%2==0)
        return ( halfn * halfn ) % MOD;
    else
        return ( ( ( halfn * halfn ) % MOD ) * base ) % MOD;
}
int findMMI_fermat(int n)
{
    return fast_pow(n,MOD-2);
}

int nCr(int n,int r)
{
	cout<<"n = "<<n<<" "<<"r = "<<r<<endl;
	int num = fact[n];
	cout<<"num = "<<num<<endl;
	int den = ((ll int)fact[n-r]*(ll int)fact[r])%MOD;
	cout<<"den = "<<den<<endl;
	int inv_den = findMMI(den);
	cout<<"inv_den = "<<inv_den<<endl;

	int temp=((ll int)num*(ll int)inv_den)%MOD;
	cout<<" n and r "<<n<<" "<<r<<" nCr = "<<temp<<endl;

	return temp;
}

int main()
{
	int t;
	scanf("%d",&t);

	fact[0]=1;
	fact[1]=1;

	for(int i=2;i<=MAX;i++)
	{
		fact[i]=((ll int)fact[i-1]*(ll int)i)%MOD;
	}

	/*
	for(int i=0;i<=25;i++)
	{
		cout<<"fact at i = "<<i<<" "<<fact[i]<<endl;
	}
	*/

	int base=6;
	for(int i=1;i<=1;i++)
	{
		cout<<"At i = "<<i<<" "<<nCr(base,i)<<endl;
	}

	while(t--)
	{
		int n,ans=0;
		scanf("%d",&n);

		for(int i=2;i<=n-1;i++)
		{
			// cout<<" i = "<<endl;
			int temp=nCr(n-1,i-1)%MOD;
			cout<<"temp at i = "<<i<<" "<<"is "<<temp<<endl;
			ans=(ans + temp)%MOD;
		}

		// cout<<"t = "<<t<<endl;
		cout<<ans<<endl;

	}
}