#include <stdio.h>
#include <stdlib.h>
#define ElementType int
#define MaxSize 100 //������������"�������"

typedef struct TreeNode *BinTree;
typedef BinTree Position;
//�����������Ĵ洢�ṹ 
struct TreeNode {
	ElementType Data; 
	BinTree Left; //������ 
	BinTree Right; //������ 
};

//�������� 
BinTree LineTree(); //������ 
Position FindMin(BinTree BT); //�ݹ�������ֵ 
Position FindMax(BinTree BT); //�ݹ������Сֵ 
BinTree Delete (ElementType X, BinTree BT); //ɾ������  
void FirTraversal(BinTree BT); //�������
void MidTraversal(BinTree BT); //������� 
void LstTraversal(BinTree BT); //�������

int main(int argc, char const *argv[]) 
{
	ElementType number=0;
	BinTree BT; //���������� 
	BinTree RT;
	RT=(BinTree)malloc(sizeof(struct TreeNode));
	
	printf("�봴������������:");
	BT=LineTree(); //������
	 
	printf("\n�����������:");
	FirTraversal(BT);
	printf("\n���������");
	MidTraversal(BT);
	printf("\n���������");
	LstTraversal(BT);
	
	printf("\n\n������Ҫɾ����Ԫ��:");
	scanf("%d", &number);
	//��ʼɾ��
	RT=Delete(number, BT);

	if (RT!=NULL) {
		printf("\nɾ��������Ķ����������������:");
		FirTraversal(BT);
		printf("\n���������");
		MidTraversal(BT);
		printf("\n���������");
		LstTraversal(BT);
	}	

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

//������������ɾ������
BinTree Delete (ElementType X, BinTree BT)
{
	BinTree TP;
	
	if (!BT) {
		printf("����");
		return NULL;
	} else if (X<BT->Data) {
		BT->Left=Delete(X, BT->Left); //��ݹ� 
	} else if (X>BT->Data) {
		BT->Right=Delete(X, BT->Right); //�ҵݹ� 
	} else {
		//�ҵ�Ҫɾ���Ľ���,�жϸý���Ƿ�ͬʱ���������� 
		if (BT->Left&&BT->Right) {
			TP=FindMin(BT->Right);//��������������СԪ�صĽ�� 
			//BT->Data�ǵ�ǰҪɾ���Ľ��,���԰�TP->Data�滻��ȥ 
			BT->Data=TP->Data;
			BT->Right=Delete(BT->Data,BT->Right);//ɾ��������������ɾ����СԪ�� 
		} else {
			TP=BT;
			if (!BT->Left) {
				BT=BT->Right;
			} else if (!BT->Right) {
				BT=BT->Left;
			}
			free (TP);
		}
	}
	
	return BT;
} 

//������СԪ�صĵݹ麯��
Position FindMin(BinTree BT)
{
	if (!BT) {
		return NULL; //���Ϊ�����ͷ���NULL; 
	} else if (!BT->Left) {
		return BT; //�ݹ鵽�����Ľ��϶�����Сֵ; 
	} else {
		return FindMin(BT->Left); //û�������һֱ�ݹ�,�ݹ�����; 
	}
}  

//�������Ԫ�صĵݹ麯��
Position FindMax(BinTree BT)
{
	if (!BT) {
		return NULL;
	} else if (!BT->Right) {
		return BT;
	} else {
		return FindMax(BT->Right);
	}
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
