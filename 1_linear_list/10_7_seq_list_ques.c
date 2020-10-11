#include <stdio.h>
#include <stdlib.h>
#include "/Users/kevin/Github/Myrep/Data_Structure/1_linear_list/10_4_seq_list.c"

//q1
int Del_lowest(Sq *L){
	if(L->length == 0){
		printf("empty array");
		return 0;
	}
	int lowest = L->data[0];
	int index = 0;
	for(int i=1;i<L->length;i++){
		if(L->data[i]<lowest){
			lowest = L->data[index];
		} 
	}
	L->data[index] = L->data[L->length-1];
	return lowest;
}
//q2
int reverse_list(Sq *L, int left, int right){
	if(left > right || left < 0 || right > L->length){
		return 0;
	}
	int temp = 0;
	int mid = (left+right)/2;
	for(int i=0;i<=mid - left;i++){
		temp = L->data[left+i];
		L->data[left+i] = L->data[right-i];
		L->data[right-i] = temp;
	}
	return true;
}
//q3
void Del_value_x_1(Sq *L, int value){
	int count=0;      //not equal value number.
	for(int i=0;i<L->length;i++){
		if(L->data[i]!=value){
			L->data[count]=L->data[i];
			count+=1;
		}
	}
	L->length = count;
}

void Del_value_x_2(Sq *L, int value){
	int count = 0, i = 0;
	while(i<L->length){
		if (L->data[i] == value){
			count++;
		}
		else{
			L->data[i-count] = L->data[i];
		}
		i++;
	}
	L->length = L->length - count;
}
//q4
void Del_value_a_to_b_1(Sq *L, int a , int b){
	//with sequence
	if(Empty(*L) || a>b){
		printf("error");
	}
	else{
		int i,j=0;
		for(i;i<L->length && L->data[i]<a;i++);
		if (i>=L->length){
			printf("This List is suitable");
		}
		for(j = i; j<L->length && L->data[j]<b;j++);
		for(i,j;j<L->length;i++,j++){
			L->data[i+1]=L->data[j];
		}
		L->length = i+1;
	}
}

//q5
void Del_value_a_to_b_2(Sq *L, int a, int b){
	// no sequence
	if(Empty(*L) || a>b){
		printf("error");
	}
	else{
		int count = 0;
		for(int i=0;i<L->length;i++){
			if(L->data[i]>a & L->data[i]<b){
				count++;
			}
			else{
				L->data[i - count] = L->data[i];
			}
		}
		L->length = L->length - count;
	}
}
//q6
void Del_same_value(Sq *L){
	if (Empty(*L)){
		printf("empty list");
	}
	else{
		int i,j;
		for(i=0,j=1;j<L->length;j++){
			if(L->data[i]!=L->data[j]){
				L->data[++i]=L->data[j];
			}
		}
		L->length=i+1;
	}
}
//q7
int two_to_one(Sq *A, Sq *B, Sq *C){
	//sequence list
	if(A->length + B->length > Max_size){
		return false;
	}
	int i,j,k;
	i=j=k=0;
	while(i<A->length && j<B->length){
		if(A->data[i]<B->data[j]){
			C->data[k++]=A->data[i++];
		}
		else{
			C->data[k++]=B->data[j++];
		}
	}
	while(i<A->length){
		C->data[k++]=A->data[i++];
	}
	while(j<B->length){
		C->data[k++]=B->data[j++];
	}
	C->length = A->length + B->length;
	return true;
}

//q8
//
void Exchange_a_b(Sq *L, int a, int b){
	reverse_list(L, 0, a+b-1);
	reverse_list(L,0,b-1);
	reverse_list(L, b, a+b-1);
}

int main(){
	Sq sq;
	Sq sq1;
	Sq sum;
	InitList(&sq);
	InitList(&sq1);
	InitList(&sum);
	for(int i=0;i<10;i++){
		Add_Elem(&sq,i);
	}
	for(int i=10;i<15;i++){
		Add_Elem(&sq,2*i);
	}
	/* for(int i=1;i<10;i++){ */
		/* Add_Elem(&sq1,i*2); */
	/* } */
	printf("sq is :\n");
	for(int i = 0;i<sq.length;i++){
		printf("%d,",sq.data[i]);
	}
	printf("\n");
	Exchange_a_b(&sq,10,5);
	printf("sq is :\n");
	for(int i = 0;i<sq.length;i++){
		printf("%d,",sq.data[i]);
	}
	printf("\n");
	/* printf("sq1 is :\n"); */
	/* for(int i = 0;i<sq1.length;i++){ */
	/* 	printf("%d,",sq1.data[i]); */
	/* } */
	/* printf("\n"); */
	/* two_to_one(&sq,&sq1,&sum); */
	/* printf("sum is :\n"); */
	/* for(int i = 0;i<sum.length;i++){ */
	/* 	printf("%d,", sum.data[i]); */
	/* } */
	/* printf("\n"); */
	/* int lowest = Del_lowest(&sq); */
	/* printf("The lowest value is %d\n", lowest); */
	/* reverse_list(&sq); */
	/* Del_value_x_2(&sq, 9); */
	/* Del_value_a_to_b_1(&sq, 2,5); */
	/* Del_same_value(&sq); */
	/* printf("length is %d\n", sq.length); */
	/* printf("New list is:\n"); */
	/* for(int i = 0;i<sq.length;i++){ */
	/* 	printf("%d\n",sq.data[i]); */
	/* } */
	return 0;
}


