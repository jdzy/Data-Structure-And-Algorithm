typedef struct
{
    int x;
    int y;
}PosType;

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

int Pass(PosType b)
{
    if(m[b.x][b.y]==1)   return OK;
    else return ERROR;
}

void FootPrint(PosType a)
{
    m[a.x][a.y]=curstep;
}

PosType NextPos(Postype c,int di)
{
    Postype direc[4]={{1,0},{0,1},{-1,0},{0,-1}};
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













}