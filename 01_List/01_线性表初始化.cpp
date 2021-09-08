//本系列代码均用int类型
//宏定义声明
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2


//线性表数据结构构造
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef struct {
    int *elem;  //基址
    int length;  //当前长度
    int listsize;  //分配的容量
}SqList;

//构造一个空线性表
int InitList_Sq(SqList &L) {
    L.elem=(int *)malloc(LIST_INIT_SIZE*sizeof(int));
    if(!L.elem) exit(OVERFLOW);
    L.length=0;
    L.listsize=LIST_INIT_SIZE;
    return OK;
}
