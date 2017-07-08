#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int sq[101];

int cmp(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}

int main()
{
	int T,N;
	cin>>T;
	while(T--)
	{
		cin>>N;
		for(int i=0;i<N;i++)
			cin>>sq[i];
		qsort(sq,N,sizeof(int),cmp);
		for(int i=0;i<N-1;i++)
			cout<<sq[i]<<" ";
		cout<<sq[N-1]<<endl;
	}
}
