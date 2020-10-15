#include "SqList.h"
#include <stdio.h>


// Test functions

void PrintElem(ElemType e){
	printf("%d ", e);
}

// data>e
Status CmpGreater(ElemType data, ElemType e) {
    return data > e ? TRUE : FALSE;
}




int main(){

	SqList L;

	int i;
	ElemType e;

	printf(" Init List \n");
	{
		printf("  init list L...\n");
		InitList(&L);
	}
	PressEnterToContinue(debug);
	
	printf("ListEmpty\n");
	{
		if(ListEmpty(L) == OK){
			printf("list is empty...\n");
		}
		else{
			printf("list is not empty...\n");
		}
	}
	PressEnterToContinue(debug);

	printf("ListInsert\n");
	{
		for(i = 1; i < 10; i++){
			printf("insert %d in %d ...\n", 3*i, i);
			ListInsert(&L, i, 3*i);
		}
	}
	PressEnterToContinue(debug);

	printf("ListTraverse\n");
	{
		printf("This list is: \n");
		ListTraverse(L, PrintElem);
	}
	PressEnterToContinue(debug);

	printf("ListLength\n");
	{
		printf("list length is: %d", ListLength(L));
	}
	PressEnterToContinue(debug);

	printf("ListDelate\n");
	{
		i = 6;
		printf("Before delete, this list is: ");
		ListTraverse(L, PrintElem);
		printf("Delete the %d elem\n", i);
		if(ListDelete(&L, i, &e)){
			printf("Delete success! the elem is %d\n", e);
		}
		else{
			printf("the %d elem is not exist!\n", i);
		}
		printf("After delete, this list is: ");
		ListTraverse(L, PrintElem);
	}

	printf("GetElem\n");
	{
		GetElem(L, 8, &e);
		printf("the 8 elem is: %d\n", e);
	}
	PressEnterToContinue(debug);

	printf("LocateElem \n");
	{
			i = LocateElem(L, 7, CmpGreater);
			printf("The first elem which > 7 is \"%d\" \n", L.elem[i - 1]);
	}
	PressEnterToContinue(debug);
	
	
	printf("PriorElem \n");
	{
			ElemType cur_e = 6;
			if(PriorElem(L, cur_e, &e)) {
					printf("the prior of \"%d\" is \"%d\" \n", cur_e, e);
			} else {
					printf("the priot of \"%d\" is not exist！\n", cur_e);
			}
	}
	PressEnterToContinue(debug);
	
	printf("NextElem \n");
	{
			ElemType cur_e = 6;
			
			if(NextElem(L, cur_e, &e) == OK) {
					printf("the next elem of \"%d\" is \"%d\" \n", cur_e, e);
			} else {
					printf("the next elem of  \"%d\" is not exist！\n", cur_e);
			}
	}
	PressEnterToContinue(debug);
	
	
	printf("ClearList \n");
	{
			printf("before clear list：");
			if(ListEmpty(L)) {
					printf(" List is empty！！\n");
			} else {
					printf(" List is not empty！\n");
			}
			
			ClearList(&L);
			
			printf("after clear list：");
			if(ListEmpty(L)) {
					printf(" List is empty！！\n");
			} else {
					printf(" List is not empty！\n");
			}
	}
	PressEnterToContinue(debug);
	
	
	printf("DestroyList \n");
	{
			printf("before destory list：");
			if(L.elem != NULL) {
					printf(" List is exist！\n");
			} else {
					printf(" List is not exist！！\n");
			}
			
			DestroyList(&L);
			
			printf("afte destory list：");
			if(L.elem != NULL) {
					printf(" List is exist！\n");
			} else {
					printf(" List is not exist！\n");
			}
	}
	PressEnterToContinue(debug);
    
    

	return 0;
}
