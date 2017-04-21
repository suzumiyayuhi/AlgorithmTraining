#include<iostream>
#include<algorithm>
using namespace std;
int res[1000003];

void table()
{
	for(int i=1;i!=1000003;++i)
	{
		long long tem=i;
		int counter=1;
		for(;;++counter)
		{
			if(tem==1)
				break;
			if(tem%2!=0)
				tem=3*tem+1;
			else
				tem=tem/2;
		}
		res[i]=counter;
	}
}

int main()
{
	int a,b;
	table();
	while(cin>>a>>b)
	{	
		if(a<b)
			cout<<a<<" "<<b<<" "<<*max_element(res+a,res+b)<<endl;
		else
			cout<<a<<" "<<b<<" "<<*max_element(res+b,res+a)<<endl;
	}
	return 0;
} 
