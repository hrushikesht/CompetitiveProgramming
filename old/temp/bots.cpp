#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define getcx getchar_unlocked
char l[1],l1[1000],l2[1000];
int BITree[1000000];
using namespace std ;
inline void inp( int &n )//fast input function
{
   n=0;
   int ch=getcx();int sign=1;
   while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}

   while(  ch >= '0' && ch <= '9' )
           n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
   n=n*sign;
}
void print(int k)
{
	if (k==0)
	{
		printf("0\n");
		return;
	}
	while(k>0)
	{
		printf("%d ",k%2);
		k=k/2;
		if (k==0)
		{
			printf("0\n");
		}
	}

}
int main(int argc, char const *argv[])
{
	
    
    	int n,m,k1=0,bot=0,count=0,ch;
    	inp(n);
    	inp(m);
      	for (int i = n-1; i>=0; --i)
    	{
    		// printf("fuck\n");
    		inp(ch);
        // cout<<"ch = "<<ch<<endl;
    		k1+=ch*pow(2,i);
      }
       	
        // printf("%d k1\n",k1);
       	int ch2;
       	for (int i = 0; i < m; ++i)
       	{
       		inp(ch2);
          cout<<"ch2 = "<<ch2<<endl;
       		bot+=pow(2,ch2);
       	}
       	printf("%d bot111\n",bot);
       	for (int i = 0; i < n-1; ++i)
       	{
       		
       		if ((bot&k1)==bot)
       		{
       			count++;
       		}
       		int k=bot;
          
       		bot<<1;
          cout<<"bot now = "<<bot<<endl;
       		print(bot);
          cout<<"k>>n = "<<(k>>(n))<<endl;
       		print(k>>(n ));
       		bot+=(k>>(n-1))%2;
          cout<<"bot now = "<<bot<<endl;

       		print(bot);
       		printf("k2 %d\n",bot);
          cout<<endl;
          

          // bot
       	}
       	printf("%d count\n",count );

    
	return 0;
}