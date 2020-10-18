

#include "LinkList.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef MERGELINKLIST_H
#define MERGELINKLIST_H


/* Merge link list */

void MergeLinkList_1(LinkList A, LinkList B, LinkList * C, Status (compare)(ElemType, ElemType));
void MergeLinkList_2(LinkList A, LinkList B, LinkList * C, Status(compare)(ElemType, ElemType));

#endif
