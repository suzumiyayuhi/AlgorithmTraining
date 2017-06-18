#include<iostream>
#include<algorithm>
using namespace std;

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

int heap_extract_max(int a[],int sz)
{
	swap(a[1],a[sz]);
	max_heapify(a,1,sz-1);
	return a[sz];
}

void heap_increase_key(int a[],int i,int key,int sz)
{
	if(a[i]>key)
		cout<<"new key should bigger than the old one"<<endl;
	else
	{
		a[i]=key;
		while(i>1&&a[i]<a[i/2])
		{
			swap(a[i],a[i/2]);
			i/=2;
		}
	}
}

void max_heap_insert(int a[],int key,int sz);//this function isnt necessary now.

int main()
{
	cout<<"priority queue"<<endl;
	cout<<"input the size of sequence"<<endl;
	int n;
	cin>>n;
	int a[n+1];
	cout<<"input the data of the sequenece"<<endl;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	build_max_heap(a,n);
	
	cout<<"input the index which you want to change the key in this sequence"<<endl;
	cin>>n;
	cout<<"input the value"<<endl;
	int v;
	cin>>v;
	heap_increase_key(a,n,v,n);
	cout<<"its be done"<<endl;
	
}
