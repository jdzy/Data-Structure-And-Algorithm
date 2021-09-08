void MergeList_Sq(SqList La,SqList Lb,SqList &Lc) {
    int *pa=La.elem;
    int *pb=Lb.elem;
    Lc.listsize=Lc.length=La.length+Lb.length;
    int *pc=Lc.elem=(int *)malloc(Lc.listsize*sizeof(int));
    if(!Lc.elem) exit(OVERFLOW);

    int *La_last=La.elem+La.length-1;
    int *Lb_last=Lb.elem+Lb.length-1;

    while(pa<=La_last && pb<=Lb_last) {
        if(*pa<=*pb) *pc++=*pa++;
        else         *pc++=*pb++;
    }

    while(pa<=La_last) *pc++=*pa++;
    while(pb<=Lb_last) *pc++=*pb++;

}