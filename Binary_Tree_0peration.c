/*
*二叉树输出叶结点、求总结点数、单孩子数，树高
*author:justinzeng
*date:2018/11/17 
*/

#include <stdio.h>
#include <stdlib.h>
#define ElementType int
#define MaxSize 100  //二叉树的"最大容量"

typedef struct TreeNode *BinTree;
typedef BinTree Position;
//二叉树的存储结构 
struct TreeNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
	int count; //总结点数
	int ChildCount; //单孩子结点数
};

//函数声明
BinTree CreateTree(); //初始化一棵树
BinTree LineTree(); //链接树  
void FirTraversal(BinTree BT); //先序遍历
void MidTraversal(BinTree BT);  //中序遍历 
void LstTraversal(BinTree BT); //后序遍历 
void FirstPrintLeaves(BinTree BT); //输出所有叶结点 
int AllNodeCount(BinTree BT, int count); //求所有结点数
int SingleFirTraversal(BinTree BT, int count); //求单孩子结点数 
int GetHight(BinTree BT); //求树的高度

int main(int argc, char const* argv[])
{
	ElementType Data=0; //树结点数据
	int TreeHight=0; //树高
	
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
	
	//获得树高 
	TreeHight=GetHight(BT); 
	printf("\n\n树的高度：%d", TreeHight);
	
	printf("\n\n所有叶结点：");
	FirstPrintLeaves(BT);
	
	BT->count=AllNodeCount(BT, BT->count); //求所有结点数 
	BT->ChildCount=SingleFirTraversal(BT, BT->ChildCount); //求单孩子结点数
	printf("\n\n总结点数为=%d\n", BT->count);
	printf("\n单孩子结点数为=%d\n", BT->ChildCount);
	
	return 0;
}

//初始化一棵树
BinTree CreateTree() 
{
	BinTree T;
	T=(BinTree)malloc(sizeof(struct TreeNode));
	T->ChildCount=0;
	T->count=0;
	
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

//输出所有叶结点 
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

//求所有结点数
int AllNodeCount(BinTree BT, int count) 
{
	if (BT) {
		count++;
		count=AllNodeCount(BT->Left, count);
		count=AllNodeCount(BT->Right, count); 
	}
	
	return count;
}

//求单孩子结点数 
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

//求树的高度 
int GetHight(BinTree BT)
{
	int LH, RH, max;
	LH=RH=max=0;
	if (BT) {
		LH=GetHight(BT->Left);
		RH=GetHight(BT->Right);
		max=(LH>RH)? LH:RH; //问号判断语句
		return (max+1);
	} else {
		return 0;
	}
}
