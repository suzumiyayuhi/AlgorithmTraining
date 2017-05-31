#include<iostream>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N,n=1;
		cin>>N;
		while(N>n)
		{
			N-=n;
			n++;
		}
		N%=9;
		if(N==0)
			cout<<9<<endl;
		else
			cout<<N<<endl;
	}
} 
