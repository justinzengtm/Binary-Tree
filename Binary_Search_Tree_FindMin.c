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
Position FindMin(BinTree BT); //�ݹ鷽ʽ������Сֵ 
Position cycleFindMin(BinTree BT); //ѭ����ʽ������Сֵ 

int main(int argc, char const* argv[])
{
	BinTree BT;
	BinTree RT;
	RT=(BinTree)malloc(sizeof(struct TreeNode));
	printf("�봴����:");
	BT=LineTree();
	
	RT=FindMin(BT); //�ݹ鷽ʽ������Сֵ
	printf("\n�ݹ������Сֵ:%d", RT->Data);
	
	printf("\n\n");
	RT=cycleFindMin(BT); //ѭ����ʽ������Сֵ 

	
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
	
	return; 
}  

//������СԪ�ص�ѭ������
Position cycleFindMin(BinTree BT)
{
	printf("ѭ��������Сֵ:");
	if (BT) {
		while (BT->Left) {
			BT=BT->Left;
		}
	}
	
	printf("%d\n", BT->Data);
	
	return BT; 
}
