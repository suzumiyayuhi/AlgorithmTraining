#include<cstdio>
int main()  
{  
    int m[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};  
    int T,month,day;  
    scanf("%d",&T);  
    while(T--)  
    {  
        scanf("%d%d",&month,&day);  
        if(month == 10&&day == 21)  
            printf("It's today!!\n");  
        else if(month>10||(month==10&&day>21))  
            printf("What a pity, it has passed!\n");  
        else  
        { 
            int sum=day;  
            for(int i=1;i<month;++i)  
                sum+=m[i];  
            printf("%d\n",294-sum);  
        }  
    }  
}  
