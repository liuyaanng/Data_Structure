#include <stdio.h>
#include "MergeLinkList.h"                    //**▲02 线性表**//


Status CmpGreater(ElemType data1, ElemType data2){
	return data1 > data2 ? TRUE : FALSE;
}
// 测试函数，打印元素
void PrintElem(ElemType e) {
    printf("%d ", e);
}


int main(int argc, char** argv) {
    LinkList La, Lb, Lc;
    
    int n = 5;
    
    printf("作为示例，La长度设定为 %d ，Lb长度设定为 %d ，创建La和Lb...\n", n, n);
    
    CreateList_Head(&La, n, "TestData_Head.txt");
    printf("La = ");
    ListTraverse(La, PrintElem);
    
    CreateList_Tail(&Lb, n, "TestData_Tail.txt");
    printf("Lb = ");
    ListTraverse(Lb, PrintElem);
    
    printf("归并La和Lb为Lc = ");
    /* MergeLinkList_1(La, Lb, &Lc, CmpGreater); */
    MergeLinkList_2(La, Lb, &Lc, CmpGreater);
    ListTraverse(Lc, PrintElem);
		
    
    return 0;
}


