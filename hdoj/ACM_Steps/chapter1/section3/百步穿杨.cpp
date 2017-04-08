#include<iostream>
#include<algorithm>
#include<stdio.h>
 #include<vector>
 using namespace std;
 
 struct Arr{
 	int length;
 	int num;
 };
 
 bool comparelength(const Arr &a,const Arr &b)
 {
 	return a.length<b.length;
 }
 
 int main()
 {
 	int n;
 	cin>>n;
 	while(n--)
 	{
 		int k;
 		vector<Arr> arrows;
 		cin>>k;
 		for(int j=0;j!=k;++j)
 		{
 			Arr tem;
 			cin>>tem.length>>tem.num;
 			arrows.push_back(tem);
 		}

 		sort(arrows.begin(),arrows.end(),comparelength);
 		
 		for(vector<Arr>::iterator beg=arrows.begin();beg!=arrows.end();++beg)
 		{
			for(int x=0;x!=beg->num;++x)
 			{
 				printf(">+");
 				for(int y=0;y!=(beg->length)-2;++y)
 				{
 					printf("-");
 				}
 				 printf("+>\n");
 			}
 			printf("\n");
 		}
 	}
 	return 0;
 }
