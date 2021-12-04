//
// Created by ASUS on 2021/11/15.
// select
//

#include<stdio.h>
#include<malloc.h>
#include<string.h>
typedef int datatype;
#define maxsize 1024
typedef struct
{
    datatype data[maxsize];
    int last;
} sequenlist;
sequenlist* create();
void print(sequenlist*);
void insert(sequenlist*,int, int );
void delete(sequenlist*,int);
void select_insert(sequenlist*);
void append_insert(sequenlist*, int);
void Delete(sequenlist*, sequenlist*, sequenlist*);
int main(void)
{
    sequenlist*LA, *LB, *LC;
    printf("*************please input LA numbers end with -1: ***********************\n");
    LA = create();
    printf("********************** insert a num 12 to LA *******************************\n");
    print(LA);

    return 0;
}

//建立顺序表
sequenlist* create()
{
    sequenlist* L;
    L = (sequenlist*)malloc(sizeof(sequenlist));
    memset(L->data,0,sizeof(int));

    L->last = 0;
    int ch;
    scanf("%d", &ch);
    while (ch != -1)
    {
//        L->last++; //从1单元开始存放元素
//        L->data[L->last] = ch;
        insert(L, ch,L->last);
        scanf("%d", &ch);
    }
    select_insert(L);
    return L;
}


void select_insert(sequenlist* L)
{
    for (int i = 1; i <= L->last ; ++i) {
        int temp = 1000000;
        int loc = 10000;
        for (int j = i; j<= L->last ;++j) {
            if (L -> data[j] <= temp)
            {
                temp = L -> data[j];
                loc = j;
            }
        }
        delete(L,loc);
        insert(L,temp,i-1);
    }
}
void insert(sequenlist* L, int num,int place)
{

//    printf("\n appending : %d",num);
    for (int i = L->last+1; i >place; i--) {
        L->data[i] = L->data[i-1];
    }
    L->data[place+1] = num;
    L->last++;
}

void delete(sequenlist *L , int temp)
{
    for(int i = temp;i<L->last;i++)
    {
        L->data[i] = L->data[i+1];
    }
    L->last--;
}

//输出顺序表
void print(sequenlist*L)
{
    for (int i = 1; i <= L->last; i++)
        printf("%d ", L->data[i]);
    printf("\n");
}
