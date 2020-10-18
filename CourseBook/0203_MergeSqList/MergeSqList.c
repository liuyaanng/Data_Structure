#include "MergeSqList.h"



void MergeList(SqList La, SqList Lb, SqList * Lc){
	InitList(Lc);
	int La_len, Lb_len, i, j, k;
	ElemType ai, bj;

	i = j = 1;
	k = 0;

	La_len = ListLength(La);
	Lb_len = ListLength(Lb);

	while(i <= La_len && j <= Lb_len){
		GetElem(La, i, &ai);
		GetElem(Lb, j, &bj);
		

		if(ai >= bj){
			ListInsert(Lc, ++k, bj);
			j++;
		}
		else{
			ListInsert(Lc, ++k, ai);
			i++;
		}
	}
	

	while(i <= La_len){
		GetElem(La, i++, &ai);
		ListInsert(Lc, ++k, ai);
	}

	while(j <= Lb_len){
		GetElem(Lb, j++, &bj);
		ListInsert(Lc, ++k, bj);
	}
}
