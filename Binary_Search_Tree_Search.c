#include <stdio.h>
#include <stdlib.h>
#define ElementType int
#define MaxSize 100 //������������"�������"

typedef struct TreeNode *BinTree;
typedef BinTree Position;
struct TreeNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
};
 
//�������� 
BinTree LineTree(); //������ 
Position Find(ElementType X, BinTree BT); //�ݹ����
Position IterateFind(ElementType X, BinTree BT); //(�ǵݹ�)ѭ������
void FirTraversal(BinTree BT); //�������
void MidTraversal(BinTree BT);  //������� 
void LstTraversal(BinTree BT); //�������

int main(int argc, char const* argv[])
{
	ElementType number=0;
	BinTree BT; //���������� 
	BinTree RT;
	RT=(BinTree)malloc(sizeof(struct TreeNode));
	
	printf("�봴������������:");
	BT=LineTree(); //������
	 
	printf("\n�������:");
	FirTraversal(BT);
	printf("\n���������");
	MidTraversal(BT);
	printf("\n���������");
	LstTraversal(BT);
	
	printf("\n\n������Ҫ���ҵ�Ԫ��:");
	scanf("%d", &number);
	RT=Find(number,BT); //�ݹ� 
	//RT=IterateFind(number,BT);//�ǵݹ� 
	if (RT) {
		printf("\n���ҽ��:%d", RT->Data);
	} else {
		printf("\nû��Ҫ�������Ԫ��.");
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

//�ݹ���� 
Position Find(ElementType X, BinTree BT) 
{
	if (!BT) {
		return NULL; //��Ϊ�գ� 
	} 
	if (X>BT->Data) {
		return Find(X,BT->Right); //���������в��� 
	} else if (X<BT->Data) {
		return Find(X,BT->Left); //���������в��� 
	} else {
		return BT;//�ҵ��˾ͷ���������; 
	}
}

//(�ǵݹ�)ѭ������
Position IterateFind(ElementType X, BinTree BT)
{
	while (BT) {
		if (X>BT->Data) {
			BT=BT->Right;
		} else if (X<BT->Data) {
			BT=BT->Left;
		} else {
			return BT;
		}
	}
	return NULL;
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
