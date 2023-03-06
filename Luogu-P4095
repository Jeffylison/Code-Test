#include <stdio.h>
#include <stdlib.h>

struct date
{
    int a;
    int b;
    int c;
    double x;
};
int main()
{
    struct date ba[100];
    int n,i,j,p,q,sum,m,t;
    double max,b[100];
    int a[100][2];
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d",&ba[i].a,&ba[i].b,&ba[i].c);
            b[i]=ba[i].x=(double)ba[i].b/(double)ba[i].a;
        }
        scanf("%d",&m);
        for(i=0;i<n;i++)
            for(j=0;j<2;j++)
                scanf("%d",&a[i][j]);
        for(i=0;i<n-1;i++)
            for(j=0;j<n-1-i;j++)
                if(b[j]<b[j+1])
                    t=b[j],b[j]=b[j+1],b[j+1]=t;
        for(i=0;i<n;i++)//请求循环
        {
            for(j=0;j<n;j++)
            {
                if(b[0]==ba[j].x) 
            }
        }
    }
    return 0;
}
