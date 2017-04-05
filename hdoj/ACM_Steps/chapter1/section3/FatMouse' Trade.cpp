    #include <stdio.h>  
    #include <algorithm>  
    #include<iostream>
    #include <iomanip>
    using namespace std;  
      
    struct Node  
    {  
        double j,f,p;  
    } node[10000];  
      
    int cmp(Node x,Node y)  
    {  
        return x.p>y.p;  
    }  
      
    int main()  
    {  
        int m,n;  
        while(cin>>n>>m && (m!=-1 && n!=-1))  
        {  
            double sum = 0,max = 0;  
            int i,j;  
            for(i = 0; i<m; i++)  
            {  
              
                cin>>node[i].j>>node[i].f;
                node[i].p = node[i].j/node[i].f;  
            }  
            sort(node,node+m,cmp);  
            for(i = 0; i<m; i++)  
            {  
                if(n>node[i].f)  
                {  
                    sum+=node[i].j;  
                    n-=node[i].f;  
                }  
                else  
                {  
                    sum+=node[i].p*n;  
                    break;  
                }  
            }  
            printf("%.3lf\n",sum); 
        }  
      
        return 0;  
    }  
