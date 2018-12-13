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

BinTree LineTree(); //链接树 
Position FindMax(BinTree BT); //递归方式查找最大值 
Position cycleFindMax(BinTree BT); //循环方式查找最大值 

int main(int argc, char const* argv[])
{
	BinTree BT;
	BinTree RT;
	RT=(BinTree)malloc(sizeof(struct TreeNode));
	printf("请创建树:");
	BT=LineTree();
	
	
	RT=FindMax(BT); //递归方式查找最大值
	printf("\n递归查找最大值:%d", RT->Data);
	
	printf("\n");
	RT=cycleFindMax(BT); //循环方式查找最大值 

	
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

//查找最大元素的递归函数
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
 
//查找最大元素的循环函数
Position cycleFindMax(BinTree BT)
{
	printf("循环查找最大值:"); 
	if (BT) {
		while (BT->Right) {
			BT=BT->Right;
		}
	}
	
	printf("%d\n", BT->Data);
	
	return BT;
} 
