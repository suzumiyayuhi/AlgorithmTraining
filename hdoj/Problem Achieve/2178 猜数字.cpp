#include<cstdio>
#include<cmath>
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",(int)(pow(2,n)-1));
	}
}
