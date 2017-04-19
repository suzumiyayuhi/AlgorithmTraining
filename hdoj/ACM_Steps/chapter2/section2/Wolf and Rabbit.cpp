#include<iostream>
#include<algorithm>
using namespace std;

int gcd(int a,int b)
{
	if(a<b)
		swap(a,b);
	if(b==0)
		return a;
	else
		gcd(b,a%b);
}

int main()
{
	int N;
	cin>>N;
	while(N--)
	{
		int n,m;
		cin>>n>>m;
		int tem=gcd(n,m);
		if(tem==1)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
	return 0;
} 
