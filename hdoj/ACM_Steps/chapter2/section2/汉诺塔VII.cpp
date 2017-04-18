#include<iostream>
#include<cstdio>
using namespace std;

bool move(int n,int a[],int b[],int c[])
{
	if(c[0]==n)
		return false;
	else if(a[0]==n)
		return move(n-1,a+1,c,b);
	else if(b[0]==n)
		return move(n-1,c,b+1,a);
	return true;
}

int main()
{
	int T;
	cin>>T;
	while(T--){
		int a[66],b[66],c[66];
		int n,m,p,q;
		cin>>n;
		cin>>m;
		for(int i=0 ; i!=m ; ++i){
			cin>>a[i];
		}
		cin>>p;
		for(int i=0 ; i!=p ; ++i){
			cin>>b[i];
		}
		cin>>q;
		for(int i=0 ; i!=q ; ++i){
			cin>>c[i];
		}
		a[m]=b[p]=c[q]=-1;

		if(move(n,a,c,b)){
			cout<<"true"<<endl;
		}else{
			cout<<"false"<<endl;
		}
	}
	return 0;
}
