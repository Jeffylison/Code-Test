#include <bits/stdc++.h>
using namespace std;
typedef struct node
{
    char no[8];
    char name1[20];
    char name2[20];
    char sex;
    double score[3];
    double scorem;
    double scoren;
    struct node *next;
}NODE;
  //自定义结构体交换
  void swap(Node *a, Node *b)  //指定排序的节点
  {
          Node t = *a;
          *a = *b;
          *b = t;
  }
  //快排递归实现
  void QuickSort(ElemType *elem, int left, int right) //注意这里是闭区间
  {
      if(left < right)
      {
          int temp = elem[right].scorem;  //这里要指定是按age排序的
          int i = left-1;
          int j = left;
          while(j < right)
          {
             if(elem[j].scorem <= temp)   //这里也要指定 <= 可以用<带换
             {
                ++i;
                swap(&elem[i], &elem[j]);
             }
             j++;
          }
          swap(&elem[i+1], &elem[right]);
          int r = i+1;
          QuickSort(elem, left, r-1);
          QuickSort(elem, r+1, right);
      }
  }
int main()
{
    NODE *phead,*pnew,*ptail;
    phead=(NODE *)malloc(sizeof(NODE));
    if(phead==NULL) exit(1);
    phead->next=NULL;
    ptail=phead;
    ofstream fout;
    fout.open("C:\\asd\\student.dat");
    int n,i,j;
    cin>>n;
    for(i=0;i<n;i++)
    {
        pnew=(NODE *)malloc(sizeof(NODE));
        if(pnew==NULL) exit(1);
        cin>>pnew->no;
        cin>>pnew->name1>>pnew->name2;
        if(strlen(pnew->name2)==1&&(pnew->name2[0]=='F'||pnew->name2[0]=='M')){pnew->sex=pnew->name2[0];}
        else cin>>pnew->sex;
        cin>>pnew->score[0]>>pnew->score[1]>>pnew->score[2];
        pnew->scorem=pnew->score[0]+pnew->score[1]+pnew->score[2];
        pnew->scoren=pnew->scorem/3.0;
        pnew->next=NULL;
        ptail->next=pnew;
        ptail=pnew;
    }
    //phead=phead->next;
    /*while(phead)
    {
        cout<<phead->no<<" "<<phead->name1<<" ";
        if(strlen(phead->name2)==1&&(phead->name2[0]=='F'||phead->name2[0]=='M')) cout<<phead->sex<<" ";
        else cout<<phead->name2<<" "<<phead->sex<<" ";
        cout<<phead->score[0]<<" "<<phead->score[1]<<" "<<phead->score[2]<<" "<<phead->scorem<<" "<<phead->scoren<<endl;
        phead=phead->next;
    }*/
    NODE *pcp1,*pcp2,*pcp11,*pcp22,*pcp;
    pcp1=pcp2=phead->next;
    pcp11=pcp22=phead;
    int max=pcp1->scorem;
    while(pcp1)
    {
        if(max<pcp1->scorem)
            {max=pcp1->scorem;pcp=pcp1;}
        pcp1=pcp1->next;pcp=pcp->next;//3 1 2 3 4 5 6 3
    }
     pcp1->next=pcp2->next;pcp
    fout.close();
    return 0;
}

