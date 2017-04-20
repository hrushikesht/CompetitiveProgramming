#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdbool.h>
#include <string>

int main()
{
	int t=0;

	scanf("%d",&t);

	while(t--)
	{
		int x1,y1,x2,y2;

		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);

		int a=x2-x1;
		int b=y2-y1;

		if(a==0 || b==0)
		{
			if(a==0 && b>0)
			{
				printf("up\n");
			}
			else
			{
				if(a==0 && b<0)
				{
					printf("down\n");
				}
				else
				{
					if(b==0 && a>0)
					{
						printf("right\n");
					}
					else
					{
						printf("left\n");
					}
				}
			}
		}
		else
		{
			printf("sad\n");
		}
	}
}