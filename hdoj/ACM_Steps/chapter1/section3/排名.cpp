#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct Student
{
	string ID;
	int counter;
	int sum;
}; 



bool compareID(const Student &a,const Student &b)
{
	if(a.sum==b.sum)
		return a.ID<b.ID;
	else
		return a.sum>b.sum;
}

int main()
{
	int N,M,G;
	while(cin>>N)
	{
		if(N==0)
			break;
		cin>>M>>G;
		vector<Student> stu;
		int Mark[M],counter=0;
		for(int i=0;i!=M;++i)
		{
			cin>>Mark[i];
		}
		for(int i=0;i!=N;++i)
		{
			int sum=0;
			Student tem;
			cin>>tem.ID>>tem.counter;
			for(int j=0;j!=tem.counter;++j)
			{
				int a;
				cin>>a;
				sum+=Mark[a-1];	
			}
			tem.sum=sum;
			if(sum>=G)
				++counter;
			stu.push_back(tem);
		}
		sort(stu.begin(),stu.end(),compareID);
		cout<<counter<<endl;
		for(vector<Student>::iterator x=stu.begin();x!=stu.end();++x)
		{
			if((x->sum)>=G)
			{
				cout<<x->ID<<" "<<x->sum<<endl;
			}
		}
		counter=0; 
		
	}
	return 0; 
} 
