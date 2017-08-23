//code from http://www.cnblogs.com/zsychanpin/p/7298880.html 
#include<stdio.h>
#include<string.h>
#define max 500000 
int count[max];
int tree[max][26];
int main()
{
    int cnt=1,i;
    char str[20];
    while(gets(str),strlen(str)>0)
    {
        int len=strlen(str);
        int flag=0;
        for(i=0;i<len;i++)
        {
            if(tree[flag][str[i]-'a']==0)
            {
                tree[flag][str[i]-'a']=cnt;
                cnt++;
            }
            flag=tree[flag][str[i]-'a'];
            count[flag]++;
        }
    }   
    while(gets(str))
    {
        int num=0;
        int flag1=0;
        int len1=strlen(str);
        for(i=0;i<len1;i++)
        {
            if(tree[flag1][str[i]-'a']==0)
            {
                break;
            }
            flag1=tree[flag1][str[i]-'a'];
            if(i==len1-1)
            {
                num=count[flag1];
            }
        }
        printf("%d\n",num);
    }

    return 0;
}
