/*
*二叉树的三种遍历方式 
*author:justinzeng
*revise:2018/12/12
*/

#include <stdio.h>
#include <stdlib.h>
#define ElementType int
#define MaxSize 100 //二叉树的"最大容量"

typedef struct TreeNode *BinTree;
typedef BinTree Position;
//二叉树的存储结构 
struct TreeNode {
	ElementType Data;
	BinTree Left; //左子树 
	BinTree Right; //右子树 
};

//函数声明
BinTree CreateTree(); //初始化一棵树
BinTree LineTree(); //链接树  
void FirTraversal(BinTree BT); //先序遍历
void MidTraversal(BinTree BT);  //中序遍历 
void LstTraversal(BinTree BT); //后序遍历 

int main(int argc, char const* argv[])
{
	ElementType Data=0; //树结点数据
	
	BinTree BT; //生成一个树的存储结构 
	BT=CreateTree();
	
	printf("请创建二叉树:");
	BT=LineTree();
	
	printf("\n先序遍历：");
	FirTraversal(BT);

	printf("\n中序遍历：");
	MidTraversal(BT);
	
	printf("\n后序遍历：");
	LstTraversal(BT);
	
	return 0;
}

//初始化一棵树
BinTree CreateTree() 
{
	BinTree T;
	T=(BinTree)malloc(sizeof(struct TreeNode));
	
	return T;
} 

//链接树
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

//先序遍历 
void FirTraversal(BinTree BT)
{ 
	if (BT) {
		printf("%d ", BT->Data);
		FirTraversal(BT->Left);
		FirTraversal(BT->Right); 
	}
	
	return;
}

//中序遍历 
void MidTraversal(BinTree BT)
{
	if (BT) {
		MidTraversal(BT->Left);
		printf("%d ", BT->Data);
		MidTraversal(BT->Right);
	}
	
	return;
}

//后序遍历 
void LstTraversal(BinTree BT)
{
	if (BT) {
		LstTraversal(BT->Left);
		LstTraversal(BT->Right);
		printf("%d ", BT->Data);
	}
	
	return;
}
