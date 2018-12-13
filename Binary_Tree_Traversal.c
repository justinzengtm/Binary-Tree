/*
*�����������ֱ�����ʽ 
*author:justinzeng
*revise:2018/12/12
*/

#include <stdio.h>
#include <stdlib.h>
#define ElementType int
#define MaxSize 100 //��������"�������"

typedef struct TreeNode *BinTree;
typedef BinTree Position;
//�������Ĵ洢�ṹ 
struct TreeNode {
	ElementType Data;
	BinTree Left; //������ 
	BinTree Right; //������ 
};

//��������
BinTree CreateTree(); //��ʼ��һ����
BinTree LineTree(); //������  
void FirTraversal(BinTree BT); //�������
void MidTraversal(BinTree BT);  //������� 
void LstTraversal(BinTree BT); //������� 

int main(int argc, char const* argv[])
{
	ElementType Data=0; //���������
	
	BinTree BT; //����һ�����Ĵ洢�ṹ 
	BT=CreateTree();
	
	printf("�봴��������:");
	BT=LineTree();
	
	printf("\n���������");
	FirTraversal(BT);

	printf("\n���������");
	MidTraversal(BT);
	
	printf("\n���������");
	LstTraversal(BT);
	
	return 0;
}

//��ʼ��һ����
BinTree CreateTree() 
{
	BinTree T;
	T=(BinTree)malloc(sizeof(struct TreeNode));
	
	return T;
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
