#include <bits/stdc++.h>
using namespace std;
//int fa[101],len[101];
struct sa
{
    int x;
    int y;
}data[1001];
struct se
{
    int fr;
    int to;
    double llen;
}date[100001];
/*
int find(int a)
{
    if(fa[a]!=a)
        fa[a]=find(fa[a]);
    return fa[a];
}
void merge(int a,int b)
{
    int x=find(a);
    int y=find(b);
    if(x!=y)
        fa[max(x,y)]=min(x,y);
}
*/
bool cmp(const se &a,const se &b)
{
    if((a.to)==(b.to))
        return (a.fr)<(b.fr);
    else
        return (a.to)<(b.to);
}
int main()
{
    //ios::sync_with_stdio(0);
    int n,m;
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
            scanf("%d%d",&data[i].x,&data[i].y);
        scanf("%d",&m);
        //for(int i=1;i<=n;i++)
        //    fa[i]=i,len[i]=0;
        for(int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            date[i].fr=min(x,y);
            date[i].to=max(x,y);
            date[i].llen=(double)sqrt(pow(abs(data[x].x-data[y].x),2)+pow(abs(data[x].y-data[y].y),2));
            //merge(x,y);
            //printf("       %d %d %lf\n",date[i].fr,date[i].to,date[i].llen);
        }
        sort(date+1,date+1+m,cmp);
        int a,b;
        scanf("%d%d",&a,&b);
        int t=0;
        double sum=0.0;
        int j=1;
        double MAX=1000000000.0;
        for(int i=j;i<=m;i++)
        {
            //printf("-------------\n");
            -----------------------------------------
            if(t==0&&date[i].fr!=a) continue;
            if(t!=0&&t!=date[i].fr)
            {
                if(i==m) {i=j+1;continue;}
                else continue;
            }
            -----------------------------------------
            if(date[i].fr==a) j=i;
            t=date[i].to;
            sum+=date[i].llen;
            //printf("%d\n",t);
            if(t==b)
            {
                MAX=min(MAX,sum);
                i=j;
                t=0;
                sum=0.0;
                continue;
            }
        }
        printf("%.2lf\n",MAX);
    }
    return 0;
}
