#include <stdio.h>
#include <stdlib.h>

int sum_1(int * arr, int n);
int sum_2(int arr[], int n);



int sum_1(int * arr, int n){
	int total = 0;
	for (int i = 0; i < n; i++){
		total += arr[i];
	}
	return total;
}


int sum_2(int arr[], int n){
	int total = 0;
	for (int i = 0; i < n; i++){
		total += arr[i];
	}
	return total;
}



int main(){
	int *a;
	int b[3] = {1,2,3};
	/* printf("%p %p\n", b, &b[0]); */
	int sum1 = 0, sum2 = 0;
	sum1 = sum_1(b,3);
	sum2 = sum_2(b,3);

	return 0;
}
