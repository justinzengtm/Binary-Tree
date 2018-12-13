#include <stdio.h>
#include <stdlib.h>
#define ElementType int
#define MaxSize 100 //二叉搜索树的"最大容量"

typedef struct TreeNode *BinTree;
typedef BinTree Position;
//二叉搜索树的存储结构 
struct TreeNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

//函数声明 
BinTree LineTree(); //链接树 
BinTree Insert(ElementType X, BinTree BT); //插入操作 
void FirTraversal(BinTree BT); //先序遍历
void MidTraversal(BinTree BT);  //中序遍历 
void LstTraversal(BinTree BT); //后序遍历

int main(int argc, char const* argv[])
{
	ElementType number=0; 
	BinTree BT;
	
	printf("创建二叉搜索树:"); 
	BT=LineTree();
	
	printf("\n先序遍历：");
	FirTraversal(BT);
	printf("\n中序遍历：");
	MidTraversal(BT);
	printf("\n后序遍历：");
	LstTraversal(BT);
	
	printf("\n\n请输入要插入的数:");
	scanf("%d", &number);
	Insert(number, BT);
	
	printf("\n插入后的二叉搜索树遍历:\n");
	printf("\n先序遍历：");
	FirTraversal(BT);
	printf("\n中序遍历：");
	MidTraversal(BT);
	printf("\n后序遍历：");
	LstTraversal(BT);
	
	return 0; 
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

//二叉搜索树的插入函数
BinTree Insert(ElementType X, BinTree BT)
{
	//若树为空，就生成并返回一个结点 
	if (!BT) {
		BT=(BinTree)malloc(sizeof(struct TreeNode));
		BT->Data=X;
		BT->Left=BT->Right=NULL;
	} else if (X>BT->Data) {    //开始查找 
		BT->Right=Insert(X,BT->Right);
	} else if (X<BT->Data) {
		BT->Left=Insert(X,BT->Left);
	}
	return BT;
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
