#include<iostream>
#include<algorithm>
using namespace std;

int partition(int a[],int left,int right)
{
	int k=a[right];
	int x=left-1;
	for(int i=left;i<=right-1;i++)
	{
		if(a[i]<=k)
		{
			x++;
			swap(a[i],a[x]);
		}
	}
	swap(a[x+1],a[right]);
	return x+1;
}

void quick_sort(int a[],int left,int right)
{
	if(left<right)
	{
		int q=partition(a,left,right);
		quick_sort(a,left,q-1);
		quick_sort(a,q+1,right);
	}
}

int main()
{
	cout<<"quick sort"<<endl<<"input the size of the sequence"<<endl;
	int N;
	cin>>N;
	cout<<"input the data"<<endl;
	int a[N+1];
	for(int i=1;i<=N;i++)
		cin>>a[i];
	quick_sort(a,1,N);
	cout<<"after sort"<<endl;
	for(int i=1;i<=N;i++)
		cout<<a[i]<<" ";
} 
