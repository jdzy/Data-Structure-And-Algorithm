void MergeList_L(LinkList &La,LinkList &Lb,LinkList &Lc)
{
    //La、Lb非递减排列
    LinkList pa=La->next;
    LinkList pb=Lb->next;
    LinkList pc=Lc=La;
    while(pa && pb)
    {
        if(pa->data<=pb->data)
        {
            pc->next=pa;
            pc=pa;
            pc->data=pa->data;
        }
        else
        {
            pc->next=pb;
            pc=pb;
            pc->data=pb->data;
        }

        pc->next=pa? pa:pb;

        //free(Lb)   释放Lb头节点

    }
}