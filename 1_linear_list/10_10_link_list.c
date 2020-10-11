#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define Bool int

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode, *Linklist;

void Init_no_head_node(Linklist L){
	L->next = NULL;
	printf("Init succeed!\n");
}


Linklist Init_with_head_node(Linklist L){
	L = (LNode *)malloc(sizeof(LNode));
	if(L==NULL){
		return false; 
	}
	L->next = NULL;
	printf("%p init", L->next);
	printf("Init succeed\n");
	return L;
}

Bool empty_1(Linklist L){
	if (L->next == NULL){
		return true;
	}
	else{
		return false;
	}
}

Linklist List_HeadInsert(Linklist L){
	LNode *s;
	int x;
	L = (LNode *)malloc(sizeof(LNode));
	L->next = NULL;
	printf("Please input data:\n");
	scanf("%d", &x);
	while(x!=9999){
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}
	return L;
};

Linklist List_TailInsert(Linklist L){
	L = (LNode *)malloc(sizeof(LNode));
	LNode *s,*r = L;
	int x;
	printf("input value:\n");
	scanf("%d", &x);
	while(x!=9999){
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d", &x);
	}
	r->next = NULL;
	return L;
}

LNode * Get_Elem(Linklist L, int i){
	if(i == 0){
		return L;
	}
	if(i < 1){
		return NULL;
	}
	int j = 1;
	LNode *p = L->next;
	while(p && j<i){
		p = p->next;
		j++;
	}
	return p;
}

LNode * LocateElem(Linklist L, int e){
	LNode *p = L->next;
	while(p && p->data != e){
		p = p->next;
	}
	return p;
}

void print_link_list(Linklist L){
	L = L->next; // head node
	while(L != NULL){
		printf("data %d\n", L->data);
		L = L->next;
	}
}
int main(){
	Linklist L;
	L = Init_with_head_node(L);
	/* Init_no_head_node(L); */
	/* L = List_HeadInsert(L); */
	L = List_TailInsert(L);
	int empty;
	empty = empty_1(L);
	printf(" is empty %d\n", empty);
	print_link_list(L);
	LNode * p = Get_Elem(L, 2);
	printf("the second elem address is:%p\n", p);
	printf("the second elem value is:%d\n", (*p).data);
	LNode * l = LocateElem(L, 20);
	printf("20 address is:%p\n", l);
	return 0;
}
