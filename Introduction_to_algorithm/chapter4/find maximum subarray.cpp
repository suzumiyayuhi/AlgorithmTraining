#include<iostream>
using namespace std;
int XX=0;
struct result
{
	result(int a,int b,int c):low(a),high(b),sum(c){}
	int low,high,sum;
};

result find_max_crossing_subarray(int a[],int left,int mid,int right)
{
	int sum,left_low,right_high,left_sum=-1000,right_sum=-1000;
	sum=0;
	for(int i=mid;i>=left;i--)
	{
		sum+=a[i];
		if(sum>=left_sum)
		{
			left_low=i;
			left_sum=sum;
		}
	}
	sum=0;
	for(int i=mid+1;i<=right;i++)
	{
		sum+=a[i];
		if(sum>=right_sum)
		{
			right_high=i;
			right_sum=sum;
		}
	}
//	cout<<++XX<<endl;
	return result(left_low,right_high,left_sum+right_sum);
}

result find_maximum_subarray(int a[],int left,int right)
{
	if(left==right)
		return result(left,right,a[left]);
	else
	{
		int mid=(left+right)/2;
		result res1=find_maximum_subarray(a,left,mid);
		result res2=find_maximum_subarray(a,mid+1,right);
		result res3=find_max_crossing_subarray(a,left,mid,right);
		if(res1.sum>=res2.sum&&res1.sum>=res3.sum)
			return res1;
		else if(res2.sum>=res1.sum&&res2.sum>=res3.sum)
			return res2;
		else
			return res3;
	}
}

int main()
{
	cout<<"finding max subarray with divide and conquer strategy"<<endl;
	cout<<"input the size of sequence"<<endl;
	int n;
	cin>>n;
	cout<<"input the data"<<endl;
	int s[n];
	for(int i=0;i!=n;i++)
		cin>>s[i];
	
	cout<<"result is:";
	result res=find_maximum_subarray(s,0,n-1);
	cout<<res.low+1<<" "<<res.high+1<<" "<<res.sum;
} 
