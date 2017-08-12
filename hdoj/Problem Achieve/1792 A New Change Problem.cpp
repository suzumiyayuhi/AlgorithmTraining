#include<cstdio>
int main()  
{
	int n,m;
	while(~scanf("%d %d",&m,&n))
	{
		printf("%d %d\n",(m-1)*n-m,(n-1)*(m-1)/2);
	}
	return 0;
}   
