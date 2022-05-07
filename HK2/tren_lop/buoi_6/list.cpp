// #############################################################################
// ###                       Copyright © K1ethoang                           ###
// #############################################################################
// ###           Name: Hoang Gia Kiet                                        ###
// ###           Code: 6251071049                                            ###
// ###           Class: CNTT - K62                                           ###
// ###           Tool: VSCode                                                ###
// ###           BM CNTT - DH GIAO THONG VAN TAI - PHAN HIEU TP.HCM          ###
// #############################################################################
// ###     Github: https://github.com/K1ethoang                              ###
// ###     Youtube: https://www.youtube.com/K1ethoang                        ###
// #############################################################################

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    Node *pNext;
} Node;

typedef struct List
{
    Node *pHead;
    Node *pTail;
} List;

void initList(List &list);                                // khởi tạo dslk
Node *createNode(int value);                              // tạo 1 node mới
void insertHead(List &list, Node *New);                   // thêm vào đầu
void insertTail(List &list, Node *New);                   // thêm vào cuối ds
void insertNodeRandomPos(List &list, Node *New, int pos); // thêm node p vào vị trí pos trong ds l
void removeNodeInHead(List &list);
void removeNodeInTail(List &list);
void removeNodeRandom(List &list, int pos);
void display(List list);

int main()
{
    List list;
    initList(list);
    Node *a = createNode(3);
    Node *b = createNode(1);
    Node *c = createNode(6);
    Node *d = createNode(10);
    insertTail(list, a);
    insertTail(list, b);
    insertTail(list, c);
    insertNodeRandomPos(list, d, 2);
    // 3 10 1 6
    // removeNodeInHead(list);
    // 10 1 6
    // removeNodeInTail(list);
    // 3 10 1
    removeNodeRandom(list, 2);
    // 3 1 6
    display(list);
    return 0;
}

void initList(List &list)
{
    list.pHead = NULL;
    list.pTail = NULL;
}

void insertHead(List &list, Node *New)
{
    // ds chưa có phần tử nào
    if (list.pHead == NULL)
        list.pHead = list.pTail = New;
    else
    {
        New->pNext = list.pHead;
        list.pHead = New; // cập nhật lại Head là node vừa thêm
    }
}

void insertTail(List &list, Node *New)
{
    // ds chưa có phần tử nào
    if (list.pHead == NULL)
        list.pHead = list.pTail = New;
    else
    {
        list.pTail->pNext = New;
        list.pTail = New; // cập nhật lại Tail là node vừa thêm
    }
}

Node *createNode(int value)
{
    Node *p = (Node *)malloc(sizeof(Node));
    if (p == NULL)
    {
        printf("\n\tKhong du bo nho de cap phat");
        return NULL;
    }
    else
    {
        p->data = value;
        p->pNext = NULL;
    }
    return p;
}

void removeNodeInHead(List &list)
{
    // ds không có phần tử nào
    if (list.pHead == NULL)
        return;
    else
    {
        Node *delPtr = list.pHead;
        list.pHead = list.pHead->pNext;
        free(delPtr);
    }
}

void removeNodeInTail(List &list)
{ // ds không có phần tử nào
    if (list.pHead == NULL)
        return;
    // có 1 node (nằm đầu)
    else if (list.pHead == list.pTail)
        removeNodeInHead(list);
    // node nằm ở cuối
    else
    {
        Node *ptr = list.pHead;
        while (ptr != NULL)
        {
            if (ptr->pNext == list.pTail)
            {
                free(list.pTail);
                ptr->pNext = NULL;
                list.pTail = ptr;
                break;
            }
            ptr = ptr->pNext;
        }
    }
}

void insertNodeRandomPos(List &list, Node *New, int pos) // thêm node p vào vị trí pos trong ds l
{
    // ds đang rỗng
    if (list.pHead == NULL || pos == 1)
        insertHead(list, New);
    else
    {
        int currentPos = 0;
        Node *ptr = (Node *)malloc(sizeof(Node));
        for (Node *t = list.pHead; t != NULL; t = t->pNext)
        {
            currentPos++;
            if (pos == currentPos)
            {
                Node *p = createNode(New->data);
                p->pNext = t;
                ptr->pNext = p;
                break;
            }
            ptr = t;
        }
    }
}

void removeNodeRandom(List &list, int pos)
{
    // nằm đầu
    if (pos == 1)
        removeNodeInHead(list);
    else
    {
        int currentPos = 0;
        Node *ptr = (Node *)malloc(sizeof(Node));
        for (Node *t = list.pHead; t != NULL; t = t->pNext)
        {
            currentPos++;
            if (pos == currentPos)
            {
                ptr->pNext = t->pNext;
                free(t);
                break;
            }
            ptr = t;
        }
    }
}

void display(List list)
{
    Node *ptr = list.pHead;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->pNext;
    }
}