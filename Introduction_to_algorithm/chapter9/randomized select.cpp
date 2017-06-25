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

int random(int left,int right)
{
	int tem=rand()%(right-left);
	return tem+left;
}

int randomized_partition(int a[],int left,int right)
{
	int i=random(left,right);
	swap(a[right],a[i]);
	return partition(a,left,right);
}

int randomized_select(int a[],int left,int right,int sz)
{
	if(left==right)
		return a[left];
	int q=randomized_partition(a,left,right);
	int k=q-left+1;
	if(sz==k)
		return a[q];
	else if(sz<k)
		return randomized_select(a,left,q-1,sz);
	else
		return randomized_select(a,q+1,right,sz-k);
}

int main()
{
	cout<<"randomized select"<<endl<<"input the size of the sequence"<<endl;
	int n;
	cin>>n;
	cout<<"input the data"<<endl;
	int a[n+1];
	for(int i=1;i!=n+1;i++)
		cin>>a[i];
	cout<<"result is:"<<randomized_select(a,1,n,n)<<endl;
} 
