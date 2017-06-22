#include<iostream>
#include<algorithm>
using namespace std;
const int k=100000;

void counting_sort(int a[],int sz)
{
	int b[k],j=0;
	memset(b,0,sizeof(b));
	for(int i=0;i!=sz;i++)
		b[a[i]]++;
	for(int i=0;i!=k;i++)
	{

		while(b[i])
		{
			a[j]=i;
			j++;
			b[i]--;
		}
	}
}

int main()
{
	cout<<"counting sort"<<endl<<"input the size of this sequence"<<endl;
	int n;
	cin>>n;
	cout<<"input the data of this sequence"<<endl;
	int a[n];
	for(int i=0;i!=n;i++)
		cin>>a[i];
	cout<<"after sort"<<endl;
	counting_sort(a,n);
	for(int i=0;i!=n;i++)
		cout<<a[i]<<" ";
	
}
