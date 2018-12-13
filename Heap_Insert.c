#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h> 
#define ElementType int
#define MaxSize 100 
#define MaxData 1000

typedef struct Heap *MaxHeap;
struct Heap {
	ElementType *HeapArr; //�洢��Ԫ�ص�����
	int NowSize; //��ǰ�����Ԫ�ظ���
	int MaxContent; //�ѵ�������� 
};

//�������� 
MaxHeap Create (int Max); //���ѵ�������ʼ��
MaxHeap Build(MaxHeap H); //�ѵĴ��� 
void Insert(MaxHeap H, ElementType X); //���ѵĲ��� 
bool IsFull(MaxHeap H); //�ж϶���
void PrintHeap(MaxHeap H, int NowSize); //�����  
bool IsFull(MaxHeap H); //�ж϶��� 
bool IsEmpty(MaxHeap H); //�ж϶ѿ� 
void BuildHeap(MaxHeap H, ElementType i); //�������� 
void AdjustHeap(MaxHeap H); //��������������� 

int main(int argc, char const* argv[])
{
	MaxHeap H;
	H=Create(MaxSize);
	H=Build(H); //������ 
	AdjustHeap(H); //������Ϊ���� 
	printf("�����Ϊ:%d\n", H->HeapArr[1]);
	printf("\n");
	PrintHeap(H, H->NowSize); //������� 
	
	printf("\n������Ҫ�����Ԫ��:");
	scanf("%d", &i);
	Insert(H, i);
	printf("\n���������:\n");
	PrintHeap(H, H->NowSize);
	
	return 0; 
}

//���ѵ������ĳ�ʼ�� 
MaxHeap Create (int Max)
{
	MaxHeap H=(MaxHeap)malloc(sizeof(struct Heap)); /*����ռ佨��*/ 
	H->HeapArr=(ElementType *)malloc(sizeof(struct ElememtType*)*(MaxSize+1)); /*����*/
	H->NowSize=0;
	H->MaxContent=Max;
	H->HeapArr[0]=MaxData; /*MaxDataΪ�Զ����ֵ,����������:*/ 
	/*��һ�ж���һ��"�ڱ�",Ҳ���Ƕ���һ�����ڶ��п��ܵ����е�Ԫ��ֵ*/
	return H; 
}

//�ѵĴ���
MaxHeap Build(MaxHeap H) 
{
	ElementType Data;
	
	printf("�봴������:"); 
	while(Data!=-1) {
		scanf("%d", &Data);
		if (Data!=-1) {
			Insert(H,Data);
		}
	}
	
	return H;
}

//���ѵĲ��� 
void Insert(MaxHeap H, ElementType X) 
{
	int i=0;
	if (IsFull(H)) {
		printf("��������.");
		return;
	}
	i=++H->NowSize; /*NowSize�ǵ�ǰ�ѵ����һ��Ԫ�ص�λ�ã����Բ�������.*/
	for ( ; H->HeapArr[i/2]<X; i/=2) {
		H->HeapArr[i]=H->HeapArr[i/2]; /*���������Ҫ�����ֵС���ͰѸ�����ƶ�����*/ 
	} 
	H->HeapArr[i]=X;
	
	return;
}

//�ж϶��Ƿ���
bool IsFull(MaxHeap H)
{
	return (H->MaxContent==H->NowSize);
}

//�����
void PrintHeap(MaxHeap H, int NowSize) 
{
	int i=0;
	printf("������������:\n");
	for (i=1;i<=NowSize;i++) {
		printf("%d ", H->HeapArr[i]);
	}
	printf("\n");
	
	return;
}

//��������(������Delete����)
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

//����������Ԫ�ص������� 
void AdjustHeap(MaxHeap H)
{
	int i;
	for (i=H->NowSize/2; i>0; i--) {
		BuildHeap(H,i);
	}
	
	return;
} 
