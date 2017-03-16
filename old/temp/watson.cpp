#include <iostream>
#include<stdio.h>
using namespace std;

int main() {
	// your code goes here
	int i,t,d;
	scanf("%d",&t);
	while(t--){
	    scanf("%d",&d);
	    if(d/9==0)
	    printf("%d\n",d+1);
	    else{
	        int c=d%9;
	        if(c==0)
	        printf("1\n");
	        else
	        printf("%d\n",c+1);
	    }
	}
	return 0;
}