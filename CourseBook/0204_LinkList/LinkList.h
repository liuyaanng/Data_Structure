/* Link List */



#ifndef LINKLIST_H
#define LINKLIST_H


#include "../../Status/Status.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElemType; 

// Link List structure with head node
typedef struct LNode{
	ElemType data;
	struct LNode * next;
}LNode, * LinkList;


// basic functions

Status InitList(LinkList * L);

Status DestroyList(LinkList * L);

Status ClearList(LinkList * L);

Status GetElem(LinkList L, int i, ElemType * e);

int LocateElem(LinkList L, ElemType e, Status(Compare)(ElemType, ElemType));

Status PriorElem(LinkList L, ElemType cur_e, ElemType * pre_e);

Status NextElem(LinkList L, ElemType cur_e, ElemType * next_e);

Status ListInsert(LinkList L, int i, ElemType e);

Status ListDelete(LinkList L, int i, ElemType * e);

void ListTraverse(LinkList L, void(Visit)(ElemType));

Status ListEmpty(LinkList L);

Status ListLength(LinkList L, int * len);

Status CreateList_Head(LinkList * L, int n, char * path);

Status CreateList_Tail(LinkList * L, int n, char * path);

#endif

