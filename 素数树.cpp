#include <bits/stdc++.h>
using namespace std;
#define MAX (int)1e4
typedef long long LL;
LL su[MAX+1];
bool b[MAX+1];
int cnt=0;
int n;
int a[10001];
void init()
{
    LL i,j;
    memset(b,1,sizeof b);
    b[0]=b[1]=0;
    for(i=2;i<=MAX;i++)
    {
        if(b[i])
        {
            su[++cnt]=i;
            for(j=i*2;j<=MAX;j+=i)
                b[j]=0;
        }
    }
}
int isprime(int n)
{
    if(n<2) return 0;
    int i;
    for(i=1;su[i]<=sqrt(n);i++)
        if(n%su[i]==0) return 0;
    return 1;
}
int fa[10001];
int find(int a)
{
    if(fa[a]!=a)
        fa[a]=find(fa[a]);
    return fa[a];
}
void merge(int a,int b)
{
    int x=a;
    int y=b;
    if(find(x)!=find(y))
    {
        if(find(x)>find(y))
            swap(x,y);
        fa[find(y)]=find(x);
    }
}
int ba(int m)
{
    if(!isprime(a[m]))return 0;
    int t=fa[m];
    fa[m]=m;
    for(int i=1;i<=n;i++)
        if(find(i)==m)
    {
        if(!(isprime(a[i])&&a[i]<a[m]))
            return 0;
    }
    return 1;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        merge(x,y);
    }
    for(int i=1;i<=n;i++)
        printf("%d ",fa[i]);
    //printf("%d",fa[3]);
    //int sum=0;
    /*
    for(int i=1;i<=n;i++)
    {
        if(ba(i)) sum++;
    }
    printf("%d\n",sum);
    */
    return 0;
}
