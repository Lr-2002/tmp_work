//
// Created by ASUS on 2021/11/15.
//

#include <stdio.h>
#include<malloc.h>
typedef struct node
{
    int data;
    struct node *next;
}LinkList;/*���������ڵ�Ľṹ*/

LinkList* create();/*��������*/
void ListDelete(LinkList * La, LinkList * Lb, LinkList *Lc);
void Print(LinkList *);

int main (void)
{/*���ܣ�����������A,B,C������ɾ��A�о���B��C�г��ֵ����ݡ�*/
    LinkList *headA, *headB, *headC;
    headA = create();/*��������*/
//    headB = create();
//    headC = create();
    printf("******************ɾ���ظ����֮ǰ��3�ű��ֱ���***************\n");
    Print(headA);/*�����ʾ��������*/
//    Print(headB);
//    Print(headC);
//    ListDelete(headA, headB, headC);/*ɾ��A�����������Ľڵ�*/
    printf("********************ɾ���ظ����֮���LA��***********************\n");
    Print(headA);
    return 0;
}

void ListDelete(LinkList *La, LinkList *Lb, LinkList *Lc)
{/*���ܣ�ɾ��A�е��йؽ��*/




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
    L->data =NULL;

    return L;
}
void Print(LinkList *L)
{
    struct node *temp  = L->next;
    while(temp->data!=-1)
    {
        printf("processing the list\n%d \n ",temp->data);
        temp = temp->next;
    }
}