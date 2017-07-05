#include<cstdio>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==1)
			printf("  1");
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(i/10==0)
					printf("%3d",i);
				else
					printf("%3d",i);
			}
			printf("\n");
			int tem1=4*n-4,tem2=n+1;
			for(int i=1;i<=n-2;i++)
			{
				if(tem1/10==0)
					printf("%3d",tem1--);
				else
					printf("%3d",tem1--);
				for(int j=1;j<=n-2;j++)
					printf("   ");
				if(tem2/10==0)
					printf("%3d",tem2++);
				else
					printf("%3d",tem2++);
				printf("\n");
			}
			for(int i=1;i<=n;i++)
			{
				if(tem1/10==0)
					printf("%3d",tem1--);
				else
					printf("%3d",tem1--);
			}
		}
		printf("\n");
	}
}
