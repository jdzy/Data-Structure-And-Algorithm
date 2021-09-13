//数制转化
void Conversion() {
    int N,e;
    InitStack(S);
    cin>>N;
    while(N)
    {
        Push(S,N%8);
        N =N/8;
    }
    while(!StackEmpty(S))
    {
        Pop(S,e);
        cout<<e<<endl;
    }
}

//行编辑程序
void LineEdit()
{
    InitStack(S);
    ch=getchar();
    while(ch!=EOF)
    {
        while(ch!=EOF && ch!='\n')
        {
            switch (ch)
            {
            case '#': Pop(S,c);
                break;
            case '@': ClearStack(S);
                break;
            default: Push(S,ch);
                break;
            }
        }
        //从低到上调用数据的过程
        ClearStack(S);
        if(ch!=EOF) ch=getchar();
    }
    DestroyStack(S);
}