#include<iostream>
#include<cstring>
#include<string>
#define MAX 233
using namespace std;
int data[MAX];

void powx(int *a ,int num,int n)
{
   memset(a,0,MAX*sizeof(int));
   int temp=num;
   for(int i=0;i<MAX;i++)
   {
      a[i]=temp%10;
      temp/=10;
   }
   
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<MAX;j++)
		{
			temp=num*a[j]+temp;
			a[j]=temp%10;
			temp/=10;
	 	} 
   }
}

int main()
{
	string str;
	int n, decilen;
 
	while(cin>>str>>n)
	{
		decilen=0;
  		int len=str.size();
  		int num=0;
  		for(int i=0;i<len;i++)
		{
			if(str[i]=='.') 
			{
            	decilen = len-i-1;
            	continue;
         	}
         	num=num*10+str[i]-'0';
      	}
		powx(data,num,n);

 		int x=decilen*n;
 		int s=-1,e=0;
 		for(int i = 0; i < MAX; i++)
		{
			if(s == -1 && data[i] != 0 && i <= x)
			s = i;
			if(data[i] != 0) 
				e = i;
		}
		if(s==-1) 
			s = x;
		if(e < x) 
			e = x;
		if(s > x) 
			s = x;
		
		bool flag = false;
		for(int i = e; i >= s; i--)
		{
			if(data[i]) 
				flag = true;
			if(flag)
				cout<<data[i];
			if( i == x && i - 1 >= s) 
			{
				flag = true;
				cout<<".";
 			}
		}
		if(!flag) 
			cout<<0;
		cout<<endl;
	}
	return 0;
}
