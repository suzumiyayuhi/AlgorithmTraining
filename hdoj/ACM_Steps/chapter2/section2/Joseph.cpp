//code from http://blog.csdn.net/c_ychen/article/details/8654645 

#include<iostream>
using namespace std;
typedef struct joseph
{
int next;
int pre;
int cur;
}joseph;
int main()
{
	int k,m,count,total,i,j,rec1,rec2,a[14];
	joseph p[30];
	count=0;
	for(j=1;j<=13;j++)
	{
		for(m=2;count!=j*2;m++)
		{
			for(i=0;i<2*j;i++)
			{
				p[i].cur=i;
				p[i].next=i+1;
				p[i].pre=i-1;
			}
			p[2*j-1].next=p[0].cur;
			p[0].pre=p[2*j-1].cur; 
			count=0;
			rec1=0;
			total=2*j;
			do
			{
				for(i=1;i<=(m-1)%total;i++)
				rec1=p[rec1].next;
				rec2=p[rec1].next;
				p[p[rec1].pre].next=rec2;
				p[rec2].pre=p[rec1].pre; 
				if(p[rec1].cur>=0 && p[rec1].cur<j)  
				{
					break;
				}
				else
				{
					rec1=rec2;
					count++;                     
				}
				total--;  
			}while(count!=j);
			if(count==j) 
			{
				a[j]=m;
				break;
			}
		}
	}
	while(cin>>k && k)
	{
		cout<<a[k]<<endl;
	}
	return 0;
}
