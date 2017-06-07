#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int N;
	cout<<"insertion sort"<<endl;
	cout<<"input the size of sequence"<<endl;
	cin>>N;
	cout<<"input the number sequence"<<endl;
	int s[N];
	for(int i=0;i!=N;i++)
		cin>>s[i];
	for(int i=0;i!=N-1;i++)
	{
		int max=i;
		for(int j=i+1;j!=N;j++)
		{
			if(s[max]<s[j])
				max=j;
		}
		swap(s[max],s[i]);
	}
	cout<<"after sorted"<<endl;
	for(int i=0;i!=N;i++)
		cout<<s[i];
}
