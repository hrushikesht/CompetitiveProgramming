#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdbool.h>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

struct Point{
	int x,y;
};	

int main()
{
	int t=0;
	// cout<<"Enter no of test cases: ";
	scanf("%d",&t);

	while(t--)
	{
		// cout<<"Enter n and m :"<<endl;
		int n,m;
		scanf("%d %d",&n,&m);

		int city[n][m];
		// cout<<"n and m are "<<n<<" and "<<m<<endl;

		// cout<<"Enter the matrix: "<<endl;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				scanf("%d",&(city[i][j]));
				// cout<<"i = "<<i<<" j= "<<j<<endl;
			}
		}

		// cout<<"Input Completed"<<endl;

		if(n==1 && m==1)
		{
			return city[0][0];
		}

		int minito=city[0][0];
		int min_sum=4*minito;


		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				int left=9999,right=9999,up=9999,down=9999;
				int centre=city[i][j];
				struct Point arr[5];
				
				arr[0].x=i;
				arr[0].y=j;
				arr[1].x=i;
				arr[1].y=j;
				arr[2].x=i;
				arr[2].y=j;
				arr[3].x=i;
				arr[3].y=j;
				arr[4].x=i;
				arr[4].y=j;

				for(int p=0;p<j;p++)
				{
					if(left>city[i][p])
					{
						// cout<<"left is "<<left<<" city is "<<city[i][p]<<" at i and j equal "<<i<<" "<<j<<endl;
						left=city[i][p];
						arr[0].y=p;
					}
				}

				for(int q=j+1;q<m;q++)
				{
					if(right>city[i][q])
					{
						right=city[i][q];
						arr[1].y=q;
					}

				}

				for(int r=0;r<i;r++)
				{
					if(up>city[r][j])
					{
						up=city[r][j];
						arr[2].x=r;
					}
				}

				for(int s=i+1;s<n;s++)
				{
					if(down>city[s][j])
					{
						// cout<<"down is "<<down<<" city is "<<city[s][j]<<" at i and j equal "<<i<<" "<<j<<endl;
						down=city[s][j];
						arr[3].x=s;

					}
				}

				if(city[i][j]>=0)
				{
					if(left>city[i][j])
					{
						left=city[i][j];
						arr[0].x=i;
						arr[0].y=j;
					}
					if(right>city[i][j])
					{
						right=city[i][j];
						arr[1].x=i;
						arr[1].y=j;
					}
					if(up>city[i][j])
					{
						up=city[i][j];
						arr[2].x=i;
						arr[2].y=j;
					}
					if(down>city[i][j])
					{
						down=city[i][j];
						arr[3].x=i;
						arr[3].y=j;
					}

				}

				else
				{
					if(left>0)
					{
						left=city[i][j];
						arr[0].x=i;
						arr[0].y=j;
					}
					if(right>0)
					{
						right=city[i][j];
						arr[1].x=i;
						arr[1].y=j;
					}
					if(up>0)
					{
						up=city[i][j];
						arr[2].x=i;
						arr[2].y=j;
					}
					if(down>0)
					{
						down=city[i][j];
						arr[3].x=i;
						arr[3].y=j;
					}
				}

				int direc[5]={left,right,up,down,centre};
				int sum=0;

				bool distinct[5]={0};

				for(int g=0;g<5;g++)
				{
					for(int h=0;h<g;h++)
					{
						if(arr[g].x==arr[h].x && arr[g].y==arr[h].y)
						{
							distinct[g]=1;
						}
					}
				}


				// cout<<"distinct: ";
				// for(int g=0;g<5;g++)
				// {
					// cout<<" "<<distinct[g];
				// }
				// cout<<endl;

				cout<<left<<" "<<right<<" "<<up<<" "<<down<<" at coordinates "<<i<<" and "<<j<<endl;

				if(min_sum>sum)
				{
					cout<<"min sum = "<<min_sum<<" sum = "<<sum<<endl;
					min_sum=sum;
				}
				// cout<<endl;

			}
		}

		// int sum=up+down+left+right;
		printf("%d\n",min_sum);
	}
}