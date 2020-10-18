/* SqList 
 * iclude Algorithm 2.3 2.4 2.5 2.6
 */


#ifndef SQLIST_H
#define SQLIST_H

#include <stdio.h>
#include <stdlib.h>

#include "../../Status/Status.h"


#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int ElemType;

/* SqList Data Structure */

typedef struct{
	ElemType * elem;
	int length;
	int listsize;
}SqList;


/* Algorithm 2.3 */

Status InitList(SqList * L);

Status DestroyList(SqList * L);

Status ClearList(SqList * L);

Status ListEmpty(SqList L);

int ListLength(SqList L);

Status GetElem(SqList L, int i, ElemType * e);

Status PriorElem(SqList L, ElemType cur_e, ElemType * pre_e);

Status NextElem(SqList L, ElemType cur_e, ElemType * next_e);

/* Visit is a function with ElemType value. */
void ListTraverse(SqList L, void (Visit)(ElemType));
/*Algorithm 2.4 */

Status ListInsert(SqList * L, int i, ElemType e);

/* Algorithm 2.4 */

Status ListDelete(SqList * L, int i, ElemType * e);

/* Algorithm 2.6 */

int LocateElem(SqList L, ElemType e, Status(Compare)(ElemType, ElemType));

#endif
