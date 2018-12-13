#include <stdio.h>
#include <stdlib.h>
#define ElementType int
#define MaxSize 100 //二叉搜索树的"最大容量"

typedef struct TreeNode *BinTree;
typedef BinTree Position;
struct TreeNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
};
 
//函数声明 
BinTree LineTree(); //链接树 
Position Find(ElementType X, BinTree BT); //递归查找
Position IterateFind(ElementType X, BinTree BT); //(非递归)循环查找
void FirTraversal(BinTree BT); //先序遍历
void MidTraversal(BinTree BT);  //中序遍历 
void LstTraversal(BinTree BT); //后序遍历

int main(int argc, char const* argv[])
{
	ElementType number=0;
	BinTree BT; //二叉搜索树 
	BinTree RT;
	RT=(BinTree)malloc(sizeof(struct TreeNode));
	
	printf("请创建二叉搜索树:");
	BT=LineTree(); //创建树
	 
	printf("\n先序遍历:");
	FirTraversal(BT);
	printf("\n中序遍历：");
	MidTraversal(BT);
	printf("\n后序遍历：");
	LstTraversal(BT);
	
	printf("\n\n请输入要查找的元素:");
	scanf("%d", &number);
	RT=Find(number,BT); //递归 
	//RT=IterateFind(number,BT);//非递归 
	if (RT) {
		printf("\n查找结果:%d", RT->Data);
	} else {
		printf("\n没有要查找这个元素.");
	}
	
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

//递归查找 
Position Find(ElementType X, BinTree BT) 
{
	if (!BT) {
		return NULL; //树为空； 
	} 
	if (X>BT->Data) {
		return Find(X,BT->Right); //往右子树中查找 
	} else if (X<BT->Data) {
		return Find(X,BT->Left); //往左子树中查找 
	} else {
		return BT;//找到了就返回这个结点; 
	}
}

//(非递归)循环查找
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
