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
Position FindMax(BinTree BT); //�ݹ鷽ʽ�������ֵ 
Position cycleFindMax(BinTree BT); //ѭ����ʽ�������ֵ 

int main(int argc, char const* argv[])
{
	BinTree BT;
	BinTree RT;
	RT=(BinTree)malloc(sizeof(struct TreeNode));
	printf("�봴����:");
	BT=LineTree();
	
	
	RT=FindMax(BT); //�ݹ鷽ʽ�������ֵ
	printf("\n�ݹ�������ֵ:%d", RT->Data);
	
	printf("\n");
	RT=cycleFindMax(BT); //ѭ����ʽ�������ֵ 

	
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
	
	return;
 } 
 
//�������Ԫ�ص�ѭ������
Position cycleFindMax(BinTree BT)
{
	printf("ѭ���������ֵ:"); 
	if (BT) {
		while (BT->Right) {
			BT=BT->Right;
		}
	}
	
	printf("%d\n", BT->Data);
	
	return BT;
} 
