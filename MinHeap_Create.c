#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h> 
#define ElementType int
#define MinSize 100 
#define MinData 1000

typedef struct Heap *MinHeap;
struct Heap {
	ElementType *HeapArr; //存储堆元素的数组
	int NowSize; //当前堆里的元素个数
	int MinContent; ///堆的最小容量
};

//函数声明 
MinHeap Create (int Min); //最小堆的容量的初始化
MinHeap Build(MinHeap H); //堆的创建 
void Insert(MinHeap H, ElementType X); //最小堆的插入 
void PrintHeap(MinHeap H, int NowSize); //输出堆 
ElementType Delete(MinHeap H); //最小堆的删除 
bool IsFull(MinHeap H); //判断堆满 
bool IsEmpty(MinHeap H); //判断堆空 
void BuildHeap(MinHeap H, ElementType i); //建立最小堆 
void AdjustHeap(MinHeap H); //调整数组的有序性  

int main(int argc, char const* argv[])
{
	MinHeap H;
	H=Create(MinSize);
	H=Build(H); //创建堆 
	AdjustHeap(H); //调整堆为最小堆 
	printf("根结点为:%d\n", H->HeapArr[1]);
	printf("\n");
	PrintHeap(H, H->NowSize); //输出最小堆 
	
	return 0; 
}

//最小堆的容量的初始化 
MinHeap Create (int Min)
{
	MinHeap H=(MinHeap)malloc(sizeof(struct Heap)); //申请空间建堆 
	H->HeapArr=(ElementType *)malloc(sizeof(ElementType)*(MinSize+1)); //数组
	H->NowSize=0;
	H->MinContent=Min;
	H->HeapArr[0]=MinData; /*MinData为自定最小值,作用如下行:*/ 
	/*上一行定义一个"哨兵",也就是定义一个小于堆中可能的所有的元素值*/
	return H; 
}

//堆的创建
MinHeap Build(MinHeap H) 
{
	ElementType Data;
	
	printf("请创建最大堆:"); 
	while(Data!=-1) {
		scanf("%d", &Data);
		if (Data!=-1) {
			Insert(H,Data);
		}
	}
	
	return H;
}

//最小堆的插入 
void Insert(MinHeap H, ElementType X) 
{
	int i;
	if (IsFull(H)) {
		printf("最小堆已满.");
		return;
	}
	i=++H->NowSize; /*NowSize是当前堆的最后一个元素的位置，所以插它后面.*/
	for ( ; H->HeapArr[i/2]<X; i/=2) {
		H->HeapArr[i]=H->HeapArr[i/2]; /*如果父结点比要插入的值小，就把父结点移动下来*/ 
	} 
	H->HeapArr[i]=X;
	
	return;
}

//输出堆 
void PrintHeap(MinHeap H, int NowSize) 
{
	int i=0;
	printf("最小堆依次往下:\n");
	for (i=1;i<=NowSize;i++) {
		printf("%d ", H->HeapArr[i]);
	}
	printf("\n");
	
	return;
}

//最小堆的删除
ElementType Delete(MinHeap H)
{
	int Head,Min; /*Head是要插入的位置，Min为作比较用*/ 
	ElementType DeleteItem,Tag;
	if (IsEmpty(H)) {
		printf("最小堆为空.");
		return;
	}	
	DeleteItem=H->HeapArr[1]; /*先把要删除的结点保存起来，最后返回出去*/
	Tag=H->HeapArr[H->NowSize--];/*保存要放上去的最后一个结点*/
	/*Head*2判断是否有左子树，左子树为Head*2,右子树为Head*2+1(下标)*/ 
	for (Head=1; Head*2<=H->NowSize; Head=Min) {
		/*如果有左右子树，就判断左右子树谁小*/ 
		/*Head*2<=H->NowSize用来判断是否有左子树*/ 
		Min=Head*2; /*Min一开始指向左子树*/ 
		if ((H->HeapArr[Min]>H->HeapArr[Min+1])&&(Min!=H->NowSize)) {
			/*如果Min=H->NowSize，证明左子树是最后一个，那就是没右子树*/
			/*左子树不是最后一个，那就证明一定有右子树,才进行的左右子树谁更小的判别*/
			 Min++;
		} 
		if (Tag<=H->HeapArr[Min]) {
			break;
		} else {
			/*将Tag移到下面一层*/ 
			H->HeapArr[Head]=H->HeapArr[Min];
		} 
	}
	H->HeapArr[Head]=Tag;
	return DeleteItem;
} 

//判断堆是否满
bool IsFull(MinHeap H)
{
	return (H->MinContent==H->NowSize);
} 

//判断堆是否空
bool IsEmpty(MinHeap H)
{
    return (H->NowSize==0);
} 

//建立最小堆(方法与Delete相似)
void BuildHeap(MinHeap H, ElementType i)
{
	int Parent,Child;
	ElementType X;
	
	X=H->HeapArr[i];
	for(Parent=i;Parent*2<=H->NowSize;Parent=Child) {
		Child=Parent*2;
		if((Child!=H->NowSize)&&(H->HeapArr[Child]>H->HeapArr[Child+1])) {
			Child++;
		}
		if(X<H->HeapArr[Child]) {
			break;
		} else {
			H->HeapArr[Parent]=H->HeapArr[Child];
		}
	} 
	H->HeapArr[Parent]=X;
	
	return;
}

//调整数组中元素的有序性 
void AdjustHeap(MinHeap H)
{
	int i;
	for (i=H->NowSize/2; i>0; i--) {
		BuildHeap(H,i);
	}
	
	return;
}
