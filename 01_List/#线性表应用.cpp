#include <iostream>
#include <stdlib.h>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef struct {
    int *elem;  //基址
    int length;  //当前长度
    int listsize;  //分配的容量
}SqList;

int InitList_Sq(SqList &L) {
    L.elem=(int *)malloc(LIST_INIT_SIZE*sizeof(int));
    if(!L.elem) exit(OVERFLOW);
    L.length=0;
    L.listsize=LIST_INIT_SIZE;
    return OK;
}

int ListInsert_Sq(SqList &L,int i,int e) {
    //在第i个元素之前插入
    if(i<1 || i>L.length+1) return ERROR;
    if(L.length>=L.listsize) {
        int *newbase=(int *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(int));
        if(!newbase) exit(OVERFLOW);
        L.elem=newbase;
        L.listsize +=LISTINCREMENT;
    }    
    int *q=&(L.elem[i-1]);
    
    for(int *p=&(L.elem[L.length-1]);p>=q;p--)  *(p+1)=*p;
    *q=e;
    ++L.listsize;
    
    return OK;
}

int ListDelete_Sq(SqList &L,int i,int &e) {
    if(i<1 || i>L.length-1) return ERROR;

    int *p=&(L.elem[i-1]);
    int *q=L.elem+L.length-1;
    e=*p; //传出被删除的元素

    for(++p;p<=q;++p) *(p-1)=*p;
    --L.length;

    return OK;
}

void MergeList_Sq(SqList La,SqList Lb,SqList &Lc) {
    int *pa=La.elem;
    int *pb=Lb.elem;
    Lc.listsize=Lc.length=La.length+Lb.length;
    int *pc=Lc.elem=(int *)malloc(Lc.listsize*sizeof(int));
    if(!Lc.elem) exit(OVERFLOW);

    int *La_last=La.elem+La.length-1;
    int *Lb_last=Lb.elem+Lb.length-1;

    while(pa<=La_last && pb<=Lb_last) {
        if(*pa<=*pb) *pc++=*pa++;
        else         *pc++=*pb++;
    }

    while(pa<=La_last) *pc++=*pa++;
    while(pb<=Lb_last) *pc++=*pb++;

}

void InputList(SqList &L,int n) {
    cout<<"请依次输入数 ：";
    for(int i=0;i<n;i++)
    {
        cin>>L.elem[i];
        ++L.length;
    }
}

void PrintList(SqList &L) {
    for(int i=0;i<L.length;i++)
    {
        cout<<L.elem[i]<<" ";
    }
}

void Menu() {
    cout<<"1、线性表初始化"<<endl;
    cout<<"2、线性表插入"<<endl;
    cout<<"3、线性表删除"<<endl;
    cout<<"4、线性表合并"<<endl;
    cout<<"5、线性表打印"<<endl;
    cout<<"6、线性表赋值"<<endl;
    cout<<"0、退出"<<endl<<endl;
    cout<<"请选择你的操作！"<<endl;
}

int main() {
    int i,n,e,flag;
    SqList La,Lb,Lc;

    while(true) {
        Menu();
        cin>>n;
        switch(n) {
            case 1:
            {
                InitList_Sq(La);
                InitList_Sq(Lb);
                InitList_Sq(Lc);
                cout<<"线性表均以初始化完毕！"<<endl;
            }
             break;

            case 2:
            {
                cout<<"请输入想插入的线性表，插入La输入1，插入Lb输入2 ：";
                cin>>flag;
                cout<<endl;
                cout<<"请依次插入位置以及插入数据，用空格隔开";
                cin>>i>>e;
                cout<<endl;
                if(flag==1)
                {
                    if(ListInsert_Sq(La,i,e)==OK) cout<<"La插入成功！！！"<<endl;
                    else cout<<"La插入失败！！！"<<endl;

                }
                if(flag==2)
                {
                    if(ListInsert_Sq(Lb,i,e)==OK) cout<<"Lb插入成功！！！"<<endl;
                    else cout<<"Lb插入失败！！！"<<endl;
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
                    if(ListDelete_Sq(La,i,e)==OK) cout<<"La删除成功！！！删除的数据是 ："<< e <<endl;
                    else cout<<"La删除失败！！！"<<endl;

                }
                if(flag==2)
                {
                    if(ListDelete_Sq(Lb,i,e)==OK) cout<<"Lb删除成功！！！删除的数据是 ："<< e <<endl;
                    else cout<<"Lb删除失败！！！"<<endl;
                 }

            }
            break;

            case 4:
            {
                MergeList_Sq(La,Lb,Lc);
                cout<<"La、Lb合并成功！！"<<endl;
             }
             break;

             case 5:
             {
                cout<<"线性表La ：";
                PrintList(La);
                cout<<endl;
                cout<<"线性表Lb ：";
                PrintList(Lb);
                cout<<endl;
                cout<<"线性表Lc ：";
                PrintList(Lc);
                cout<<endl;
            }
            break;

            case 6:
            {
                cout<<"请输入想赋值的线性表，La输入1，Lb输入2 ：";
                cin>>flag;
                cout<<endl;
                cout<<"请输入赋值个数 ：";
                cin>>n;
                cout<<endl;
                if(flag==1) InputList(La,n);
                if(flag==2) InputList(Lb,n);
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