int ListDelete_Sq(SqList &L,int i,int &e) {
    if(i<1 || i>L.length-1) return ERROR;

    int *p=&(L.elem[i-1]);
    int *q=L.elem+L.length-1;
    e=*p; //传出被删除的元素

    for(++p;p<=q;++p) *(p-1)=*p;
    --L.length;

    return OK;
}