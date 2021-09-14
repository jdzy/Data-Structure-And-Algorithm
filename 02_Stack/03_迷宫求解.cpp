#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct
{
    int x;
    int y;
}PosType;

typedef struct {
    int *base;
    int *top;
    int stacksize;
}SqStack;


#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define MAXLENGTH=30;
typedef int MazeType[MAXLENGTH][MAXLENGTH];

MazeType m;
int curstep=1;

typedef struct
{
    int ord;
    PosType seat;
    int  di;
}SElemType;

int InitStack(SqStack &S) {
    S.base=(int *)malloc(STACK_INIT_SIZE*sizeof(int));
    if(!S.base) exit(OVERFLOW);
    S.top=S.base;
    S.stacksize=STACK_INIT_SIZE;
   
    return OK;
}

//获取栈顶元素

int GetTop(SqStack S,int &e)
{
    if(S.top==S.base) return ERROR;

    e=*--S.top;
    return OK;
}

//在栈顶插入e

int Push(SqStack &S,int e)
{
    if(S.top-S.base>=S.stacksize)
    {
        S.base=(int *)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(int));
        if(!base) exit(OVERFLOW);

        S.top=S.base+S.stacksize;
        S.stacksize +=STACKINCREMENT;
    }

    *S.top++=e;

    return OK;
}

int Pop(SqStack &S,int &e)
{
    if(S.top==S.base)  return ERROR;
    e=*--S.top;
    return OK;
}

int Pass(PosType b)
{
    if(m[b.x][b.y]==1)   return OK;
    else return ERROR;
}

void FootPrint(PosType a)
{
    m[a.x][a.y]=curstep;
}

PosType NextPos(PosType c,int di)
{
    PosType direc[4]={{1,0},{0,1},{-1,0},{0,-1}};
    c.x+=direc[di].x;
    c.y+=direc[di].y;
    return c;
}

void MarkPrint(PosType b)
{
    m[b.x][b.y]=-1;
}

int MazePath(PosType start,PosType end)
{
    SqStack S;
    PosType curpos;
    SElemType e;
    InitStack(&S);
    curpos=start;
    
    do{
        if(Pass(curpos))
        {
            FootPrint(curpos);
            e.ord=curstep;
            e.seat.x=curpos.x;
            e.seat.y=curpos.y;
            e.di=0;
            Push(&S,&e);
            curstep++;
            if(curpos.x==end.x && curpos.y==end.y) return TRUE;
            curpos=NextPos(curpos,e.di);
        }
        else
        {
            if(!StackEmpty(S))
            {
                Pop(&S,e);
                curstep--;
                while(e.di==3&&!StackEmpty(S))
                {
                    MarkPrint(e.seat);
                    Pop(&S,e);
                    curstep--;
                }
                if(e.di<3)
                {
                    e.di++;
                    Push(&S,e);
                    curstep++;
                    curpos=NextPos(e.seat,e.di);
                }
             }
        }
    
    }while(!StackEmpty(S));
    return FALSE;
}

void Print(int x,int y)
{
    int i,j;
    for(int i=0;i<x;i++)
    {
        for(j=0;j<y;j++) printf("%3d",m[i][j]);
        printf("\n");
    }
}

void main()
{
    PosType begin,end;
    int i,j,x,y,x1,y1;
    printf("请输入行数、列数");
    cin>>x>>y;
    for(int i=0;i<x;i++)
    {
        m[0][i]=0;
        m[x-1]][i]=0;
    }
    for(j=1;j<y-1;j++)
    {
        m[j][0]=0;
        m[j][y-1]=0;
    }
    for(i=1;i<x-1;i++)
        for(j=1;j<y-1;j++)
            m[i][j]=1;
    printf("请输入迷宫内墙单元数 : ");
    cin>>j;
    printf("请输入每个单元的行数 : ");
    for(i=1;i<=j;i++)
    {
        cin>>x1>>y1;
        m[x1][y1]=0;
    }
    printf("迷宫结构如下:\n");
    Print(x,y);
    printf("请输入起点的行数、列数 ：");
    cin>>begin.x>>begin.y;
    printf("请输入终点的行数、列数 ：");
    cin>>end.x>>end.y;
    if(MazePath(begin,end))
    {
        printf("路径如下：");
        Print(x,y);
    }
    else
        printf("没有路径！！");
}