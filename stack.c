//
// Created by ASUS on 2021/11/15.
//

#include<stdio.h>
#include<malloc.h>
#define maxsize 1024
typedef char datatype;
typedef  struct stack
{
    datatype data[maxsize];
    int Top;
    int length;
} seqstack;

seqstack * Initstack();
void Delete(seqstack *, datatype);
void Push(seqstack *, datatype);
datatype Pop(seqstack *);
int EmptyS(seqstack *s);
void Print(seqstack * s);
int main (void)
{
    seqstack *s;
    datatype m;
    printf("***********************������m: ***********************\n");
    scanf("%c", &m);
    printf("***********************���ʼ��ջs: ***********************\n");
    s = Initstack();
    printf("***********************���ջs: ***********************\n");
    Print(s);
    Delete(s, m);//����ɾ������
//    Pop(s);
    printf("\n********************���ɾ��m֮���ջs: ***********************\n");
    Print(s);
    return 0;

}

void Delete(seqstack *s,datatype m)
{
    seqstack *tmp;
    tmp = (seqstack * )malloc(sizeof(seqstack *));
    tmp->length=0;
    while(s->length != 0)
    {
        datatype ch = Pop(s);
        if(ch == m)
        {
            continue;
        }
        else{
            Push(tmp , ch );
        }
    }
    while(tmp->length != 0)
    {
        datatype ch = Pop(tmp);
        Push(s,ch);
    }




}
seqstack* Initstack ( )
{
    seqstack *s;
    s = (seqstack * )malloc(sizeof(seqstack *));

    datatype ch ;
    s->length = 0;
    scanf("%c",&ch );
    while(ch!='q')
    {
        Push(s,ch);
        scanf("%c",&ch);
    }
    return s;


}
void Push(seqstack *s, datatype e)
{
    s->data[++s->length] = e;
    s->Top = e;
}

int EmptyS(seqstack *s)
{
    while(s->length!=0)
    {
        Pop(s);
    }
    return 1;

}


datatype Pop(seqstack *s)
{
//    s->length --;
    datatype tmp = s->data[s->length];
    s->Top = s->data[--s->length];
    return tmp;

}

void Print(seqstack*s)
{
//    printf("printing the stack\n");
    for(int i=s->length;i>=1;i--)
    {
        printf("%c ",s->data[i]);
    }
    printf("\n");
}
