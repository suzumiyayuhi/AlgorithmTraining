#include <stdio.h>
#include<string.h>
int a[10][10];
int main()
{
    int x;
    while(~scanf("%d",&x))
    {
        if(x==0)
            break;
        memset(a,0,sizeof(a));
        int i,j=0,s=1;
        for(i=0; i<x; i++)
        {
            for(; j<x; j++)
            {
                a[i][j]=s++;
            }
            if(j==x)
                j=x-1;
        }

        j=x-2;
        for(i=x-1; i>=1; i--)
        {
            for(; j>=0; j--)
                a[i][j]=s++;
            if(j<0)
                j=0;
        }

        for(i=0; i<x; i++)
        {
            for(j=0; j<x; j++)
                if(a[i][j]!=0)
                    printf("%3d",a[i][j]);
                else printf("   ");
            printf("\n");
        }

    }
    return 0;
}
