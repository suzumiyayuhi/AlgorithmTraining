#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int A[4],counter=0;
	while(cin>>A[0]>>A[1]>>A[2]>>A[3],A[0]+A[1]+A[2]+A[3])
	{
		if(counter)
		{
			cout<<endl;
		}
		counter=1;
		int flag=1,tem;
		do{
			if(A[0]==0)
				 continue;
			if(flag)
			{
				cout<<A[0]<<A[1]<<A[2]<<A[3];
				flag=0;
			}
			else if(tem==A[0])
				cout<<" "<<A[0]<<A[1]<<A[2]<<A[3];
			else
			{
				cout<<endl<<A[0]<<A[1]<<A[2]<<A[3];
			}
			tem=A[0];
		}while(next_permutation(A,A+4));
		cout<<endl;
	}
	return 0;
}
