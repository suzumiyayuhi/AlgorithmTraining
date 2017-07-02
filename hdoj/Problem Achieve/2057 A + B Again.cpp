#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	__int64 a,b;  
    while(scanf("%I64X%I64X",&a,&b)!=EOF)  
    {  
        if(a+b>=0)  
            printf("%I64X\n",a+b);  
        else  
            printf("-%I64X\n",-(a+b));  
    }  
}
