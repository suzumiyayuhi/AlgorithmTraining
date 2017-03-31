#include<iostream>
using namespace std; 
    int main()  
    {  
        int n,i,j,k,l;  
        int m;  
        cin>>n;  
        while(n--)  
        {  
            cin>>m;
            i=m%10;  
            j=i*i%10;  
            k=j*i%10;  
            l=k*i%10;  
            switch(m%4)  
            {  
                case 0:cout<<l<<endl;break;
                case 1:cout<<i<<endl;break;
                case 2:cout<<j<<endl;break;
                case 3:cout<<k<<endl;break;
            }  
        }  
        return 0;  
    }  
