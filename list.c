//
// Created by ASUS on 2021/11/15.
//

#include <stdio.h>
#include<malloc.h>
typedef struct node
{
    int data;
    struct node *next;
}LinkList;/*��������ڵ�Ľṹ*/

LinkList* create();/*��������*/
void ListDelete(LinkList * La, LinkList * Lb, LinkList *Lc);
void Print(LinkList *);
void delete(LinkList *,int );
int main (void)
{/*���ܣ�����������A,B,C������ɾ��A�о���B��C�г��ֵ����ݡ�*/
    LinkList *headA, *headB, *headC;
    headA = create();/*��������*/
    headB = create();
    headC = create();
    printf("******************ɾ���ظ����֮ǰ��3�ű�ֱ���***************\n");
    Print(headA);/*�����ʾ��������*/
    Print(headB);
    Print(headC);
    ListDelete(headA, headB, headC);/*ɾ��A�����������Ľڵ�*/
    printf("********************ɾ���ظ����֮���LA��***********************\n");
    Print(headA);
    return 0;
}

void ListDelete(LinkList *La, LinkList *Lb, LinkList *Lc)
{/*���ܣ�ɾ��A�е��йؽ��*/
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
//    ͨ��ֵɾ�������еĽڵ�
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