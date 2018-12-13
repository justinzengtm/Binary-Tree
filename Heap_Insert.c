#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h> 
#define ElementType int
#define MaxSize 100 
#define MaxData 1000

typedef struct Heap *MaxHeap;
struct Heap {
	ElementType *HeapArr; //存储堆元素的数组
	int NowSize; //当前堆里的元素个数
	int MaxContent; //堆的最大容量 
};

//函数声明 
MaxHeap Create (int Max); //最大堆的容量初始化
MaxHeap Build(MaxHeap H); //堆的创建 
void Insert(MaxHeap H, ElementType X); //最大堆的插入 
bool IsFull(MaxHeap H); //判断堆满
void PrintHeap(MaxHeap H, int NowSize); //输出堆  
bool IsFull(MaxHeap H); //判断堆满 
bool IsEmpty(MaxHeap H); //判断堆空 
void BuildHeap(MaxHeap H, ElementType i); //建立最大堆 
void AdjustHeap(MaxHeap H); //调整数组的有序性 

int main(int argc, char const* argv[])
{
	MaxHeap H;
	H=Create(MaxSize);
	H=Build(H); //创建堆 
	AdjustHeap(H); //调整堆为最大堆 
	printf("根结点为:%d\n", H->HeapArr[1]);
	printf("\n");
	PrintHeap(H, H->NowSize); //输出最大堆 
	
	printf("\n请输入要插入的元素:");
	scanf("%d", &i);
	Insert(H, i);
	printf("\n插入操作后:\n");
	PrintHeap(H, H->NowSize);
	
	return 0; 
}

//最大堆的容量的初始化 
MaxHeap Create (int Max)
{
	MaxHeap H=(MaxHeap)malloc(sizeof(struct Heap)); /*申请空间建堆*/ 
	H->HeapArr=(ElementType *)malloc(sizeof(struct ElememtType*)*(MaxSize+1)); /*数组*/
	H->NowSize=0;
	H->MaxContent=Max;
	H->HeapArr[0]=MaxData; /*MaxData为自定最大值,作用如下行:*/ 
	/*上一行定义一个"哨兵",也就是定义一个大于堆中可能的所有的元素值*/
	return H; 
}

//堆的创建
MaxHeap Build(MaxHeap H) 
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

//最大堆的插入 
void Insert(MaxHeap H, ElementType X) 
{
	int i=0;
	if (IsFull(H)) {
		printf("最大堆已满.");
		return;
	}
	i=++H->NowSize; /*NowSize是当前堆的最后一个元素的位置，所以插它后面.*/
	for ( ; H->HeapArr[i/2]<X; i/=2) {
		H->HeapArr[i]=H->HeapArr[i/2]; /*如果父结点比要插入的值小，就把父结点移动下来*/ 
	} 
	H->HeapArr[i]=X;
	
	return;
}

//判断堆是否满
bool IsFull(MaxHeap H)
{
	return (H->MaxContent==H->NowSize);
}

//输出堆
void PrintHeap(MaxHeap H, int NowSize) 
{
	int i=0;
	printf("最大堆依次往下:\n");
	for (i=1;i<=NowSize;i++) {
		printf("%d ", H->HeapArr[i]);
	}
	printf("\n");
	
	return;
}

//建立最大堆(方法与Delete相似)
void BuildHeap(MaxHeap H, ElementType i)
{
	int Parent,Child;
	ElementType X;
	
	X=H->HeapArr[i];
	for(Parent=i;Parent*2<=H->NowSize;Parent=Child) {
		Child=Parent*2;
		if((Child!=H->NowSize)&&(H->HeapArr[Child]<H->HeapArr[Child+1])) {
			Child++;
		}
		if(X>H->HeapArr[Child]) {
			break;
		} else {
			H->HeapArr[Parent]=H->HeapArr[Child];
		}
	} 
	H->HeapArr[Parent]=X;
	
	return;
}

//调整数组中元素的有序性 
void AdjustHeap(MaxHeap H)
{
	int i;
	for (i=H->NowSize/2; i>0; i--) {
		BuildHeap(H,i);
	}
	
	return;
} 
