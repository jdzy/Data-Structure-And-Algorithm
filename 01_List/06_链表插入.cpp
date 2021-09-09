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

    s=(LinkList)malloc(sizeof(LNode));
    s->next=p->next;
    s->data=e;
    p->next=s;

    return OK;

}