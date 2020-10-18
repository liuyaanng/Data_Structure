#include "LinkList.h"

void PrintfElem(ElemType e){
	printf("%d", e);
}


// basic functions

Status InitList(LinkList * L){
	(*L) = (LinkList)malloc(sizeof(LNode));
	if(*L == NULL){
		exit(OVERFLOW);
	}
	(*L)->next = NULL;
	return OK;
}

Status DestroyList(LinkList * L){
	LNode * p;

	if(L == NULL || *L == NULL){
		return ERROR;
	}

	p = *L;

	while(p != NULL){
		p = (*L)->next;
		free(*L);
		(*L) = p;
	}

	*L = NULL;
	return OK;
}

Status ClearList(LinkList * L){
	if(L == NULL || (*L)->next == NULL){
		return ERROR;
	}
	LNode * pre, *p;
	p = (*L)->next;
	while(p != NULL){
		pre = p;
		p = p->next;
		free(pre);
	}
	(*L)->next = NULL;
	return OK;
}

Status GetElem(LinkList L, int i, ElemType * e){
	if(L == NULL || L->next == NULL){
		return ERROR;
	}

	LNode * p = L->next;
	int j = 1;
	while(p && j < i){
		p = p->next;
		++j;
	}
	if(!p || j > i)return ERROR;
	*e = p->data;
	return OK;
}

int LocateElem(LinkList L, ElemType e, Status(Compare)(ElemType, ElemType)){
	LNode * p;
	int i;

	if(L == NULL || L->next == NULL){
		return 0;
	}

	p = L->next;
	while(p != NULL && !(Compare(L->data, e))){
		i++; 
		p = p->next;
	}

	if(p != NULL){
		return i;
	}
	else{
		return 0;
	}
}

Status PriorElem(LinkList L, ElemType cur_e, ElemType * pre_e){
	LNode * pre, * next;

	if(L == NULL || L->next == NULL){
		return ERROR;
	}

	pre = L->next;
	next = pre->next;
	while(next != NULL && next->data != cur_e){
		pre = next;
		next = next->next;
		}
	if(next == NULL){
		return ERROR;
	}
	
	*pre_e = pre->data;

	return OK;
}

Status NextElem(LinkList L, ElemType cur_e, ElemType * next_e){
	LNode * p;

	if(L == NULL || L->next == NULL){
		return ERROR;
	}

	p = L->next;
	while(p->next != NULL && p->data != cur_e){
		p = p->next;
	}

	if(p->next == NULL){
		return ERROR;
	}
	*next_e = p->next->data;

	return OK;

}

Status ListInsert(LinkList L, int i, ElemType e){
	LNode * S;
	LNode * p;
	int j;

	if(L == NULL){
		return ERROR;
	}
	
	p = L;
	j = 1;

	while(p != NULL && j < i){
		++j;
		p = p->next;
	}

	if(p == NULL || j > i){
		return ERROR;
	}

	S = (LNode *)malloc(sizeof(LNode));
	if(S == NULL){
		exit(OVERFLOW);
	}
	S->next = p->next;
	p->next = S;
	S->data = e;

	return OK;
}

Status ListDelete(LinkList L, int i, ElemType * e){
	LNode * p, * q;
	int j;

	if(L == NULL || L->next == NULL){
		return ERROR;
	}

	p = L;
	j = 1;
	while(p->next != NULL & j < i){
		j++;
		p = p->next;
	}

	if(p->next == NULL || j > i){
		return ERROR;
	}
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	
	return OK;
}

void ListTraverse(LinkList L, void(Visit)(ElemType)){
	LNode * p;

	if(L == NULL || L->next == NULL){
		return;
	}
	p = L->next;

	while(p != NULL){
		Visit(p->data);
		p = p->next;
	}

	printf("\n");
}

Status ListEmpty(LinkList L){
	if(L != NULL && L->next != NULL){
		return FALSE;
	}
	else{
		return TRUE;
	}
}

Status ListLength(LinkList L, int * len){
	LNode * p;
	if(L == NULL || L->next == NULL){
		return ERROR;
	}
	*len = 0;
	p = L->next;
	while(p != NULL){
		(*len)++;
		p = p->next;
	}
	return OK;
}

Status CreateList_Head(LinkList * L, int n, char * path){
	int i;
	LNode * S;
	FILE * fp;
	int readFromConsole;

	readFromConsole = path == NULL || strcmp(path, "") == 0;

	if(readFromConsole){
		// create head node 
		*L = (LinkList)malloc(sizeof(LNode));
		(*L)->next = NULL;

		printf("Please input %d elem:", n);
		for(i = 1; i <= n; i++){
			S = (LNode *)malloc(sizeof(LNode));

			scanf("%d", &(S->data));

			S->next = (*L)->next;
			(*L)->next = S;
		}
	}
	else{
		fp = fopen(path, "r");
		if(fp == NULL){
			return ERROR;
		}

		*L = (LinkList)malloc(sizeof(LNode));
		(*L)->next = NULL;

		for(i = 1; i < n; i++){
			S = (LNode *)malloc(sizeof(LNode));

			ReadData(fp, "%d", &(S->data));

			S->next = (*L)->next;
			(*L)->next = S;
		}
		fclose(fp);
		
	}
	return OK;
}

Status CreateList_Tail(LinkList * L, int n, char * path){
	int i;
	LNode * p, *S;
	FILE * fp;
	int readFromConsole;

	readFromConsole = path == NULL || strcmp(path, "") == 0;

	if(readFromConsole){
		InitList(L);

		p = *L;
		printf("Please input %d elems:", n);

		for(i = 1; i <= n; i++){
			S = (LNode *)malloc(sizeof(LNode));
			scanf("%d", &(S->data));

			S->next = p->next;
			p->next = S;
			p = S;
		}
	}
	else{
		fp = fopen(path, "r");
		if(fp == NULL){
			return ERROR;
		}
		
		InitList(L);

		p = *L;
		
		for(i = 1; i <= n; i++){
			S = (LinkList)malloc(sizeof(LNode));

			ReadData(fp, "%d", &(S->data));

			S->next = p->next;
			p->next = S;
			p = S;
		}
	}
	return OK;
}


