//
// Created by ASUS on 2021/11/15.
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
void append_insert(sequenlist*, int);
void Delete(sequenlist*, sequenlist*, sequenlist*);
int main(void)
{
    sequenlist*LA, *LB, *LC;
    printf("*************please input LA numbers end with -1: ***********************\n");
    LA = create();
    printf("********************** insert a num 12 to LA *******************************\n");
//    append_insert(LA, 4);
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
        append_insert(L, ch);
        scanf("%d", &ch);
    }
    return L;
}

void append_insert(sequenlist* L, int num)
{
    if(L->last == 0)
    {
        insert(L,num,0);
    }
    for (int i = 1; i <= L->last ; ++i) {
        if(L->data[i] <= num && L ->data[i+1] > num)
        {
            printf("\n location is %d ,left %d, right %d\n",i,L->data[i] , L->data[i+1]);
            insert(L, num,i);
            break;
        }
    }
}

void insert(sequenlist* L, int num,int place)
{

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

void Delete(sequenlist *LA, sequenlist *LB, sequenlist *LC)
{
    for(int i = 1;i<= LA-> last;i++)
    {
        int temp = LA->data[i];
        int flag = 0;
        for (int j = 1; j<=LB->last;j++)
        {
            if(temp == LB->data[j])
            {
                printf("deleting : %d \n",LA->data[i]);
                delete(LA,i);
                flag = 1;
                i--;
                break;
            }
        }
        if(flag == 1 )continue;
        else{
            for (int j = 1; j<=LC->last;j++)
            {
                if(temp == LC->data[j])
                {
                    printf("deleting : %d \n",LA->data[i]);
                    delete(LA,i);
//                    flag = 1;
                    i--;
                    break;
                }
            }
        }

    }


}/*SqList_Delete*/


//输出顺序表
void print(sequenlist*L)
{
    for (int i = 1; i <= L->last; i++)
        printf("%d ", L->data[i]);
    printf("\n");
}
