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
void Compare(BinTree BT, BinTree T, int *P); //判断树是否相同
void FirTraversal(BinTree BT); //先序遍历
void MidTraversal(BinTree BT);  //中序遍历 
void LstTraversal(BinTree BT); //后序遍历 

int main(int argc, char const* argv[])
{
	BinTree BT;
    BinTree RT;
	int *Tmp=NULL; //标识符,判断两棵二叉搜索树是否相同 
	int tmp=1;
	Tmp=&tmp;
	
	printf("请创建树BT:");
	BT=LineTree();
	
	printf("请创建树RT:");
	RT=LineTree();
	
	printf("\nBT树先序遍历：");
	FirTraversal(BT);
	printf("\nRT树先序遍历：");
	FirTraversal(RT);
	
	//判别两棵树是否一致
	Compare(BT, RT, Tmp);
	printf("\n");
	if (tmp!=-1) {
		printf("\n两棵二叉搜索树相同！\n");
	} else {
		printf("\n两棵二叉搜索树不相同。\n");
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

//判断树是否相同
void Compare(BinTree BT, BinTree T, int *P)
{
	if (BT==NULL && T==NULL) {
		return;
	}
	
	if (BT!=NULL && T!=NULL) {
		if(BT->Data!=T->Data) {
			*P=-1;
			return;
		} 
	} 
	if (BT==NULL && T!=NULL || BT!=NULL && T==NULL) {
		*P=-1;	
		return;
	}
	
	//递归处理左右子树 
	Compare(BT->Left, T->Left, P);	
	Compare(BT->Right, T->Right, P);
	
	return;
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
