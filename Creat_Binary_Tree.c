/*
*�������Ĵ���
*author:justinzeng
*date:2018/11/17 
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
	BinTree Left;
	BinTree Right; 
};

//��������
BinTree CreateTree(); //��ʼ��һ����
BinTree LineTree(); //������  
void FirTraversal(BinTree BT); //�������

int main(int argc, char const* argv[])
{
	ElementType Data=0; //���������

	
	BinTree BT; //����һ�����Ĵ洢�ṹ 
	BT=CreateTree();
	printf("�봴��������:");
	BT=LineTree();
	
	printf("\n�����������������:");
	FirTraversal(BT);
	
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
}
