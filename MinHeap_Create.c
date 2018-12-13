#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h> 
#define ElementType int
#define MinSize 100 
#define MinData 1000

typedef struct Heap *MinHeap;
struct Heap {
	ElementType *HeapArr; //�洢��Ԫ�ص�����
	int NowSize; //��ǰ�����Ԫ�ظ���
	int MinContent; ///�ѵ���С����
};

//�������� 
MinHeap Create (int Min); //��С�ѵ������ĳ�ʼ��
MinHeap Build(MinHeap H); //�ѵĴ��� 
void Insert(MinHeap H, ElementType X); //��С�ѵĲ��� 
void PrintHeap(MinHeap H, int NowSize); //����� 
ElementType Delete(MinHeap H); //��С�ѵ�ɾ�� 
bool IsFull(MinHeap H); //�ж϶��� 
bool IsEmpty(MinHeap H); //�ж϶ѿ� 
void BuildHeap(MinHeap H, ElementType i); //������С�� 
void AdjustHeap(MinHeap H); //���������������  

int main(int argc, char const* argv[])
{
	MinHeap H;
	H=Create(MinSize);
	H=Build(H); //������ 
	AdjustHeap(H); //������Ϊ��С�� 
	printf("�����Ϊ:%d\n", H->HeapArr[1]);
	printf("\n");
	PrintHeap(H, H->NowSize); //�����С�� 
	
	return 0; 
}

//��С�ѵ������ĳ�ʼ�� 
MinHeap Create (int Min)
{
	MinHeap H=(MinHeap)malloc(sizeof(struct Heap)); //����ռ佨�� 
	H->HeapArr=(ElementType *)malloc(sizeof(ElementType)*(MinSize+1)); //����
	H->NowSize=0;
	H->MinContent=Min;
	H->HeapArr[0]=MinData; /*MinDataΪ�Զ���Сֵ,����������:*/ 
	/*��һ�ж���һ��"�ڱ�",Ҳ���Ƕ���һ��С�ڶ��п��ܵ����е�Ԫ��ֵ*/
	return H; 
}

//�ѵĴ���
MinHeap Build(MinHeap H) 
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

//��С�ѵĲ��� 
void Insert(MinHeap H, ElementType X) 
{
	int i;
	if (IsFull(H)) {
		printf("��С������.");
		return;
	}
	i=++H->NowSize; /*NowSize�ǵ�ǰ�ѵ����һ��Ԫ�ص�λ�ã����Բ�������.*/
	for ( ; H->HeapArr[i/2]<X; i/=2) {
		H->HeapArr[i]=H->HeapArr[i/2]; /*���������Ҫ�����ֵС���ͰѸ�����ƶ�����*/ 
	} 
	H->HeapArr[i]=X;
	
	return;
}

//����� 
void PrintHeap(MinHeap H, int NowSize) 
{
	int i=0;
	printf("��С����������:\n");
	for (i=1;i<=NowSize;i++) {
		printf("%d ", H->HeapArr[i]);
	}
	printf("\n");
	
	return;
}

//��С�ѵ�ɾ��
ElementType Delete(MinHeap H)
{
	int Head,Min; /*Head��Ҫ�����λ�ã�MinΪ���Ƚ���*/ 
	ElementType DeleteItem,Tag;
	if (IsEmpty(H)) {
		printf("��С��Ϊ��.");
		return;
	}	
	DeleteItem=H->HeapArr[1]; /*�Ȱ�Ҫɾ���Ľ�㱣����������󷵻س�ȥ*/
	Tag=H->HeapArr[H->NowSize--];/*����Ҫ����ȥ�����һ�����*/
	/*Head*2�ж��Ƿ�����������������ΪHead*2,������ΪHead*2+1(�±�)*/ 
	for (Head=1; Head*2<=H->NowSize; Head=Min) {
		/*������������������ж���������˭С*/ 
		/*Head*2<=H->NowSize�����ж��Ƿ���������*/ 
		Min=Head*2; /*Minһ��ʼָ��������*/ 
		if ((H->HeapArr[Min]>H->HeapArr[Min+1])&&(Min!=H->NowSize)) {
			/*���Min=H->NowSize��֤�������������һ�����Ǿ���û������*/
			/*�������������һ�����Ǿ�֤��һ����������,�Ž��е���������˭��С���б�*/
			 Min++;
		} 
		if (Tag<=H->HeapArr[Min]) {
			break;
		} else {
			/*��Tag�Ƶ�����һ��*/ 
			H->HeapArr[Head]=H->HeapArr[Min];
		} 
	}
	H->HeapArr[Head]=Tag;
	return DeleteItem;
} 

//�ж϶��Ƿ���
bool IsFull(MinHeap H)
{
	return (H->MinContent==H->NowSize);
} 

//�ж϶��Ƿ��
bool IsEmpty(MinHeap H)
{
    return (H->NowSize==0);
} 

//������С��(������Delete����)
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

//����������Ԫ�ص������� 
void AdjustHeap(MinHeap H)
{
	int i;
	for (i=H->NowSize/2; i>0; i--) {
		BuildHeap(H,i);
	}
	
	return;
}
