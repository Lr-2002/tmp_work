//
// Created by ASUS on 2021/11/15.
//

#include<stdio.h>
#include<malloc.h>
typedef int datatype;
#define maxsize 1024
typedef struct
{
    datatype data[maxsize];
    int last;
} sequenlist;
sequenlist* create();
void print(sequenlist*);
void delete(sequenlist*,int);
void Delete(sequenlist*, sequenlist*, sequenlist*);
int main(void)
{
    sequenlist*LA, *LB, *LC;
    printf("*************please input LA numbers end with -1: ***********************\n");
    LA = create();
    printf("*************please input LB numbers : ***********************\n");
    LB = create();
    printf("*************please input LC numbers : ***********************\n");
    LC = create();
    printf("******************ɾ��֮ǰ��3�ű�***********************\n");
    print(LA);
    print(LB);
    print(LC);
//    delete(LA , 1);
    Delete(LA, LB, LC);
    printf("***^*********ɾ����3�ű����ظ����ֽ��֮���A��******************\n");
    print(LA);

    return 0;
}

//����˳���
sequenlist* create()
{
    sequenlist* L;
    L = (sequenlist*)malloc(sizeof(sequenlist));
    L->last = 0;
    int ch;
    scanf("%d", &ch);
    while (ch != -1)
    {
        L->last++; //��1��Ԫ��ʼ���Ԫ��
        L->data[L->last] = ch;
        scanf("%d", &ch);
    }
    return L;
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


//���˳���
void print(sequenlist*L)
{
    for (int i = 1; i <= L->last; i++)
        printf("%d ", L->data[i]);
    printf("\n");
}
