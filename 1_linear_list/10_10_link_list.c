#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define Bool int

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode, *LinkList;

typedef struct DNode{
	int data;
	struct DNode *prior, *next;
}DNode, *DLinkList;


void Init_no_head_node(LinkList L){
	L->next = NULL;
	printf("Init succeed!\n");
}

LinkList Init_with_head_node(LinkList L){
	L = (LNode *)malloc(sizeof(LNode));
	if(L==NULL){
		return false; 
	}
	L->next = NULL;
	printf("%p init", L->next);
	printf("Init succeed\n");
	return L;
}

Bool empty_1(LinkList L){
	if (L->next == NULL){
		return true;
	}
	else{
		return false;
	}
}

LinkList List_HeadInsert(LinkList L){
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
	//注意这里是建立链表，故即使传入初识地址也无法直接修改，必须需要返回值，链表建立完成后在进行操作则无需返回值
};

LinkList List_TailInsert(LinkList L){
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

LNode * Get_Elem(LinkList L, int i){
	//with head node
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

LNode * LocateElem(LinkList L, int e){
	LNode *p = L->next;
	while(p && p->data != e){
		p = p->next;
	}
	return p;
}

Bool InsertNextNode(LNode *p, int e){
	LNode *s = (LNode *)malloc(sizeof(LNode));
	if(s==NULL){ //malloc failed
		return false;
	}
	s->next = p->next;
	s->data = e;
	p->next = s;
	return true;
}

Bool InsertPriorNode(LNode *p, int e){
	LNode * s = (LNode *)malloc(sizeof(LNode));
	if(s==NULL){
		return false;
	}
	s->next = p->next;
	p->next = s;
	s->data = p->data;
	p->data = e;
	return true;
}
LinkList InsertElem(LinkList L, int i, int e){
	LNode *p = Get_Elem(L, i-1);
	InsertNextNode(p, e);
	InsertPriorNode(p, e);
	return L;
}

Bool DelateNextNode(LNode *p){
	LNode *q;
	q = p->next;
	p->next = q->next;
	free(q);
	return true;
}
LinkList DelateElem(LinkList L, int i){
	LNode *p = Get_Elem(L,i-1);
	DelateNextNode(p);
	return L;
}

int sizeof_linklist(LinkList L){
	L = L->next;
	int count = 0;
	while(L!=NULL){
		count++;
		L = L->next;
	}
	return count;
}

void print_link_list(LinkList L){
	L = L->next; // head node
	while(L != NULL){
		printf("data %d\n", L->data);
		L = L->next;
	}
}

LinkList Reverselinklist(LinkList L){
	LinkList S;
	S = (LNode *)malloc(sizeof(LNode));
	S->next = NULL;
	L = L->next;
	while(L!=NULL){
		LNode * s = (LNode *)malloc(sizeof(LNode));
		s->data = L->data;
		s->next = S->next;
		S->next = s;
		L = L->next;
	}
	return S;
}

// DLinkList
DLinkList InitDLinkList(DLinkList D){
	D = (DNode *)malloc(sizeof(DNode));
	if(D==NULL){
		return false;
	}
	D->next = NULL;
	D->prior = NULL;
	return D;
}

Bool InsertNextDNode(DNode * p, int e){
	DNode * s = (DNode *)malloc(sizeof(DNode));
	if(s==NULL){
		return false;
	}
	s->data = e;
	s->next = p->next;
	if(p->next != NULL){
		p->next->prior = s;
	}
	s->prior = p;
	p->next = s;
	return true;
}

Bool DelateNextDNode(DNode *p){
	DNode * q = p->next;
	p->next = q->next;
	if(p->next != NULL){
		q->next->prior = p;
	}
	free(q);
	return true;
}
DNode * GetDNodeELem(DLinkList D, int i){
	if(i==0){
		return D;
	}
	if(i<1){
		return NULL;
	}
	DNode * p = D->next;
	int j = 1;
	while(p && j < i){
		p = p->next;
		j++;
	}
	return p;
}
Bool DelateDNodeElem(DLinkList D, int i){
	DNode * p = GetDNodeELem(D, i-1);
	DelateNextDNode(p);
	return true;
}

Bool CreateDLinkList(DLinkList D){
	DNode *p = D;
	int x = 0;
	printf("input Dnode:\n");
	scanf("%d", &x);
	while(x!=9999){
		InsertNextDNode(p, x);
		printf("next\n");
		scanf("%d", &x);
		p = p->next;

	}
	return true;
}

Bool PrintDLinkList(DLinkList D){
	D = D->next;
	while(D!=NULL){
		printf("DNode is:%d\n", D->data);
		D = D->next;
	}
	return true;
}
void TestDLinkList(){
	DLinkList D;
	D = InitDLinkList(D);
	CreateDLinkList(D);
	PrintDLinkList(D);
	DelateDNodeElem(D, 3);
	PrintDLinkList(D);
}
void TestLinkList(){
	LinkList L;
	LinkList S;
	L = Init_with_head_node(L);
	/* Init_no_head_node(L); */
	/* L = List_HeadInsert(L); */
	L = List_TailInsert(L);
	print_link_list(L);
	S = Reverselinklist(L);
	print_link_list(S);
	/* int empty; */
	/* empty = empty_1(L); */
	/* printf(" is empty %d\n", empty); */
	/* print_link_list(L); */
	/* LNode * p = Get_Elem(L, 2); */
	/* printf("the second elem address is:%p\n", p); */
	/* printf("the second elem value is:%d\n", (*p).data); */
	/* #<{(| LNode * l = LocateElem(L, 20); |)}># */
	/* #<{(| printf("20 address is:%p\n", l); |)}># */
	/* InsertElem(L, 3, 100); */
	/* printf("insert\n"); */
	/* print_link_list(L); */
	/* DelateElem(L, 4); */
	/* print_link_list(L); */
	/* int count= 0; */
	/* count = sizeof_linklist(L); */
	/* printf("This link list is %d long\n", count); */
}

int main(){
	TestDLinkList();
	return 0;
}
