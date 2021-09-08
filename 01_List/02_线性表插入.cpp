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