#include <iostream>
#include <stdlib.h>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef struct LNode {
    int data;
    struct LNode *next;
}LNode,*LinkList;

//逆位序创建一个链表
void CreateList_L(LinkList &L,int n) {
    //L=(LinkList)malloc(sizeof(LNode));
    //L->next=NULL;

    for(int i=n;i>0;--i) 
    {
        LinkList p=(LinkList)malloc(sizeof(LNode));
        cin>>p->data;
        p->next=L->next;
        L->next=p;
    }
}

int ListInsert_L(LinkList &L,int i,int e) 
{
    LinkList p=L;
    int j=0;
    while(p && j<i-1)
    {
        p=p->next;
        ++j;
    }
    if(!p || j>i-1) return ERROR;

    LinkList s=(LinkList)malloc(sizeof(LNode));
    s->next=p->next;
    s->data=e;
    p->next=s;

    return OK;

}

int GetElem_L(LinkList L,int i,int &e) 
{
    LinkList p=L->next;
    int j=1;
    while(p && j<i) 
    {
        p=p->next;
        ++j;
    }
    if(!p || j>i) return ERROR;

    e=p->data;

    return OK;
}

int ListDelete_L(LinkList &L,int i,int &e)
{
    LinkList p=L;
    int j=0;
    while(p && j<i-1)
    {
        p=p->next;
        ++j;
    }
    if(!p || j>i-1) return ERROR;

    LinkList q=p->next;
    p->next=q->next;
    e=q->data;
    free(q);

    return OK;
}

void MergeList_L(LinkList &La,LinkList &Lb,LinkList &Lc)
{
    //La、Lb非递减排列
    LinkList pa=La->next;
    LinkList pb=Lb->next;
    LinkList pc;
    Lc=pc=La;
    while(pa && pb)
    {
        if(pa->data<=pb->data)
        {
            pc->next=pa;
            pc=pa;
            pa=pa->next;
            //cout<<"This is a test  ------pa"<<endl;
        }
        else
        {
            pc->next=pb;
            pc=pb;
            pb=pb->next;
            //cout<<"This is a test  ------pb"<<endl;
        }

    }
    //cout<<"This is a test"<<endl;
    pc->next=pa?pa:pb;

     //free(Lb)   释放Lb头节点
}


//打印链表
void PrintList(LinkList &L) {
    LinkList p=L->next;
    while(p)
    {
        cout<<p->data;
        p=p->next;
    }
}

void Menu() {
    cout<<"1、链表插入"<<endl;
    cout<<"2、链表查询"<<endl;
    cout<<"3、链表删除"<<endl;
    cout<<"4、链表合并"<<endl;
    cout<<"5、链表打印"<<endl;
    cout<<"6、链表初始化赋值"<<endl;
    cout<<"0、退出"<<endl<<endl;
    cout<<"请选择你的操作！"<<endl;
}

int main() {
    int i,n,e,flag;

    //对La、Lb、Lc初始化，如果不提前初始化后面没法进行
    LinkList La=(LinkList)malloc(sizeof(LNode));
    LinkList Lb=(LinkList)malloc(sizeof(LNode));
    LinkList Lc=(LinkList)malloc(sizeof(LNode));
    La->next=Lb->next=Lc->next=NULL;

    while(true) {
        Menu();
        cin>>n;
        switch(n) {
            case 1:
            {
                cout<<"请输入想插入的链表，插入La输入1，插入Lb输入2 ：";
                cin>>flag;
                cout<<endl;
                cout<<"请依次插入位置以及插入数据，用空格隔开";
                cin>>i>>e;
                cout<<endl;
                if(flag==1)
                {
                    if(ListInsert_L(La,i,e)==OK) cout<<"La插入成功！！！"<<endl;
                    else cout<<"La插入失败！！！"<<endl;

                }
                if(flag==2)
                {
                    if(ListInsert_L(Lb,i,e)==OK) cout<<"Lb插入成功！！！"<<endl;
                    else cout<<"Lb插入失败！！！"<<endl;
                 }
            }
            break;

            case 2:
            {
                cout<<"请输入查询的线性表，La输入1，Lb输入2 ：";
                cin>>flag;
                cout<<endl;
                cout<<"请输入查询的位置 ：";
                cin>>i;
                cout<<endl;
                if(flag==1)
                {
                    if(GetElem_L(La,i,e)==OK) cout<<"La查询成功！！！查询的数据是 ："<< e <<endl;
                    else cout<<"La查询失败！！！"<<endl;

                }
                if(flag==2)
                {
                    if(GetElem_L(Lb,i,e)==OK) cout<<"Lb查询成功！！！查询的数据是 ："<< e <<endl;
                    else cout<<"Lb查询失败！！！"<<endl;
                 }

            }
            break;

            case 3:
            {
                cout<<"请输入想删除的线性表，La输入1，Lb输入2 ：";
                cin>>flag;
                cout<<endl;
                cout<<"请输入删除的位置 ：";
                cin>>i;
                cout<<endl;
                if(flag==1)
                {
                    if(ListDelete_L(La,i,e)==OK) cout<<"La删除成功！！！删除的数据是 ："<< e <<endl;
                    else cout<<"La删除失败！！！"<<endl;

                }
                if(flag==2)
                {
                    if(ListDelete_L(Lb,i,e)==OK) cout<<"Lb删除成功！！！删除的数据是 ："<< e <<endl;
                    else cout<<"Lb删除失败！！！"<<endl;
                 }

            }
            break;

            case 4:
            {
                MergeList_L(La,Lb,Lc);
                cout<<"La、Lb合并成功！！"<<endl;
             }
             break;

             case 5:
             {
                cout<<"链表La ：";
                PrintList(La);
                cout<<endl;
                cout<<"链表Lb ：";
                PrintList(Lb);
                cout<<endl;
                cout<<"链表Lc ：";
                PrintList(Lc);
                cout<<endl;
            }
            break;

            case 6:
            {
                cout<<"请输入想赋值的线性表，La输入1，Lb输入2 ：";
                cin>>flag;
                cout<<endl;
                cout<<"请输入赋值个数 ："<<endl;
                cin>>n;
                cout<<"请逆位次序输入"<<n<<"个数字！！ ： ";
                if(flag==1) CreateList_L(La,n);
                if(flag==2) CreateList_L(Lb,n);
                cout<<"赋值成功！！"<<endl;
            }
            break;

            case 0: exit(0);
            break;

            default:
                cout<<"输入数字错误！！"<<endl;
         }
    }

    return 0;

}