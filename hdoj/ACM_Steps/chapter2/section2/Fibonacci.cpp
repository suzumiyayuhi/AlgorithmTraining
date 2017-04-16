#include<iostream>
#include<cmath>
using namespace std;
int f[21];
int main()
{
	int num;
	f[0]=0;
	f[1]=1;
	for(int i=2;i<21;++i)
		f[i]=f[i-1]+f[i-2];
	while(cin>>num)
	{
		if(num<=20)
			cout<<f[num]<<endl;
		else
		{
			double temp = -0.5 * log(5.0) / log(10.0) + ((double)num) * log((sqrt(5.0)+1.0)/2.0) / log(10.0);  
            temp -= floor(temp);  
            temp = pow(10.0, temp);  
            while(temp < 1000)  
                temp *= 10;  
             cout<<floor(temp)<<endl;
		}
	}
} 
