#include "MergeLinkList.h"
/* Merge link list */

void MergeLinkList_1(LinkList A, LinkList B, LinkList * C, Status(compare)(ElemType, ElemType)){
	InitList(C);
	int i = 0;
	LNode *pa, *pb;

	pa = A->next;
	pb = B->next;

	while(pa && pb){
		if(compare(pa->data, pb->data)){
			ListInsert(*C, ++i, pb->data);
			pb = pb->next;
		}
		else{
			ListInsert(*C, ++i, pa->data);
			pa = pa->next;
		}
	}

	while(pa == NULL){
		ListInsert(*C, ++i, pb->data);
		pb = pb->next;
		return;
	}

	while(pb == NULL){
		ListInsert(*C, ++i, pa->data);
		pa = pa->next;
		return;
	}
}


void MergeLinkList_2(LinkList A, LinkList B, LinkList * C, Status(compare)(ElemType, ElemType)){
	LNode *pa, *pb, *pc;

	*C = A;
	InitList(C);

	pa = A->next;
	pb = B->next;

	pc = (*C);

	while(pa && pb){
		if(compare(pa->data, pb->data)){
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
		else{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
	}

	pc->next = pa ? pa : pb;

	free(B);

	A = NULL;
	B = NULL;

}
