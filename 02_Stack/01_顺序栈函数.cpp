//初始声明以及初始化函数

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef struct {
    int *base;
    int *top;
    int stacksize;
}SqStack;

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

    }
}