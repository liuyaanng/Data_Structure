#include <stdio.h>
#include <stdlib.h>

#define Max_size 10
#define true 1
#define false 0
typedef struct SqList{
	int data[Max_size];
	int length;
}Sq;


void InitList(Sq *L)
{
	for(int i=0;i<Max_size;i++){
		L->data[i]=0;
	}
	L->length=0;
}

int Length(Sq L){
	return L.length;
}

void Add_Elem(Sq *L, int value){
	if (L->length < Max_size){
		L->data[L->length] = value;
		L->length += 1;
	}
	else{
		printf("error array size");
	}
}
int LocateElem(Sq L, int value){
	for(int i=0;i<L.length;i++){
		if (L.data[i]==value){
			return i;
		}
	}
}


int GetElem(Sq L, int id){
	return L.data[id-1];
}

int GetIndex(Sq L, int value){
	for(int i=0; i<L.length;i++){
		if(value == L.data[i]){
			return i+1;
		}
	}
	printf("no this value\n");

}
int is_work(int length, int id){
	if (id<1 || id>length){
		return false;
	}
	else if (length>Max_size){
		return false;
	} 	
	else{
		return true;
	}
}

void ListInsert(Sq *L, int id, int value){
	if (is_work(L->length, id)){
		for (int j=L->length;j<id;j--){
			L->data[j] = L->data[j-1];
		}
		L->data[id-1] = value;
		L->length += 1;
	}
}

int main(){
	Sq sqlist;
	InitList(&sqlist);
	
	for(int i=0;i<5;i++){
		Add_Elem(&sqlist, i);
	}

	ListInsert(&sqlist, 2, 10);
	for(int i=0;i<sqlist.length;i++){
		printf("%d\n",sqlist.data[i]);
	}
	/* int length = Length(&sqlist); */
	/* int Elem = GetElem(sqlist, 3); */
	/* int Index = GetIndex(sqlist, 10); */
	/* printf("Length is %d\n", length); */
	/* printf("3 Elem is %d,10 Index is %d\n", Elem, Index); */
	/* printf("%d\n", sqlist.length); */
	return 0;
}
