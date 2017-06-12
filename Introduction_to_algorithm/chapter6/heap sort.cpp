#include<iostream>
#include<algorithm>
using namespace std;
int N=0;
void max_heapify(int a[],int n,int sz)
{
	int left=n*2,right=n*2+1,flag=n;
	
	if(left<=sz&&a[left]>a[flag])
		flag=left;
	if(right<=sz&&a[right]>a[flag])
		flag=right;
	if(flag!=n)
	{
		swap(a[flag],a[n]);
		max_heapify(a,flag,sz);
	}
}

void build_max_heap(int a[],int sz)
{
	for(int i=sz/2;i!=0;i--)
		max_heapify(a,i,sz);
}

void heap_sort(int a[],int sz)
{
	build_max_heap(a,sz);
	int tem=sz;
	for(int i=sz;i!=1;i--)
	{
		swap(a[1],a[i]);
		build_max_heap(a,--tem);
	}
}

int main()
{
	cout<<"heap sort"<<endl<<"now input a size of number sequence"<<endl;
	int sz;
	cin>>sz;
	cout<<"input the date of this sequence"<<endl;
	int a[sz+1];
	for(int i=1;i<=sz;i++)
		cin>>a[i];
	
	heap_sort(a,sz);
	cout<<"after sort"<<endl;
	for(int i=1;i<=sz;i++)
		cout<<a[i]<<" ";
} 
