#include <stdio.h>
#include <stdlib.h>
#define ElementType int
#define MaxSize 100 //二叉搜索树的"最大容量"

typedef struct TreeNode *BinTree;
typedef BinTree Position;
//二叉搜索树的存储结构 
struct TreeNode {
	ElementType Data; 
	BinTree Left; //左子树 
	BinTree Right; //右子树 
};

//函数声明 
BinTree LineTree(); //链接树 
Position FindMin(BinTree BT); //递归查找最大值 
Position FindMax(BinTree BT); //递归查找最小值 
BinTree Delete (ElementType X, BinTree BT); //删除操作  
void FirTraversal(BinTree BT); //先序遍历
void MidTraversal(BinTree BT); //中序遍历 
void LstTraversal(BinTree BT); //后序遍历

int main(int argc, char const *argv[]) 
{
	ElementType number=0;
	BinTree BT; //二叉搜索树 
	BinTree RT;
	RT=(BinTree)malloc(sizeof(struct TreeNode));
	
	printf("请创建二叉搜索树:");
	BT=LineTree(); //创建树
	 
	printf("\n先序遍历序列:");
	FirTraversal(BT);
	printf("\n中序遍历：");
	MidTraversal(BT);
	printf("\n后序遍历：");
	LstTraversal(BT);
	
	printf("\n\n请输入要删除的元素:");
	scanf("%d", &number);
	//开始删除
	RT=Delete(number, BT);

	if (RT!=NULL) {
		printf("\n删除操作后的二叉搜索树先序遍历:");
		FirTraversal(BT);
		printf("\n中序遍历：");
		MidTraversal(BT);
		printf("\n后序遍历：");
		LstTraversal(BT);
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

//二叉搜索树的删除函数
BinTree Delete (ElementType X, BinTree BT)
{
	BinTree TP;
	
	if (!BT) {
		printf("树空");
		return NULL;
	} else if (X<BT->Data) {
		BT->Left=Delete(X, BT->Left); //左递归 
	} else if (X>BT->Data) {
		BT->Right=Delete(X, BT->Right); //右递归 
	} else {
		//找到要删除的结点后,判断该结点是否同时有左右子树 
		if (BT->Left&&BT->Right) {
			TP=FindMin(BT->Right);//往右子树中找最小元素的结点 
			//BT->Data是当前要删除的结点,所以把TP->Data替换上去 
			BT->Data=TP->Data;
			BT->Right=Delete(BT->Data,BT->Right);//删除结点的右子树中删除最小元素 
		} else {
			TP=BT;
			if (!BT->Left) {
				BT=BT->Right;
			} else if (!BT->Right) {
				BT=BT->Left;
			}
			free (TP);
		}
	}
	
	return BT;
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
