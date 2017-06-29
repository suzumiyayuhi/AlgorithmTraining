#include<cstdio>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int a=n/2;
		n-=a;
		printf("%d\n",n*(n-1)/2+a*(a-1)/2);
	}
}
