//
// Created by ASUS on 2021/11/15.
//

#include <stdio.h>
#include<malloc.h>
typedef struct node
{
    int data;
    struct node *next;
}LinkList;/*定义链表节点的结构*/

LinkList* create();/*函数声明*/
void ListDelete(LinkList * La, LinkList * Lb, LinkList *Lc);
void Print(LinkList *);

int main (void)
{/*功能：建立单链表A,B,C，并且删除A中均在B和C中出现的数据。*/
    LinkList *headA, *headB, *headC;
    headA = create();/*建立链表*/
    headB = create();
    headC = create();
    printf("******************删除重复结点之前的3张表分别是***************\n");
    Print(headA);/*输出显示链表数据*/
    Print(headB);
    Print(headC);
    ListDelete(headA, headB, headC);/*删除A中满足条件的节点*/
    printf("********************删除重复结点之后的LA表***********************\n");
    Print(headA);
    return 0;
}

void ListDelete(LinkList *La, LinkList *Lb, LinkList *Lc)
{/*功能：删除A中的有关结点*/




}

LinkList* create()
{
    printf("making the list\n");
    LinkList* L;
    L = (LinkList*)malloc(sizeof(LinkList));
    L->data = 0;
    int ch;
    scanf("%d", &ch);
    while (ch != -1)
    {
        struct node *temp;
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = ch;
        temp->next = L;
        L->next = temp;
        scanf("%d", &ch);
    }
    L->data = -1;

    return L;
}
void Print(LinkList *L)
{
    struct node *temp  = L;
    while(temp->data!=-1)
    {
        printf("processing the list\n%d \n ",temp->data);
        temp = temp->next;
    }
}