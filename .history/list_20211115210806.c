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
void delete(LinkList *,int );
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
    struct node * cur = Lb->next;
    while(1)
    {
        delete(La,cur->data);
        if(cur->next==NULL)break;
        cur = cur->next;
    }
    cur = Lc ->next;
    while(1)
    {
        delete(La,cur->data);
        if(cur->next==NULL)break;
        cur = cur->next;
    }

}
void delete(LinkList* L,int temp)
{
//    通过值删除链表中的节点
    struct node * cur = L;
    while(cur->next != NULL)
    {
        if(cur->next->data == temp)
        {
//            struct node * tt = cur->next;
            cur->next=cur->next->next;
//            tt = NULL;
        }
        cur = cur->next;
    }
}

struct node* make_node(int ch )
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = ch;
    temp->next =NULL;
    return temp;
};

LinkList* create()
{
    printf("making the list\n");
    LinkList* L;
    L = (LinkList*)malloc(sizeof(LinkList));
    L->data = 0;
    int ch;
    struct node * temp;
    struct node * cur;
    cur = L;
    scanf("%d", &ch);
    while (ch != -1)
    {
        temp = make_node(ch);
        cur -> next = temp;
        // temp = cur->next;
        cur = cur ->next;
        scanf("%d", &ch);
    }
//    L->data =NULL;

    return L;
}
void Print(LinkList *L)
{
//    printf("show the list\n");
    struct node *temp  = L->next;
    while(1)
    {
        printf("%d ",temp->data);
        if (temp->next == NULL)
            break;
        temp = temp->next;

    }
    printf("\n");
}