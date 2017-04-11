#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

struct student
{
	int id;
	int mark;
};

bool cam(const student &a,const student &b)
{
	return a.mark>b.mark;
}

int CalRes(int str)
{
	int res=0;
	vector<student> students;
	student tem;
	int t;
	while(cin>>tem.id>>tem.mark)
	{
		if(tem.id==0&&tem.mark==0)
			break;
		else
		{
			students.push_back(tem);
			if(tem.id==str)
				t=tem.mark;
		}
			
	}
	sort(students.begin(),students.end(),cam);
	
	++res;
	for(vector<student>::iterator beg=students.begin();beg!=students.end();++beg)
	{
		if(beg->mark==t)	//you can not write "beg->id=str".because it leads WA
			break;
		++res;
	}
	return res;
}

int main()
{
	int number;
	while(cin>>number)
	{
		cout<<CalRes(number)<<endl;
	}
	return 0;
}
