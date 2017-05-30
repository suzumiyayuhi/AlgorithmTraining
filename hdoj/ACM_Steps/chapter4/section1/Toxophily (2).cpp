#include<stdio.h>
#include<math.h>
#define pi acos(-1)
#define g 9.8
int main()
{
    int T;
    double x, y, v;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%lf%lf%lf", &x, &y, &v);
        double dd, x1, x2, a, b, c;
        a=g*x*x, b=-2*v*v*x, c=2*v*v*y+g*x*x;
        dd=b*b-4*a*c;
        if(dd<0)
            printf("-1\n");
        else
        {
            x1=atan((-1*b+sqrt(dd))/(2*a));
            x2=atan((-1*b-sqrt(dd))/(2*a));
            if((x1<0||x1>pi/2)&&(x2<0||x2>pi/2))
                printf("-1\n");
            else if(x1<0||x1>pi/2)
                printf("%.6lf\n", x2);
            else if(x2<0||x2>pi/2)
                printf("%.6lf\n", x1);
            else
                printf("%.6lf\n", x1>x2?x2:x1);
        }
    }
    return 0;
}
