#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    string name,min_name;
    double Min,s;
    int min_v;
    int T,p,v,d,n;
    scanf("%d",&T);
    while (T--)
    {
        Min=99999;
        min_v=0;
        scanf("%d",&n);
        while(n--)
        {
            cin>>name>>p>>v;
            if (v<200)
                continue;
            if (v/200>=5)
                s=p/5;
            else
                s=p*1.0/(v/200);
            if(Min>s)
            {
                min_v=v;
                Min=s;
                min_name=name;
            }
            else if(Min==s)
            {
                if(min_v<v)
                {
                    min_v=v;
                    min_name=name;
                }
            }
        }
        cout<<min_name<<endl;
    }
    return 0;
}
