#include <stdio.h>
#include <stdlib.h>
#define ElementType int
#define MaxSize 100 //������������"�������"

typedef struct TreeNode *BinTree;
typedef BinTree Position;
//�����������Ĵ洢�ṹ 
struct TreeNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

//�������� 
BinTree LineTree(); //������ 
BinTree Insert(ElementType X, BinTree BT); //������� 
void FirTraversal(BinTree BT); //�������
void MidTraversal(BinTree BT);  //������� 
void LstTraversal(BinTree BT); //�������

int main(int argc, char const* argv[])
{
	ElementType number=0; 
	BinTree BT;
	
	printf("��������������:"); 
	BT=LineTree();
	
	printf("\n���������");
	FirTraversal(BT);
	printf("\n���������");
	MidTraversal(BT);
	printf("\n���������");
	LstTraversal(BT);
	
	printf("\n\n������Ҫ�������:");
	scanf("%d", &number);
	Insert(number, BT);
	
	printf("\n�����Ķ�������������:\n");
	printf("\n���������");
	FirTraversal(BT);
	printf("\n���������");
	MidTraversal(BT);
	printf("\n���������");
	LstTraversal(BT);
	
	return 0; 
}

//������ 
BinTree LineTree()
{
	int number;
	BinTree T;
	scanf("%d", &number);
	if (number==-1) {
		T=NULL;
	} else {
		T=(BinTree)malloc(sizeof(struct TreeNode));
		T->Data=number;
		T->Left=LineTree();
		T->Right=LineTree(); 
	}		
	return T;	
}

//�����������Ĳ��뺯��
BinTree Insert(ElementType X, BinTree BT)
{
	//����Ϊ�գ������ɲ�����һ����� 
	if (!BT) {
		BT=(BinTree)malloc(sizeof(struct TreeNode));
		BT->Data=X;
		BT->Left=BT->Right=NULL;
	} else if (X>BT->Data) {    //��ʼ���� 
		BT->Right=Insert(X,BT->Right);
	} else if (X<BT->Data) {
		BT->Left=Insert(X,BT->Left);
	}
	return BT;
 } 
 
 //������� 
void FirTraversal(BinTree BT)
{ 
	if (BT) {
		printf("%d ", BT->Data);
		FirTraversal(BT->Left);
		FirTraversal(BT->Right); 
	}
	
	return;
}

//������� 
void MidTraversal(BinTree BT)
{
	if (BT) {
		MidTraversal(BT->Left);
		printf("%d ", BT->Data);
		MidTraversal(BT->Right);
	}
	
	return;
}

//������� 
void LstTraversal(BinTree BT)
{
	if (BT) {
		LstTraversal(BT->Left);
		LstTraversal(BT->Right);
		printf("%d ", BT->Data);
	}
	
	return;
}
