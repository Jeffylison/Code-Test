#include <bits/stdc++.h>
using namespace std;
struct date
{
    int no[7];
    char name[20];
    char sex;
    double score[2];
    double x;
    double sum;
};
int main()
{
    //FILE *fp=fopen("C:\\asd\\student.txt","w");
    ofstream fout;
    fout.open("C:\\asd\\students.txt");
    struct date ba[5];
    int i,j,n,m,t=0;
    //char a[100];
    cin>>n;
    cin.ignore();
    //ba=(struct date *)malloc(sizeof(struct date)*n);
    for(i=0;i<n;i++)
    {
        t=0;
        for(j=0;j<8;j++)
        {cin>>ba[i].no[j];
        fout<<ba[i].no[j];}
        cin.ignore(1,' ');
        for(j=0;j<20;j++)
        {
            cin>>ba[i].name[j];
            if(ba[i].name[j]==' '&&t==0) t=1;
            else if(ba[i].name[j]==' '&&t==1) break;
            fout<<ba[i].name[j];
        }
        m=strlen(ba[i].name);
        fout<<m;
        cin.ignore(1,' ');
        cin>>ba[i].sex;
        fout<<ba[i].sex;
        cin.ignore(1,' ');
        cin>>ba[i].score[0]>>ba[i].score[1]>>ba[i].score[2];
        ba[i].x=(ba[i].score[0]+ba[i].score[1]+ba[i].score[2])/3;
        ba[i].sum=ba[i].score[0]+ba[i].score[1]+ba[i].score[2];
        fout<<ba[i].score[0]<<ba[i].score[1]<<ba[i].score[2]<<ba[i].x<<ba[i].sum<<endl;
        cin.ignore(1024,'\n');
    }
        fout.close();
    return 0;
}
