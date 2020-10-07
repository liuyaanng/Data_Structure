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
void reverse_list(Sq *L){
	int temp = 0;
	for(int i=0;i<L->length/2;i++){
		temp = L->data[i];
		L->data[i] = L->data[L->length-1-i];
		L->data[L->length-1-i] = temp;
	}
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





int main(){
	Sq sq;
	InitList(&sq);
	for(int i=1;i<10;i++){
		Add_Elem(&sq,i);
		Add_Elem(&sq,i);
		Add_Elem(&sq,i);
	}




	for(int i = 0;i<sq.length;i++){
		printf("%d\n",sq.data[i]);
	}
	/* int lowest = Del_lowest(&sq); */
	/* printf("The lowest value is %d\n", lowest); */
	/* reverse_list(&sq); */
	/* Del_value_x_2(&sq, 9); */
	/* Del_value_a_to_b_1(&sq, 2,5); */
	Del_same_value(&sq);
	printf("length is %d\n", sq.length);
	printf("New list is:\n");
	for(int i = 0;i<sq.length;i++){
		printf("%d\n",sq.data[i]);
	}
	return 0;
}


