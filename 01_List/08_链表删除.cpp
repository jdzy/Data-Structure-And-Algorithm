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