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

BinTree LineTree(); //������ 
void Compare(BinTree BT, BinTree T, int *P); //�ж����Ƿ���ͬ
void FirTraversal(BinTree BT); //�������
void MidTraversal(BinTree BT);  //������� 
void LstTraversal(BinTree BT); //������� 

int main(int argc, char const* argv[])
{
	BinTree BT;
    BinTree RT;
	int *Tmp=NULL; //��ʶ��,�ж����ö����������Ƿ���ͬ 
	int tmp=1;
	Tmp=&tmp;
	
	printf("�봴����BT:");
	BT=LineTree();
	
	printf("�봴����RT:");
	RT=LineTree();
	
	printf("\nBT�����������");
	FirTraversal(BT);
	printf("\nRT�����������");
	FirTraversal(RT);
	
	//�б��������Ƿ�һ��
	Compare(BT, RT, Tmp);
	printf("\n");
	if (tmp!=-1) {
		printf("\n���ö�����������ͬ��\n");
	} else {
		printf("\n���ö�������������ͬ��\n");
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

//�ж����Ƿ���ͬ
void Compare(BinTree BT, BinTree T, int *P)
{
	if (BT==NULL && T==NULL) {
		return;
	}
	
	if (BT!=NULL && T!=NULL) {
		if(BT->Data!=T->Data) {
			*P=-1;
			return;
		} 
	} 
	if (BT==NULL && T!=NULL || BT!=NULL && T==NULL) {
		*P=-1;	
		return;
	}
	
	//�ݹ鴦���������� 
	Compare(BT->Left, T->Left, P);	
	Compare(BT->Right, T->Right, P);
	
	return;
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
