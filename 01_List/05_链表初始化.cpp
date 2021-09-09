//数据结构组织

typedef struct LNode {
    int data;
    struct LNode *next;
}LNode,*LinkList;

//逆位序创建一个链表
void CreateList_L(LinkList &L,int n) {
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;

    for(int i=n;i>0;--i) 
    {
        LinkList p=(LinkList)malloc(sizeof(LNode));
        cin>>p->data;
        p->next=L->next;
        L->next=p;
    }
}

