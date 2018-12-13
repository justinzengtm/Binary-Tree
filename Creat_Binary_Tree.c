/*
*二叉树的创建
*author:justinzeng
*date:2018/11/17 
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
	BinTree Left;
	BinTree Right; 
};

//函数声明
BinTree CreateTree(); //初始化一棵树
BinTree LineTree(); //链接树  
void FirTraversal(BinTree BT); //先序遍历

int main(int argc, char const* argv[])
{
	ElementType Data=0; //树结点数据

	
	BinTree BT; //生成一个树的存储结构 
	BT=CreateTree();
	printf("请创建二叉树:");
	BT=LineTree();
	
	printf("\n二叉树先序遍历序列:");
	FirTraversal(BT);
	
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
}
