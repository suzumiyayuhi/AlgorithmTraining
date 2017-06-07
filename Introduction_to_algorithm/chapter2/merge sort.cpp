#include<iostream>
#include<algorithm>
using namespace std;

void merge(int s[],int a,int b,int c)
{
	int n1=b-a+1,n2=c-b;
	int left[n1],right[n2];
	for(int i=0;i!=n1;i++)
		left[i]=s[a+i];
	for(int i=0;i!=n2;i++)
		right[i]=s[b+i+1];
	int i=0,j=0;
	for(int k=a;k<=c;k++)
	{
		if(i!=n1&&j!=n2&&left[i]>=right[j])
			s[k]=left[i],i++;
		else if(i!=n1&&j!=n2&&right[j]>=left[i])
			s[k]=right[j],j++;
		else if(i==n1)
			s[k]=right[j],j++;
		else if(j==n2)
			s[k]=left[i],i++;
	}
}

void merge_sort(int s[],int a,int b)
{
	if(a<b)
	{
		int c=(a+b)/2;
		merge_sort(s,a,c);
		merge_sort(s,c+1,b);
		merge(s,a,c,b);
		for(int i=0;i!=8;i++)
			cout<<s[i];
		cout<<endl;
	}
}

int main()
{
	int N;
	cout<<"merge sort"<<endl;
	cout<<"input the size of sequence"<<endl;
	cin>>N;
	int s[N];
	cout<<"input the sequence"<<endl;
	for(int i=0;i!=N;i++)
		cin>>s[i];
	merge_sort(s,0,N-1);
	cout<<endl<<endl;
	cout<<"after sort"<<endl;
	for(int i=0;i!=N;i++)
		cout<<s[i];
} 
