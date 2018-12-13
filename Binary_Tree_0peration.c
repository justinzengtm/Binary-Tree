/*
*���������Ҷ��㡢���ܽ��������������������
*author:justinzeng
*date:2018/11/17 
*/

#include <stdio.h>
#include <stdlib.h>
#define ElementType int
#define MaxSize 100  //��������"�������"

typedef struct TreeNode *BinTree;
typedef BinTree Position;
//�������Ĵ洢�ṹ 
struct TreeNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
	int count; //�ܽ����
	int ChildCount; //�����ӽ����
};

//��������
BinTree CreateTree(); //��ʼ��һ����
BinTree LineTree(); //������  
void FirTraversal(BinTree BT); //�������
void MidTraversal(BinTree BT);  //������� 
void LstTraversal(BinTree BT); //������� 
void FirstPrintLeaves(BinTree BT); //�������Ҷ��� 
int AllNodeCount(BinTree BT, int count); //�����н����
int SingleFirTraversal(BinTree BT, int count); //�󵥺��ӽ���� 
int GetHight(BinTree BT); //�����ĸ߶�

int main(int argc, char const* argv[])
{
	ElementType Data=0; //���������
	int TreeHight=0; //����
	
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
	
	//������� 
	TreeHight=GetHight(BT); 
	printf("\n\n���ĸ߶ȣ�%d", TreeHight);
	
	printf("\n\n����Ҷ��㣺");
	FirstPrintLeaves(BT);
	
	BT->count=AllNodeCount(BT, BT->count); //�����н���� 
	BT->ChildCount=SingleFirTraversal(BT, BT->ChildCount); //�󵥺��ӽ����
	printf("\n\n�ܽ����Ϊ=%d\n", BT->count);
	printf("\n�����ӽ����Ϊ=%d\n", BT->ChildCount);
	
	return 0;
}

//��ʼ��һ����
BinTree CreateTree() 
{
	BinTree T;
	T=(BinTree)malloc(sizeof(struct TreeNode));
	T->ChildCount=0;
	T->count=0;
	
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

//�������Ҷ��� 
void FirstPrintLeaves(BinTree BT)
{
	if (BT) {
		if (BT->Left==NULL && BT->Right==NULL) {
			printf("%d ", BT->Data);
		}
		FirstPrintLeaves(BT->Left);
		FirstPrintLeaves(BT->Right);
	}
	
	return;
}

//�����н����
int AllNodeCount(BinTree BT, int count) 
{
	if (BT) {
		count++;
		count=AllNodeCount(BT->Left, count);
		count=AllNodeCount(BT->Right, count); 
	}
	
	return count;
}

//�󵥺��ӽ���� 
int SingleFirTraversal(BinTree BT, int count)
{ 
	if (BT) {
		if ((BT->Left!=NULL && BT->Right==NULL) || (BT->Left==NULL && BT->Right!=NULL)) {
			count++;
		}
		count=SingleFirTraversal(BT->Left, count);
		count=SingleFirTraversal(BT->Right, count); 
	}
	
	return count;
}

//�����ĸ߶� 
int GetHight(BinTree BT)
{
	int LH, RH, max;
	LH=RH=max=0;
	if (BT) {
		LH=GetHight(BT->Left);
		RH=GetHight(BT->Right);
		max=(LH>RH)? LH:RH; //�ʺ��ж����
		return (max+1);
	} else {
		return 0;
	}
}
