#include<iostream>
#include<string.h>
#include<cstdio>
using namespace std;

void square_martrix_multiply()
{
	cout<<"square martrix multiply"<<endl;
	cout<<"input the size of square martrix A and B"<<endl;
	int n;
	cin>>n;
	int A[n][n],B[n][n],C[n][n];
	memset(C,0,sizeof(C));
	cout<<"input the square martrix A";
	for(int i=0;i!=n;i++)
		for(int j=0;j!=n;j++)
			cin>>A[i][j];
	cout<<"input the square martrix B";
	for(int i=0;i!=n;i++)
		for(int j=0;j!=n;j++)
			cin>>B[i][j];
	
	for(int i=0;i!=n;i++)
		for(int j=0;j!=n;j++)
			for(int k=0;k!=n;k++)
				C[i][j]+=A[i][k]*B[k][j];	
	
	cout<<"the result is"<<endl;
	for(int i=0;i!=n;i++)
	{
		cout<<endl;
		for(int j=0;j!=n;j++)
			cout<<C[i][j]<<" ";
	}
}

int main()
{
	square_martrix_multiply();
}
