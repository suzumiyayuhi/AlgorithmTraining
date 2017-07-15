#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main()
{
	int N,hp1,hp2,str1,str2,spd1,spd2,time1,time2;
	string s1,s2;
	cin>>N;
	while(N--)
	{
		cin>>s1>>s2;
		hp1=0;hp2=0;str1=1;str2=1;spd1=0;spd2=0;
		
		for(int i=0;i<s1.size();i++)
        {
            hp1=(hp1+(83-s1[i])*(83-s1[i]))%97;
            str1=(str1*s1[i])%79;
            for(int j=i+1;j<s1.size();j++)
            {
                spd1=(spd1+s1[i]*s1[j])%11;
            }
        }
        for(int i=0;i<s2.size();i++)
        {
            hp2=(hp2+(83 -s2[i])*(83-s2[i]))%97;
            str2=(str2*s2[i])%79;
            for(int j=i+1;j<s2.size();j++)
            {
                spd2=(spd2+s2[i]*s2[j])%11;
            }
        }
        hp1=300-hp1;
        hp2=300-hp2;
        str1+=22;
        str2+=22;
		
		time1=hp1/str2;
		time2=hp2/str1;
		if(hp1%str2!=0)
			time1++;
		if(hp2%str1!=0)
			time2++;
		time2*=(20-spd1);
		time1*=(20-spd2);
		
		
		if(time1>time2)
			cout<<"win"<<endl;
		else if(time1==time2)
			cout<<"tie"<<endl;
		else
			cout<<"lose"<<endl;
	}
}
