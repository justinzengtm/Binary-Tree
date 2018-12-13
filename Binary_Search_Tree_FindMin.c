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
Position FindMin(BinTree BT); //递归方式查找最小值 
Position cycleFindMin(BinTree BT); //循环方式查找最小值 

int main(int argc, char const* argv[])
{
	BinTree BT;
	BinTree RT;
	RT=(BinTree)malloc(sizeof(struct TreeNode));
	printf("请创建树:");
	BT=LineTree();
	
	RT=FindMin(BT); //递归方式查找最小值
	printf("\n递归查找最小值:%d", RT->Data);
	
	printf("\n\n");
	RT=cycleFindMin(BT); //循环方式查找最小值 

	
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

//查找最小元素的递归函数
Position FindMin(BinTree BT)
{

	if (!BT) {
		return NULL; //如果为空树就返回NULL; 
	} else if (!BT->Left) {
		return BT; //递归到最左后的结点肯定是最小值; 
	} else {
		return FindMin(BT->Left); //没到最左就一直递归,递归放最后; 
	}
	
	return; 
}  

//查找最小元素的循环函数
Position cycleFindMin(BinTree BT)
{
	printf("循环查找最小值:");
	if (BT) {
		while (BT->Left) {
			BT=BT->Left;
		}
	}
	
	printf("%d\n", BT->Data);
	
	return BT; 
}
